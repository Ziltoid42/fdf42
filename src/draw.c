#include "fdf.h"

void			draw_windows(char *title, int weight, int height, t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, weight, height, title);
}

int		point_out_window(t_point *point)
{
	if (!(point->x > WINDOW_SIZE_W + 100 || point->x <= 0 ||
		point->y > WINDOW_SIZE_H + 100 || point->y <= 0))
		return (1);
	else
		return (0);
}

int		get_color(t_point *point1, t_point *point2)
{
	int color;
	int z;

	if (point2->z_color > point1->z_color)
		z = point2->z_color;
	else
		z = point1->z_color;
	if (z < 0)
		color = 0x0D6386;
	else if (z >= 0 && z < 10)
		color = 0x32A862;
	else if (z >= 10 && z < 20)
		color = 0x8FC89A;
	else if (z >= 20 && z < 50)
		color = 0xFAECBE;
	else if (z >= 50 && z < 70)
		color = 0x996E56;
	else if (z >= 70)
		color = 0xE0D3CC;
	else
		color = 0;
	return (color);
}

static	void	draw_line_params(t_point *point1, t_point *point2, double *tab)
{
	tab[0] = fabs(point1->x - point2->x);
	tab[1] = point1->x < point2->x ? 1 : -1;
	tab[2] = fabs(point1->y - point2->y);
	tab[3] = point1->y < point2->y ? 1 : -1;
	tab[4] = (tab[0] > tab[2] ? tab[0] : -tab[2]) * 0.5;
}

static void		draw_point(t_point *point, t_env *env, int color)
{
	int i;
	i = ((int)point->x * 4) + ((int)point->y * env->s_line);
	env->pixel_img[i] = color;
	env->pixel_img[++i] = color >> 8;
	env->pixel_img[++i] = color >> 16;
}

static	void	draw_line(t_point p1, t_point p2, t_env *env)
{
	double	tab[6];
	int		state;
	if (!point_out_window(&p1) && point_out_window(&p2))
		return ;
	draw_line_params(&p1, &p2, tab), state = 1;
	while (state == 1 && !((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y))
	{
		if (point_out_window(&p1) == 1)
			draw_point(&p1, env, get_color(&p1, &p2));
		tab[5] = tab[4];
		state = 0;
		if (tab[5] > -tab[0] && (int)p1.x != (int)p2.x)
		{
			
			tab[4] -= tab[2];
			p1.x += tab[1];
			state = 1;
		}
		if (tab[5] < tab[2] && (int)p1.y != (int)p2.y)
		{
			
			tab[4] += tab[0];
			p1.y += tab[3];
			state = 1;
		}
	}
	
}

void	get_center(t_env *env)
{
	t_point 	center;
	int 		xl;
	int 		yl;

	center = env->center;
	yl = env->map->len;
	xl = env->map->lines[yl - 1]->len;
	center.x = (env->map->lines[yl - 1]->points[xl - 1]->x +
			env->map->lines[0]->points[0]->x) / 2;
	center.y = (env->map->lines[yl - 1]->points[xl - 1]->y +
			env->map->lines[0]->points[0]->y) / 2;
	env->center = center;
}

void	draw_reload(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WINDOW_SIZE_W + 100, WINDOW_SIZE_H + 100);
	e->pixel_img = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->ed));
	draw_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, -50, -50);
	mlx_destroy_image(e->mlx, e->img);
}

void	draw_map(t_env *env)
{
	int 	x;
	int 	y;
	t_point p;

	y = 0;
	while(y < env->map->len)
	{
		x = 0;
		while(x < (env->map->lines[y]->len))
		{
			
			p = (*env->map->lines[y]->points[x]);
			if (env->map->lines[y]->points[x + 1])
				draw_line(p, (*env->map->lines[y]->points[x + 1]), env);
			if (env->map->lines[y + 1])
			{
				if (env->map->lines[y + 1]->points[x] &&
					x <= env->map->lines[y + 1]->len)
						draw_line(p, (*env->map->lines[y + 1]->points[x]), env);
			}
			x++;
		}
		y++;
	}
}