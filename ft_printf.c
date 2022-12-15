/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:32:00 by artvan-d          #+#    #+#             */
/*   Updated: 2022/09/12 14:16:20 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_type(va_list args, const char format)
{
	int		len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_printptr(va_arg(args, unsigned long));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		args;
	int			len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_check_type(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end (args);
	return (len);
}

/*
#include <stdio.h>

int	main(void)
{
	char	lettre;
	char	*str;
	int		nb;
	int		n;

	lettre = 'a';
	str = "un mot";
	nb = 32;
	n = -789;

	ft_printf("lettre a : %c\n", lettre);
	printf("lettre a : %c\n", lettre);

	ft_printf("mot : %s\n", str);
	printf("mot : %s\n", str);

	ft_printf("adresse : %p\n", str);
	printf("adresse : %p\n", str);

	ft_printf("chiffre unsigned : %u\n", nb);
	printf("chiffre unsigned : %u\n", nb);

	ft_printf("int : %i\n", n);
	printf("int : %d\n", n);

	ft_printf("hexa : %X\n", nb);
	printf("hexa : %X\n", nb);

	ft_printf("pourcent : %%\n");
	printf("pourcent : %%\n");
}
*/
