/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 21:13:45 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/26 11:16:06 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choose_print(const char *format, int *i, va_list args)
{
	int	result;

	if (format[*i] == '%')
	{
		result = ft_conversion(format[*i +1], args);
		(*i)++;
	}
	else
		result = ft_print_char(format[*i]);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		result;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		result = ft_choose_print(format, &i, args);
		if (result == -1)
		{
			va_end(args);
			return (-1);
		}
		count += result;
		i++;
	}
	va_end(args);
	return (count);
}
