

#include "fractol.h"

int	keyboard(int key, t_fractol *fract)
{
	if (key == 53)
	{
		mlx_destroy_window(fract->mlx_p, fract->win_p);
		exit(1);
	}
	if (key == 38)
		fract->j_mouse_ctrl = (fract->j_mouse_ctrl == 1) ? 0 : 1;
	else if (key == 18)
		fract->color_func = calculate_color;
	else if (key == 19)
		fract->color_func = calculate_color_2;
	else if (key == 20)
		fract->color_func = calculate_color_3;
	else if (key == 123 || key == 0)
		move_x(fract, (fract->end_re - fract->begin_re) * 0.05);
	else if (key == 126 || key == 13)
		move_y(fract, (fract->end_im - fract->begin_im) * 0.05);
	else if (key == 124 || key == 2)
		move_x(fract, -(fract->end_re - fract->begin_re) * 0.05);
	else if (key == 125 || key == 1)
		move_y(fract, -(fract->end_im - fract->begin_im) * 0.05);
	else if (key == 49)
		fract->fract_init(fract);
	redraw_fractal(fract);
	return (0);
}

int	mouse(int key, int x, int y, t_fractol *fract)
{
	fract->mouse_x = x;
	fract->mouse_y = y;
	if (key == 5 || key == 1)
	{
		zoom(fract, 0.95);
		redraw_fractal(fract);
	}
	else if (key == 4 || key == 2)
	{
		zoom(fract, 1.05);
		redraw_fractal(fract);
	}
	else if (key == 3)
	{
		fract->fract_init(fract);
		redraw_fractal(fract);
	}
	return (0);
}

int	julia_mouse(int x, int y, t_fractol *fract)
{
	if (fract->j_mouse_ctrl == 1)
	{
		fract->julia_re = fract->begin_re +
			(fract->end_re - fract->begin_re) * (double)x / (double)fract->w;
		fract->julia_im = fract->begin_im +
			(fract->end_im - fract->begin_im) * (double)y / (double)fract->h;
		redraw_fractal(fract);
	}
	return (0);
}
