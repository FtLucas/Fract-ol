/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:59:20 by luwargni          #+#    #+#             */
/*   Updated: 2019/07/28 00:46:13 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_mandelbrot(t_data *data)
{
	data->zoom = 220;
	data->x1 = -2.5;
	data->y1 = -1.8;
	data->it_max = 42;
	data->color = COLOR_1;
}

static void		init_julia(t_data *data)
{
	data->zoom = 200;
	data->x1 = -2.0;
	data->y1 = -2.0;
	data->it_max = 42;
	data->julia_mouse = 1;
	data->c_r = 0.0;
	data->c_i = 150.0;
	data->color = COLOR_1;
}

static void		init_burningship(t_data *data)
{
	data->zoom = 190;
	data->x1 = -2.4;
	data->y1 = -2.4;
	data->it_max = 42;
	data->color = COLOR_1;
}

void			init_fract(t_data *data)
{
	ft_strcpy(data->fracts[0].name, "mandelbrot");
	ft_strcpy(data->fracts[1].name, "julia");
	ft_strcpy(data->fracts[2].name, "burningship");
	data->fracts[0].f = set_point_mandelbrot;
	data->fracts[1].f = set_point_julia;
	data->fracts[2].f = set_point_burningship;
	data->fracts[0].init = init_mandelbrot;
	data->fracts[1].init = init_julia;
	data->fracts[2].init = init_burningship;
}
