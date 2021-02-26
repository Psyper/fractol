

#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H

# include <stdio.h>
# include "minilibx_macos/mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

typedef struct	s_fractol
{
	int				trd_total;
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
	int				w;
	int				h;
	int				mouse_x;
	int				mouse_y;
	double			begin_re;
	double			begin_im;
	double			end_re;
	double			end_im;
	double			dre;
	double			dim;
	int				iter;
	int				max_iter;
	double			julia_re;
	double			julia_im;
	int				j_mouse_ctrl;
	int				(*color_func)(struct s_fractol *f, int x, int y);
	void			(*fract_func)(struct s_fractol *f, int x, int y);
	void			(*fract_init)(struct s_fractol *f);
	int				*img_begin;
}				t_fractol;

typedef struct	s_f_trd
{
	int			id;
	t_fractol	*fract;
}				t_fract_id;

int				keyboard(int key, t_fractol *fract);
int				mouse(int key, int x, int y, t_fractol *fract);
int				julia_mouse(int x, int y, t_fractol *fract);
void			zoom(t_fractol *fract, double zoom);
void			move_x(t_fractol *fract, double re);
void			move_y(t_fractol *fract, double im);
void			draw_fractal(t_fractol *fract, int id);
void			draw_text(t_fractol *fract);
void			redraw_fractal(t_fractol *fract);
void			init_madnelbrot(t_fractol *fract);
void			init_julia(t_fractol *fract);
void			init_ship(t_fractol *fract);
void			madnelbrot(t_fractol *fract, int x, int y);
void			julia(t_fractol *fract, int x, int y);
void			ship(t_fractol *fract, int x, int y);
int				calculate_color(t_fractol *fract, int x, int y);
int				calculate_color_2(t_fractol *fract, int x, int y);
int				calculate_color_3(t_fractol *fract, int x, int y);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_putstr(char *str);
void 			threads(t_fractol *fract);
void			*trd_draw(void *trd_f);

#endif
