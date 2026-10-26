/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:49:07 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/26 11:23:31 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_adress(void *ptr)
{
	int	len;
	int	result;

	len = 0;
	if (ptr == NULL)
		return (ft_print_str("(nil)"));
	result = ft_print_str("0x");
	if (result == -1)
		return (-1);
	len += result;
	result = ft_print_nb_base((unsigned long)ptr, "0123456789abcdef");
	if (result == -1)
		return (-1);
	len += result;
	return (len);
}
