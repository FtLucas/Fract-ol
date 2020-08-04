/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:29:25 by luwargni          #+#    #+#             */
/*   Updated: 2019/08/25 19:20:36 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			init_mlx(t_data *data)
{
	int		bpp;
	int		endian;
	int		s_l;

	data->mlx.mlx_ptr = mlx_init();
	if (!(data->mlx.mlx_win = mlx_new_window(data->mlx.mlx_ptr,
		WIDTH, WIDTH, NAME)))
		return (MALLOC_FAILED);
	if (!(data->mlx.mlx_img_ptr = mlx_new_image(data->mlx.mlx_ptr,
		WIDTH, WIDTH)))
		return (MALLOC_FAILED);
	data->mlx.mlx_img = (int *)mlx_get_data_addr(data->mlx.mlx_img_ptr,
		&(bpp), &(s_l), &(endian));
	return (SUCCESS);
}

static int			parse(t_data *data, char *str)
{
	int		i;

	i = -1;
	init_fract(data);
	data->fract_is = 42;
	while (++i < NB_FRACT)
		if (ft_strcmp(str, data->fracts[i].name) == 0)
			data->fract_is = i;
	if (data->fract_is != 42)
	{
		data->fracts[data->fract_is].init(data);
		return (SUCCESS);
	}
	error_usage(data);
	return (PARSE_FAILED);
}

int					main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_putendl_fd("usage \"mandelbrot\" | \"julia\" | \"burningship\"", 2);
		return (0);
	}
	if (parse(&data, av[1]) != SUCCESS)
		return (0);
	if (init_mlx(&data) != SUCCESS)
	{
		ft_putendl_fd("erreur", 2);
		return (0);
	}
	mlx_hook(data.mlx.mlx_win, 6, 1L << 6, mouse_julia, &data);
	mlx_mouse_hook(data.mlx.mlx_win, mouse_hook, &data);
	mlx_hook(data.mlx.mlx_win, 17, 0, close_button, &data);
	mlx_hook(data.mlx.mlx_win, 3, 0, key_unhook, &data);
	mlx_hook(data.mlx.mlx_win, 2, 0, key_hook, &data);
	mlx_loop_hook(data.mlx.mlx_ptr, draw, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
