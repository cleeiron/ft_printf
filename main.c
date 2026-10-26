/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:01:07 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/26 11:31:17 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
#include <unistd.h>

int	main(void)
{
	int	n;

	n = 42;
	int a;
	int b;
	char *str;
	str = NULL;
	int	result;

close(1);
result = ft_printf("Bonjour %d\n", 42);
fprintf(stderr, "Retour ft_printf : %d\n", result);

	printf("Original : %d %s %x %c\n", -42, "Salut", 255, 'A');
ft_printf("Le mien  : %d %s %x %c\n", -42, "Salut", 255, 'A');
	printf("Original : [%c] FIN\n", '\0');
ft_printf("Le mien  : [%c] FIN\n", '\0');
	a = printf("ABC%cDEF\n", '\0');
	b = ft_printf("ABC%cDEF\n", '\0');
	printf("Retour printf    : %d\n", a);
	printf("Retour ft_printf : %d\n", b);
	printf("Original : %p\n", (void *)NULL);
	ft_printf("Le mien  : %p\n", (void *)NULL);
	printf("Original : %s\n", str);
ft_printf("Le mien  : %s\n", str);
printf("Original : %d\n", printf("Bonjour"));
printf("Le tien  : %d\n", ft_printf("Bonjour"));
printf("===== PRINTF =====\n");
printf("Char : %c\n", 'A');
printf("String : %s\n", "Bonjour");
printf("Decimal : %d\n", -42);
printf("Integer : %i\n", INT_MIN);
printf("Unsigned : %u\n", UINT_MAX);
printf("Hexa : %x\n", 255);
printf("Hexa maj : %X\n", 255);
printf("Pointer : %p\n", (void *)&n);
printf("Percent : %%\n");
ft_printf("\n===== FT_PRINTF =====\n");
ft_printf("Char : %c\n", 'A');
ft_printf("String : %s\n", "Bonjour");
ft_printf("Decimal : %d\n", -42);
ft_printf("Integer : %i\n", INT_MIN);
ft_printf("Unsigned : %u\n", UINT_MAX);
ft_printf("Hexa : %x\n", 255);
ft_printf("Hexa maj : %X\n", 255);
ft_printf("Pointer : %p\n", (void *)&n);
ft_printf("Percent : %%\n");
	return (0);
}
