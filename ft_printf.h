/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:55:39 by artvan-d          #+#    #+#             */
/*   Updated: 2022/09/01 15:03:43 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_printstr(const char *str);
int		ft_printptr(unsigned long nb);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_hexa(unsigned int nb, const char format);
char	*ft_itoa(int n);

#endif
