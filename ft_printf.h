/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:41:36 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/26 10:41:53 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_conversion(char letter, va_list args);
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_nb(int n);
int		ft_print_nb_base(unsigned long n, char *base);
int		ft_print_adress(void *ptr);
size_t	ft_strlen(const char *s);

#endif