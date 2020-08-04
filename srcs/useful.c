/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:10:30 by luwargni          #+#    #+#             */
/*   Updated: 2019/08/25 19:35:54 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			close_button(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.mlx_img_ptr);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
	exit(0);
	return (0);
}

int			mouse_julia(int x, int y, t_data *data)
{
	if (data->fract_is == 1 && data->julia_mouse == 1)
	{
		data->c_r = x * 1 - 300;
		data->c_i = y * 1 - 300;
		draw(data);
	}
	return (0);
}

int			key_unhook(int key, t_data *data)
{
	data->keys[key] = 0;
	return (0);
}

void		put_pxl(t_data *data, int x, int y, int color)
{
	if (data->x < WIDTH && data->y < WIDTH)
	{
		color = mlx_get_color_value(data->mlx.mlx_ptr, color);
		data->mlx.mlx_img[y * WIDTH + x] = color;
	}
}

void		error_usage(t_data *data)
{
	int		i;

	ft_putendl_fd("\n=================	 \
	=================\n\" \
						\"\n\" 						\"\n\" \
	The given parameter is not valid.	\"", 2);
	ft_putstr_fd("\"	Use :					\"\n", 2);
	i = 0;
	while (i < NB_FRACT)
	{
		ft_putstr_fd("\"	./fractol \"", 2);
		ft_putstr_fd(data->fracts[i].name, 2);
		ft_putendl_fd("			\"", 2);
		i++;
	}
	ft_putstr_fd("\"						\"\n=================	\
	=================\n", 2);
}
