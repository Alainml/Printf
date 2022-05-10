/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almirand <almirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:21:23 by almirand          #+#    #+#             */
/*   Updated: 2022/05/09 17:15:19 by almirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

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

int	ft_treat_bonus(char bonus, char flag, va_list list)
{
	int	counter;
	int	nbr;

	counter = 0;
	if (bonus == ' ')
	{
		if (flag == 'd' || flag == 'i')
			counter += write(1, " ", 1);
	}
	else if (bonus == '+')
	{
		if (flag == 'd' || flag == 'i')
		{
			nbr = va_arg(list, int);
			if (nbr >= 0)
				counter += write(1, "+", 1);
			return (counter + ft_putnbr(nbr));
		}
	}
	else if (bonus == '#')
	{
		if (flag == 'x' || flag == 'X')
			counter += write(1, "0x", 2);
	}
	return (counter + ft_treat_format(flag, list));
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
		{
			if (str[i + 1] == '#' || str[i + 1] == ' ' || str[i + 1] == '+')
			{
				counter += ft_treat_bonus(str[i + 1], str[i + 2], list);
				i += 2;
			}
			else
				counter += ft_treat_format(str[++i], list);
		}
		else
			counter += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (counter);
}

int main()
{
	ft_printf("% d \n", -1);
	printf("% d \n", -1);
}
