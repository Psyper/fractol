

#include "fractol.h"

void 	threads(t_fractol *fract)
{
	int			i;
	int			trd_count;
	pthread_t	trd[4];
	t_fract_id	data_id[4];

	i = 0;
	trd_count = 4;

	fract->trd_total = trd_count;
	while (i < trd_count)
	{
		data_id[i].fract = fract;
		data_id[i].id = i + 1;
		if (pthread_create(&trd[i],NULL,trd_draw, &data_id[i]))
			ft_putstr("error trd create\n");
		i++;
	}
	i = 0;
	while (i < trd_count)
	{
		if (pthread_join(trd[i], NULL))
			ft_putstr("error trd join\n");
		i++;
	}
	mlx_put_image_to_window(fract->mlx_p, fract->win_p, fract->img_p, 0, 0);

}

void	*trd_draw(void *trd_f)
{
	t_fract_id *data;

	data = (t_fract_id *)trd_f;
	draw_fractal(data->fract, data->id);
	return (NULL);
}