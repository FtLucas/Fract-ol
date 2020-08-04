/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:51:57 by luwargni          #+#    #+#             */
/*   Updated: 2019/08/12 17:49:54 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_point_burningship(t_data *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->it = -1;
	data->z_rx2 = data->z_r * data->z_r;
	data->z_ix2 = data->z_i * data->z_i;
	while (data->z_rx2 + data->z_ix2 < 4 && ++(data->it) < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_rx2 - data->z_ix2 + data->c_r;
		data->z_i = fabs(2 * data->z_i * data->tmp) + data->c_i;
		data->z_rx2 = data->z_r * data->z_r;
		data->z_ix2 = data->z_i * data->z_i;
	}
	if (data->it == data->it_max)
		put_pxl(data, data->x, data->y, BLACK);
	else
		put_pxl(data, data->x, data->y, (data->it * data->color));
}

void	set_point_julia(t_data *data)
{
	data->z_r = data->x / data->zoom + data->x1;
	data->z_i = data->y / data->zoom + data->y1;
	data->it = -1;
	while (data->z_r * data->z_r + data->z_i
			* data->z_i < 4 && ++(data->it) < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r -
			data->z_i * data->z_i - 0.8 + (data->c_r / WIDTH);
		data->z_i = 2 * data->z_i * data->tmp + data->c_i / WIDTH;
	}
	if (data->it == data->it_max)
		put_pxl(data, data->x, data->y, BLACK);
	else
		put_pxl(data, data->x, data->y, (data->it * data->color));
}

void	set_point_mandelbrot(t_data *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->it = -1;
	data->z_rx2 = data->z_r * data->z_r;
	data->z_ix2 = data->z_i * data->z_i;
	while (data->z_rx2 + data->z_ix2 < 4 && ++(data->it) < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_rx2 - data->z_ix2 + data->c_r;
		data->z_i = (2 * data->z_i * data->tmp) + data->c_i;
		data->z_rx2 = data->z_r * data->z_r;
		data->z_ix2 = data->z_i * data->z_i;
	}
	if (data->it == data->it_max)
		put_pxl(data, data->x, data->y, BLACK);
	else
		put_pxl(data, data->x, data->y, (data->color * data->it));
}

void	*draw_fract(void *tab)
{
	t_data	*data;
	int		tmp;

	data = (t_data *)tab;
	tmp = data->y - 1;
	data->x = -1;
	while (++(data->x) < WIDTH)
	{
		data->y = tmp;
		while (++(data->y) < data->y_max)
			data->fracts[data->fract_is].f(data);
	}
	return (tab);
}

int		pthread_fract(t_data *data, void *(f))
{
	t_data		tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_data));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_max = THREAD_WIDTH * (i + 1);
		if (pthread_create(&t[i], NULL, f, &tab[i]) != 0)
			return (ERROR_PTHREAD);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
	mlx_put_image_to_window(data->mlx.mlx_ptr,
							data->mlx.mlx_win, data->mlx.mlx_img_ptr, 0, 0);
	return (0);
}
