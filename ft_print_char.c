/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:04:38 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/23 11:59:20 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	int	len;
	int	result;
	int	i;

	len = 0;
	result = 0;
	i = 0;
	if (s == NULL)
		return (ft_print_str("null"));
	while (s[i] != '\0')
	{
		result = ft_print_char(s[i]);
		if (result == -1)
			return (-1);
		len += result;
		i++;
	}
	return (len);
}

int ft_print_adress(void *ptr)
{
	int	len;
	int	result;

	len = 0;
	if (ptr == NULL)
		return (ft_print_str("nill"));
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
