/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:39:32 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/23 11:19:33 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_print_nb(int n)
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

int	ft_print_nb_base(unsigned long n, char *base)
{
	int 			result;
	int				len;
	int				lbase;

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
