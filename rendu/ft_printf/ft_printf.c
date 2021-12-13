/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:36:21 by kevyn             #+#    #+#             */
/*   Updated: 2021/12/13 12:31:38 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int glo;

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
		glo++;
	}
}

void	ft_putnbr(int nb)
{
	char b;
	
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		glo = glo + 11;
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
		glo++;
	}
	if (nb >= 0 && nb <= 9)
	{
		b = nb + '0';
		write(1, &b, 1);
		glo++;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_putnbr_base(int nb, char *base)
{
	if (nb >= 0 && nb <= 15)
	{
		write(1, &base[nb], 1);
		glo++;
	}
	else
	{
		ft_putnbr_base(nb / 16, base) ;
		ft_putnbr_base(nb % 16, base);
	}
}

void	ft_convert(char val, void *param)
{
	if (val == 's')
		ft_putstr((char *)param);
	if (val == 'd')
		ft_putnbr((int)param);
	if (val == 'x')
		ft_putnbr_base((int)param, "0123456789abcdef");
}

int		ft_printf(const char *arg, ...)
{
	int i;
	va_list ap;

	i = 0;
	va_start(ap, arg);
	while(arg[i])
	{
		if (arg[i] == '%' && arg[i + 1] != '%')
		{
			i++;
			ft_convert(arg[i], va_arg(ap, void *));
		}
		else if (arg[i] == '%' && arg[i + 1] == '%')
		{
			i++;
			write(1, "%", 1);
			glo++;
		}
		else
		{
			write(1, &arg[i], 1);
			glo++;
		}
		i++;
	}
	va_end(ap);
	return (glo);
}

