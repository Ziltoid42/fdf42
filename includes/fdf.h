#ifndef FDF_H
# define FDF_H

typedef struct	s_point {
	double	x;
	double	y;
	double	val;
	//double	s;
	//int		z_color;
}				t_point;

typedef struct	s_line {
	t_point	**points;
	int		len;
}				t_line;

typedef struct	s_map {
	t_line	**lines;
	int		len;
}				t_map;

#endif