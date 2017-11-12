#include "fdf.h"

void	print_error(char *msg)
{
	if(msg)
	{
		ft_putstr_fd("Error: ", 1);
		ft_putendl_fd(msg, 1);
	}
	else
		ft_putendl_fd("Error: ", 1);
	exit(-1);
}

int	read_lines(int fd)
{
	int 	nb_lines;
	char 	buff;

	nb_lines = 0;
	while(read(fd, &buff, 1))
	{
		if (buff == '\n')
			nb_lines++;
	}
	close(fd);
	return(nb_lines);

}

int parse_point(char *points_array)
{
	int i;
	int negative;
	int value;

	i = 0;
	negative = 0;
	value = 0;

	if(points_array[i] == '-')
	{

		negative = 1;
		i++;
	}
	while((points_array[i] >= '0') && (points_array[i] <= '9'))
	{
		value = (value * 10) + points_array[i++] - '0';
	}
	if(negative == 1)
		return(value * -1);
	else
		return(value);

}

int	parse_line(char *line, int nb_lines, t_point ***points)
{
	int i;
	char	**points_array;
	t_point *point;

	i = 0;
	points_array = ft_strsplit(line, ' ');
	while (points_array[i] != 0)
			i++;
		if (!((*points) = (t_point**)malloc(sizeof(t_point) * i)))
			print_error("points malloc error");
	i = 0;
	while(points_array[i] != 0)
	{
		point = (t_point*)malloc(sizeof(t_point));
		point->x = i * SIZE_W;
		point->y = nb_lines * SIZE_H;
		point->val = parse_point(points_array[i]);
		point->s = 1;
		point->z_color = point->val;
		(*points)[i] = point;
		i++;
	}
	return(i);

}

t_map	*parse_map(int fd, char **argv)
{
	t_map	*map;
	t_line	*line_map;
	t_point	**points;
	char	*line;
	int		nb_lines;

	nb_lines = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))) ||
		!(map->lines = (t_line**)malloc(sizeof(t_line) * read_lines(fd))))
		print_error("Map malloc error");
	map->len = 0;
	if ((fd = open(argv[1], O_RDONLY)) > 0)
	{
		while((get_next_line(fd, &line)) > 0)
		{
			
			if (!(line_map = (t_line*)malloc(sizeof(t_line))))
					print_error("line malloc error");
				line_map->len = parse_line(line, nb_lines, &points);
				line_map->points = points;
				map->lines[nb_lines] = line_map;
				nb_lines++;
		}
		map->len = nb_lines;
		
	}
	return(map);
}

void	print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < map->len)
	{
		while(j < map->lines[i]->len)
		{
			ft_putnbr(map->lines[i]->points[j]->val);
			ft_putchar(' ');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
		
}



void	adapt_map(t_env *e)
{
	int		w;
	int		h;
	double	s;
	w = (WINDOW_SIZE_W + 100) / 2;
	h = (WINDOW_SIZE_H + 100) / 2;
	e->center.x == 0 ? e->center.x = 10 : e->center.x;
	s = (w - 600) / (e->center.x);
	ft_cal_translat(e, -e->center.x + w, -e->center.y + h, 0);
	ft_cal_scale(e, s);
}

int		expose_hook(t_env *e)
{
	draw_reload(e);
	return (0);
}

int		main(int argc, char **argv)
{
	
	int 	fd;
	int 	i;
	t_map	*map;
	t_env 	*env;

	i = 0;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
			print_error("An error occured during env malloc");

	fd = open(argv[1], O_RDONLY);
	if(argc !=2)
	{
		print_error("Usage: ./fillit [map.map]");
		return(0);
	}
	if(fd == -1)
		print_error("An error occured during opening of the file");

	map = parse_map(fd, argv);
	env->map = map;
	get_center(env);
	
	draw_windows("42 FDF", WINDOW_SIZE_W, WINDOW_SIZE_H, env);
	adapt_map(env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_hook(env->win, 2, 3, key_hook, env);
	mlx_loop(env->mlx);
	
	return(1);
}