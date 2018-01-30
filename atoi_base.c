/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:15:30 by afokin            #+#    #+#             */
/*   Updated: 2017/12/12 18:15:33 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int			ft_atoi_hex(char *str, int base)
{
	int					z;
	unsigned int		res;

	z = 1;
	res = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 16 + *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			res = res * 16 + *str - 'a' + 10;
		else
			res = res * 16 + *str - 'A' + 10;
	}
	return (res);
}
