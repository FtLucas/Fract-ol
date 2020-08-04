/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:10:16 by luwargni          #+#    #+#             */
/*   Updated: 2019/08/04 23:24:09 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_hook_2(int key, t_data *data)
{
	if (key == ESC)
	{
		mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.mlx_img_ptr);
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
		exit(0);
	}
	else if (key == 24)
	{
		data->fract_is++;
		if (data->fract_is >= NB_FRACT)
			data->fract_is = 0;
		data->fracts[data->fract_is].init(data);
	}
	else if (key == 27)
	{
		data->fract_is--;
		if (data->fract_is < 0)
			data->fract_is = NB_FRACT - 1;
		data->fracts[data->fract_is].init(data);
	}
	return (0);
}

int			key_hook(int key, t_data *data)
{
	data->keys[key] = 1;
	key_hook_2(key, data);
	if (key == SPACE)
		data->fracts[data->fract_is].init(data);
	else if (key == FRACT_COLOR_1)
		data->color = COLOR_1;
	if (key == FRACT_COLOR_2)
		data->color = COLOR_2;
	else if (key == FRACT_COLOR_3)
		data->color = COLOR_3;
	else if (key == FRACT_COLOR_4)
		data->color = COLOR_4;
	else if (key == FRACT_COLOR_5)
		data->color = COLOR_5;
	else if (key == PAUSE)
		data->julia_mouse = !data->julia_mouse;
	else if (key == AFF_ITERATION)
		data->view_text = !data->view_text;
	else if (key == AFF_HUD)
		data->view_hud = !data->view_hud;
	draw(data);
	return (0);
}

static void	ft_dezoom(int x, int y, t_data *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
	data->it_max--;
	data->zoom /= 1.3;
}

static void	ft_zoom(int x, int y, t_data *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
	if (!(data->it_max >= 350))
		data->it_max++;
	data->zoom *= 1.3;
}

int			mouse_hook(int mouse, int x, int y, t_data *data)
{
	if (mouse == 4 || mouse == 1)
		ft_zoom(x, y, data);
	else if (mouse == 5 || mouse == 2)
		ft_dezoom(x, y, data);
	draw(data);
	return (0);
}
