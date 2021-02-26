

#include "fractol.h"

void	move_x(t_fractol *fract, double re)
{
	fract->begin_re -= re;
	fract->end_re -= re;
}

void	move_y(t_fractol *fract, double im)
{
	fract->begin_im -= im;
	fract->end_im -= im;
}

void	zoom(t_fractol *fract, double zoom)
{
	double mouse_re;
	double mouse_im;

	mouse_re = (double)fract->mouse_x /
			(fract->w / (fract->end_re - fract->begin_re)) + fract->begin_re;
	mouse_im = (double)fract->mouse_y /
			(fract->h / (fract->end_im - fract->begin_im)) + fract->begin_im;
	fract->begin_re = mouse_re + ((fract->begin_re - mouse_re) * zoom);
	fract->begin_im = mouse_im + ((fract->begin_im - mouse_im) * zoom);
	fract->end_re = mouse_re + ((fract->end_re - mouse_re) * zoom);
	fract->end_im = mouse_im + ((fract->end_im - mouse_im) * zoom);
}
