/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 02:52:29 by luwargni          #+#    #+#             */
/*   Updated: 2019/07/23 22:06:10 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/*
** -------------------------- ft_itoa ----------------------------------
*/
char			*ft_itoa(int nbr);

/*
** -------------------------- ft_memcpy --------------------------------
*/
void			*ft_memcpy(void *dest, const void *src, size_t n);

/*
** -------------------------- ft_putchar_fd ----------------------------
*/
void			ft_putchar_fd(char c, int fd);

/*
** -------------------------- ft_putendl_fd ----------------------------
*/
void			ft_putendl_fd(char const *s, int fd);

/*
** -------------------------- ft_putstr_fd -----------------------------
*/
void			ft_putstr_fd(char const *s, int fd);

/*
** -------------------------- ft_strcmp --------------------------------
*/
int				ft_strcmp(const char *s1, const char *s2);

/*
** -------------------------- ft_strdel --------------------------------
*/
void			ft_strdel(char **as);

/*
** -------------------------- ft_strjoin --------------------------------
*/
char			*ft_strjoin(char const *s1, char const *s2);

/*
** -------------------------- ft_strlen ---------------------------------
*/
size_t			ft_strlen(const char *s);

/*
** -------------------------- ft_strcpy ---------------------------------
*/
char			*ft_strcpy(char *dest, const char *src);

#endif
