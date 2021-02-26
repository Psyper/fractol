

#include "fractol.h"

void	redraw_fractal(t_fractol *fract)
{
	mlx_clear_window(fract->mlx_p, fract->win_p);
	threads(fract);
	draw_text(fract);
}

void	assign_values(t_fractol *fract)
{
	int bpp;
	int endian;
	int w;

	bpp = 24;
	endian = 0;
	w = 800;
	fract->w = w;
	fract->h = 800;
	fract->max_iter = 0;
	fract->mlx_p = mlx_init();
	fract->win_p = mlx_new_window(fract->mlx_p, fract->w, fract->h, "Fractal");
	fract->img_p = mlx_new_image(fract->mlx_p, fract->w, fract->h);
	fract->img_begin =
			(int *)mlx_get_data_addr(fract->img_p, &bpp, &w, &endian);
	fract->j_mouse_ctrl = 0;
	fract->color_func = calculate_color;
}

int		select_fractal(const char *name, t_fractol *fract)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
	{
		fract->fract_func = madnelbrot;
		fract->fract_init = init_madnelbrot;
		return (1);
	}
	else if (ft_strcmp(name, "julia") == 0)
	{
		fract->fract_func = julia;
		fract->fract_init = init_julia;
		return (1);
	}
	else if (ft_strcmp(name, "b_ship") == 0)
	{
		fract->fract_func = ship;
		fract->fract_init = init_ship;
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_fractol fract;

	if (argc != 2)
	{
		ft_putstr("error: a single argument required\n");
		return (0);
	}
	else if (select_fractal(argv[1], &fract) == 0)
	{
		ft_putstr("error: possible arguments are: mandelbrot, julia, b_ship\n");
		return (0);
	}
	assign_values(&fract);
	select_fractal(argv[1], &fract);
	threads(&fract);
	draw_text(&fract);
	mlx_mouse_hook(fract.win_p, mouse, &fract);
	mlx_hook(fract.win_p, 2, 1, keyboard, &fract);
	mlx_hook(fract.win_p, 6, (1L << 6), julia_mouse, &fract);
	mlx_loop(fract.mlx_p);
	return (0);

}
