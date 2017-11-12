#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"

# define WINDOW_SIZE_H 1000
# define WINDOW_SIZE_W 2000


# define DEC_T 100
# define DEC_L 100
# define SIZE_W 20
# define SIZE_H 20
/*
**	Move pixel
*/
# define MOVE_UP -100
# define MOVE_DOWN 100
# define MOVE_LEFT -100
# define MOVE_RIGHT 100

# define MOVE_ZOOM_IN 1.1
# define MOVE_ZOOM_OUT 0.9

# define MOVE_ROT_X_U -M_PI / 64
# define MOVE_ROT_X_D M_PI / 64
# define MOVE_ROT_Y_U -M_PI / 64
# define MOVE_ROT_Y_D M_PI / 64
# define MOVE_ROT_Z_U -M_PI / 64
# define MOVE_ROT_Z_D M_PI / 64

/*
**	Key code
*/
# define KEY_ESC 53

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define KEY_ZOOM_IN 69
# define KEY_ZOOM_OUT 78

# define KEY_ROT_X_U 86
# define KEY_ROT_X_D 83
# define KEY_ROT_Y_U 87
# define KEY_ROT_Y_D 84
# define KEY_ROT_Z_U 88
# define KEY_ROT_Z_D 85

typedef struct	s_point {
	double	x;
	double	y;
	double	val;
	double	s;
	int		z_color;
}				t_point;

typedef struct	s_line {
	t_point	**points;
	int		len;
}				t_line;

typedef struct	s_map {
	t_line	**lines;
	int		len;
}				t_map;

typedef struct	s_env {
	void	*mlx;
	void	*win;
	t_map	*map;
	t_point	center;
	void	*img;
	char	*pixel_img;
	int		bpp;
	int		s_line;
	int		ed;
}				t_env;

typedef struct	s_matrice {
	double a1;
	double a2;
	double a3;
	double a4;
	double b1;
	double b2;
	double b3;
	double b4;
	double c1;
	double c2;
	double c3;
	double c4;
	double d1;
	double d2;
	double d3;
	double d4;
}				t_matrice;

// draw.c
void			draw_windows(char *title, int weight, int height, t_env *env);
int		point_out_window(t_point *point);
//static	void	draw_line(t_point p1, t_point p2, t_env *env);
void	draw_map(t_env *e);
void	get_center(t_env *env);
void	draw_reload(t_env *e);

/*
**	Calcul of matrice
**	\file fdf_cal_matrice.c
*/

void			ft_cal_rotation(t_env *e, double rot, char axe);
void			ft_cal_translat(t_env *e, double x, double y, double val);
void			ft_cal_scale(t_env *e, double s);

/*
**	Mtarice init
**	\file fdf_matrice.c
*/
t_matrice		*ft_matrice_rotation_x(double beta);
t_matrice		*ft_matrice_rotation_y(double beta);
t_matrice		*ft_matrice_rotation_z(double beta);
t_matrice		*ft_matrice_translation(double tx, double ty, double tz);
t_matrice		*ft_matrice_scale(double s);

/*
**	Hook
**	\file fdf_hook.c
*/
int				key_hook(int keycode, t_env *e);


#endif