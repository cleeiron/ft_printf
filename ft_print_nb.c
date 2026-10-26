/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:39:32 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/26 11:13:39 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nb(int n)
{
	long int	nb;
	int			len;
	int			result;

	nb = n;
	len = 0;
	result = 0;
	if (n < 0)
	{
		result = ft_print_char('-');
		if (result == -1)
			return (-1);
		len += result;
		nb = -nb;
	}
	result = ft_print_nb_base(nb, "0123456789");
	if (result == -1)
		return (-1);
	len += result;
	return (len);
}
