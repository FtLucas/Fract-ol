/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:31:43 by luwargni          #+#    #+#             */
/*   Updated: 2019/08/25 19:28:29 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "pthread.h"
# include <stdlib.h>
# include "math.h"
# include "mlx.h"

/*
** Values
*/
# define NAME				"FRACTOL"
# define WIDTH				800
# define NB_FRACT			3
# define NB_COLORS			5
# define THREAD_WIDTH		7
# define THREAD_NUMBER		120

/*
** Keys
*/
# define AFF_ITERATION		34
# define AFF_HUD			4
# define ZOOM_P				13
# define ZOOM_M				1
# define ITE_P				69
# define ITE_M				78
# define SPACE				49
# define PAUSE				35
# define ESC				53
# define FRACT_COLOR_1		18
# define FRACT_COLOR_2		19
# define FRACT_COLOR_3		20
# define FRACT_COLOR_4		21
# define FRACT_COLOR_5		23

/*
** Returns
*/
# define SUCCESS			10
# define FAILURE			-1
# define UNKNOWN_KEY		-2
# define PARSE_FAILED		-3
# define ERROR_PTHREAD		-4
# define MALLOC_FAILED		-5

/*
** Colors
*/
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define COLOR_1		0x0a0001
# define COLOR_2		0x050505
# define COLOR_3		2050
# define COLOR_4		2550000
# define COLOR_5		4100

/*
** Structures
*/
typedef struct		s_init
{
	char			name[30];
	void			(*f)();
	void			(*init)();
}					t_init;

typedef struct		s_mlx
{
	void			*mlx_img_ptr;
	int				*mlx_img;
	void			*mlx_ptr;
	void			*mlx_win;
}					t_mlx;

typedef struct		s_data
{
	int				fract_is;
	int				color;
	int				julia_mouse;
	int				it;
	int				it_max;
	int				view_text;
	int				view_hud;
	int				x;
	int				y;
	int				y_max;
	double			zoom;
	double			x1;
	double			y1;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			z_rx2;
	double			z_ix2;
	double			tmp;
	char			keys[300];
	t_init			fracts[NB_FRACT];
	t_mlx			mlx;
}					t_data;

/*
** Fonctions
*/

void				init_fract(t_data *data);
/*
** static void		init_mandelbrot(t_data *data);
** static void		init_julia(t_data *data);
** static void		init_burningship(t_data *data);
*/

void				error_usage(t_data *data);
int					draw(t_data *data);
/*
** static void		key_put(t_data *data);
** int				pthread_fract(t_data *data, void *(f));
** static void		put_hud(t_data *data);
** static void		put_text(t_data *data);
*/

int					pthread_fract(t_data *data, void *(f));
/*
** void				*draw_fract(void *tab);
*/

void				*draw_fract(void *tab);
/*
** void				set_point_burningship(t_data *data);
** void				set_point_mandelbrot(t_data *data);
** void				set_point_julia(t_data *data);
*/
void				set_point_burningship(t_data *data);
void				set_point_mandelbrot(t_data *data);
void				set_point_julia(t_data *data);
/*
** void				put_pxl(t_data *data, int x, int y, int color);
*/
void				put_pxl(t_data *data, int x, int y, int color);
int					mouse_julia(int x, int y, t_data *data);
int					mouse_hook(int mouse, int x, int y, t_data *data);
int					close_button(t_data *data);
int					key_unhook(int key, t_data *data);
int					key_hook(int key, t_data *data);

#endif
