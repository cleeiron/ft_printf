/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 21:13:45 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/23 16:32:27 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		result;

	i = 0;
	count = 0;
	result = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			result = ft_conversion(format[i +1], args);
			i++;
		}
		else
		{
			result = ft_print_char(format[i]);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
		}
		count += result;
		i++;
	}
	va_end(args);
	return (count);
}