/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:48:07 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/26 11:27:00 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	len;
	int	result;
	int	i;

	len = 0;
	result = 0;
	i = 0;
	if (s == NULL)
		return (ft_print_str("(null)"));
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
