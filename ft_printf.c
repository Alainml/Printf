/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almirand <almirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:21:23 by almirand          #+#    #+#             */
/*   Updated: 2022/05/09 16:15:50 by almirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Treats the flag after %, deppending the char.
 *
 * @param {Character} Flag char to treat
 * @param {list} list of variables to print
 *
 * @return {n_written} Returns the number of written chars
 */
int	ft_treat_format(char c, va_list list)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (c == 'p')
		return (write(1, "0x", 2)
			+ ft_put_unsignbr_base(va_arg(list, unsigned long int),
				"0123456789abcdef"));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(list, int)));
	else if (c == 'u')
		return (ft_put_unsignbr_base(va_arg(list, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_put_unsignbr_base(va_arg(list, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_put_unsignbr_base(va_arg(list, unsigned int),
				"0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar(c));
}

/*
 * Formats and prints the given arguments.
 *
 * @param {parameters} Unlimited numbers to format and print
 *
 * @returm {n_written} Number of written chars
 */
int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	list;

	i = 0;
	counter = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
			counter += ft_treat_format(str[++i], list);
		else
			counter += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (counter);
}
