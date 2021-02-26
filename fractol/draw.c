

#include "fractol.h"

int		calculate_color(t_fractol *fract, int x, int y)
{
	int argb;
	int r;
	int g;
	int b;

	fract->fract_func(fract, x, y);
	r = (fract->iter * 3) % 255;
	b = (fract->iter * 7) % 255;
	g = (fract->iter * 4) % 255;
	argb = (r << 16) | (g << 8) | b;
	return (argb);
}

int		calculate_color_2(t_fractol *fract, int x, int y)
{
	int argb;
	int r;
	int g;
	int b;

	fract->fract_func(fract, x, y);
	r = (int)(8 * fract->iter) % 255;
	g = (int)(2 * fract->iter) % 4;
	b = (int)(5 * fract->iter) % 70;
	argb = (r << 16) | (g << 8) | b;
	return (argb);
}

int		calculate_color_3(t_fractol *fract, int x, int y)
{
	int		argb;
	int		r;
	int		g;
	int		b;
	double	proc;

	fract->fract_func(fract, x, y);
	proc = (double)fract->iter / (double)fract->max_iter;
	r = (int)(9 * (1 - proc) * 255);
	g = (int)(15 * (1 - proc) * 255);
	b = (int)(8.5 * (1 - proc) * 255);
	argb = (r << 16) | (g << 8) | b;
	return (argb);
}

void	draw_fractal(t_fractol *fract, int id)
{
	int x;
	int y;

	x = fract->w * (id - 1) / fract->trd_total;
	y = 0;
	if (fract->max_iter == 0)
		fract->fract_init(fract);
	while (y < fract->h)
	{
		while (x < fract->w * id / fract->trd_total)
		{
			fract->img_begin[y * fract->w + x] = fract->color_func(fract, x, y);
			x++;
		}
		x = fract->w * (id - 1) / fract->trd_total;
		y++;
	}
}

void	draw_text(t_fractol *fract)
{
	void	*mlx;
	void	*win;
	int		y;

	mlx = fract->mlx_p;
	win = fract->win_p;
	y = 10;
	mlx_string_put(mlx, win, 5, y += 15, 0xADD8E6, "Controls:");
	mlx_string_put(mlx, win, 5, y += 15, 0xADD8E6, "Reset: space or mmb");
	mlx_string_put(mlx, win, 5, y += 15, 0xADD8E6, "Move: Arrows/wasd");
	mlx_string_put(mlx, win, 5, y += 15,
				0xADD8E6, "Zoom: mouse wheel and buttons");
	mlx_string_put(mlx, win, 5, y += 15, 0xADD8E6, "Change colors: 1, 2, 3");
	if (fract->fract_init == init_julia)
		mlx_string_put(mlx, win, 5, y + 15, 0xADD8E6, "Julia mouse control: j");
}
