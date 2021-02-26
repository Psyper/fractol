

#include "fractol.h"

void	init_madnelbrot(t_fractol *fract)
{
	fract->max_iter = 300;
	fract->begin_re = -1.8f;
	fract->begin_im = -1.8f;
	fract->end_re = 1.8f;
	fract->end_im = 1.8f;
}

void	init_julia(t_fractol *fract)
{
	fract->max_iter = 300;
	fract->begin_re = -1.8f;
	fract->begin_im = -1.8f;
	fract->end_re = 1.8f;
	fract->end_im = 1.8f;
	fract->julia_re = 0.0f;
	fract->julia_im = 0.8f;
	fract->j_mouse_ctrl = 1;
}

void	init_ship(t_fractol *fract)
{
	fract->max_iter = 300;
	fract->begin_re = -2.0f;
	fract->begin_im = -0.5f;
	fract->end_re = -1.0f;
	fract->end_im = 0.5f;
}
