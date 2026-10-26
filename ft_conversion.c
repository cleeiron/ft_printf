/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:21:11 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/23 11:24:39 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_conversion(char letter, va_list args)
{
	if (letter == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (letter == 'd' || letter == 'i')
		return (ft_print_nb(va_arg(args, int)));
	if (letter == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (letter == 'p')
		return (ft_print_adress(va_arg(args, void *)));
	if (letter == 'u')
		return (ft_print_nb_base(va_arg(args, unsigned int),
				"0123456789"));
	if (letter == 'x')
		return (ft_print_nb_base(va_arg(args, unsigned int),
				"0123456789abcdef"));
	if (letter == 'X')
		return (ft_print_nb_base(va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	if (letter == '%')
		return (ft_print_char('%'));
	return (0);
}