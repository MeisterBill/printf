/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:31:53 by artvan-d          #+#    #+#             */
/*   Updated: 2022/09/12 14:16:32 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_hexa(unsigned int nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static void	ft_put_hexa(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		ft_put_hexa(nb / 16, format);
		ft_put_hexa(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + 48);
		else
		{
			if (format == 'x')
				ft_putchar(nb - 10 + 97);
			if (format == 'X')
				ft_putchar(nb - 10 + 65);
		}
	}
}

int	ft_print_hexa(unsigned int nb, const char format)
{
	if (nb == 0)
		write(1, "0", 1);
	else
		ft_put_hexa(nb, format);
	return (ft_len_hexa(nb));
}
