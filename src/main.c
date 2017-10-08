
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/libft.h"
#include "fdf.h"
#include "mlx.h"

int	print_error(char *msg)
{
	if(msg)
	{
		ft_putstr("Error: ");
		ft_putendl(msg);
	}
	else
		ft_putendl("Error: ");
	return(1);
}

int		main(int argc, char *argv[])
{
	
	//int 	fd;
	void	*mlx;
	void	*win;
	int 	x;
	int 	y;

	y = 50;
	argv = NULL;
	argc = 0;
	/*if(argc !=2)
	{
		print_error("Usage: ./fdf [map.fdf]");
		return(0);
	}*/

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	while(y<150)
	{
		x = 50;
		while(x<150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);
	mlx_loop(mlx);
	
	return(1);
}