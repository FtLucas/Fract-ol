/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:31:13 by luwargni          #+#    #+#             */
/*   Updated: 2019/08/08 20:12:47 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		put_hud(t_data *data)
{
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, 10, 10, WHITE,
		"Press arrow up/down or use click mouse = zoom/dezoom");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, 10, 30, WHITE,
		"Press 1,2,3,4,5 for select fractal color");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, 10, 50, WHITE,
		"Press a, w, s, d, for move the fractal");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, 10, 70, WHITE,
		"Press 'h' for HUD Close/Open");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, 10, 90, WHITE,
		"Press 'i' for nb iteration");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, 10, 110, WHITE,
		"Press +/- for interation++");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, 10, 130, WHITE,
		"Press 'p' for pause julia");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, 10, 150, WHITE,
		"Press 'c' for color++");
}

static void		put_text(t_data *data)
{
	char	*text;
	char	*nb;

	nb = ft_itoa(data->it_max);
	if (!(data->it_max >= 350))
	{
		text = ft_strjoin("iteration : ", nb);
		mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, 645, 10, WHITE,
			text);
	}
	else
	{
		text = ft_strjoin("iteration MAX : MAX = ", nb);
		mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, 545, 10, WHITE,
			text);
	}
	ft_strdel(&text);
	ft_strdel(&nb);
}

static void		key_zoom(t_data *data)
{
	int		div;

	div = (WIDTH / 2);
	if (data->keys[126])
	{
		data->x1 = (div / data->zoom + data->x1) - (div / (data->zoom * 1.03));
		data->y1 = (div / data->zoom + data->y1) - (div / (data->zoom * 1.03));
		data->zoom *= 1.03;
		if (!(data->it_max >= 350))
			data->it_max += 1;
	}
	if (data->keys[125])
	{
		data->x1 = (div / data->zoom + data->x1) - (div / (data->zoom / 1.03));
		data->y1 = (div / data->zoom + data->y1) - (div / (data->zoom / 1.03));
		data->zoom /= 1.03;
		data->it_max -= 1;
	}
}

static void		key_put(t_data *data)
{
	if (data->keys[126] || data->keys[125])
		key_zoom(data);
	if (data->keys[8])
		data->color = data->color * 9;
	if (data->keys[0])
		data->x1 -= 10 / data->zoom;
	if (data->keys[2])
		data->x1 += 10 / data->zoom;
	if (data->keys[1])
		data->y1 += 10 / data->zoom;
	if (data->keys[13])
		data->y1 -= 10 / data->zoom;
	if (data->keys[69] && !(data->it_max >= 350))
		data->it_max += 1;
	if (data->keys[78])
	{
		data->it_max -= 1;
		if (data->it_max < 0)
			data->it_max = 0;
	}
	if (data->it_max < 0)
		data->it_max = 0;
}

int				draw(t_data *data)
{
	key_put(data);
	pthread_fract(data, (void *)draw_fract);
	if (data->view_hud)
		put_hud(data);
	if (data->view_text)
		put_text(data);
	return (0);
}
