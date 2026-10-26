/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:12:48 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/26 11:14:59 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nb_base(unsigned long n, char *base)
{
	int				result;
	int				len;
	unsigned long	lbase;

	result = 0;
	len = 0;
	lbase = ft_strlen(base);
	if (n < lbase)
		return (ft_print_char(base[n % lbase]));
	else
	{
		result = ft_print_nb_base((n / lbase), base);
		if (result == -1)
			return (-1);
		len += result;
		result = ft_print_char(base[n % lbase]);
		if (result == -1)
			return (-1);
	}
	len += result;
	return (len);
}
