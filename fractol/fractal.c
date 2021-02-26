

#include "fractol.h"

void	madnelbrot(t_fractol *fract, int x, int y)
{
	double dx;
	double dy;
	double x_temp;

	fract->iter = 0;
	dx = 0.0f;
	dy = 0.0f;
	fract->dre = fract->begin_re +
			(fract->end_re - fract->begin_re) * (double)x / (double)fract->w;
	fract->dim = fract->begin_im +
			(fract->end_im - fract->begin_im) * (double)y / (double)fract->h;
	while (fract->iter < fract->max_iter && (dx * dx + dy * dy) <= 4.0f)
	{
		x_temp = dx * dx - dy * dy;
		dy = 2.0f * dx * dy + fract->dim;
		dx = x_temp + fract->dre;
		fract->iter++;
	}
}

void	julia(t_fractol *fract, int x, int y)
{
	double dx;
	double dy;
	double x_temp;

	fract->iter = 0;
	fract->dre = fract->begin_re +
			(fract->end_re - fract->begin_re) * (double)x / (double)fract->w;
	fract->dim = fract->begin_im +
			(fract->end_im - fract->begin_im) * (double)y / (double)fract->h;
	dx = fract->dre;
	dy = fract->dim;
	while (fract->iter < fract->max_iter && (dx * dx + dy * dy) <= 16.0f)
	{
		x_temp = (dx * dx - dy * dy);
		dy = 2.0f * dx * dy - fract->julia_im;
		dx = x_temp - fract->julia_re;
		fract->iter++;
	}
}

void	ship(t_fractol *fract, int x, int y)
{
	double dx;
	double dy;
	double x_temp;

	fract->iter = 0;
	dx = 0.0f;
	dy = 0.0f;
	fract->dre = fract->begin_re +
			(fract->end_re - fract->begin_re) * (double)x / (double)fract->w;
	fract->dim = fract->begin_im +
			(fract->end_im - fract->begin_im) * (double)y / (double)fract->h;
	while (fract->iter < fract->max_iter && (dx * dx + dy * dy) <= 4.0f)
	{
		x_temp = (dx * dx - dy * dy);
		dy = fabs(2.0f * dx * dy) + fract->dim;
		dx = x_temp + fract->dre;
		fract->iter++;
	}
}
