/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almirand <almirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:35:45 by almirand          #+#    #+#             */
/*   Updated: 2022/05/09 15:49:17 by almirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
 * Writes an unsigned number into the given base
 *
 * @param{unsignbr} Number to print
 * @param{base} Base to transform the number into
 *
 * @return{n_written} Number of written chars.
 */
int	ft_put_unsignbr_base(unsigned long int unsignbr, char	*base)
{
	unsigned long int	lenbase;
	int					counter;

	counter = 0;
	lenbase = ft_strlen(base);
	if (unsignbr >= lenbase)
		counter += ft_put_unsignbr_base(unsignbr / lenbase, base);
	counter += ft_putchar(base[unsignbr % lenbase]);
	return (counter);
}

/*
 * Writes the given number
 *
 * @param{nb} Number to print
 *
 * @return{n_written} Number of written chars
 */
int	ft_putnbr(int nb)
{
	int	length;

	length = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (nb < 0)
		{
			length += ft_putchar('-');
			nb = nb * (-1);
		}
		if (nb > 9)
		{
			length += ft_putnbr(nb / 10);
			length += ft_putchar(nb % 10 + '0');
		}
		else
			length += ft_putchar(nb + '0');
	}
	return (length);
}
