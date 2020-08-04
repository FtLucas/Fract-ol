/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:48:29 by luwargni          #+#    #+#             */
/*   Updated: 2019/07/23 22:08:35 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t			size;
	size_t			neg;
	unsigned int	nb;
	char			*str;

	size = 0;
	neg = 0;
	if (n < 0)
	{
		neg++;
		size++;
		n = n * -1;
	}
	nb = n;
	while (n /= 10)
		size++;
	if (!(str = (char *)malloc(sizeof(char) * (size) + 1)))
		return (NULL);
	str[size + 1] = '\0';
	str[size] = (48 + nb % 10);
	while (nb /= 10)
		str[--size] = (48 + nb % 10);
	if (neg == 1)
		str[--size] = '-';
	return (str);
}
