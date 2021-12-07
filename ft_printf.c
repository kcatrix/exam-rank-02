/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:13:20 by kcatrix           #+#    #+#             */
/*   Updated: 2021/12/07 15:07:36 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int glo;

int	ft_putnbr(int nb)
{
	char	b;

	if (nb < 0)
	{
		write(1, "-", 1);
		glo++;
		nb = nb * (-1);
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
	return(glo);
}

int	ft_putnbr_base(int nb, char *base)
{
	if (nb <= 15)
	{
		write(1, &base[nb], 1);
		glo++;
	}
	if (nb > 15)
	{
		ft_putnbr_base(nb / 16, base);
		ft_putnbr_base(nb % 16, base);
	}
	return (glo);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		glo++;
	}
	return (glo);
}

int	ft_convert(char val, void *param)
{
	if (val == 's')
		ft_putstr((char *)param);
	else if (val == 'd')
		ft_putnbr((int)param);
	else if (val == 'x')
		ft_putnbr_base((long)param, "0123456789ABCDEF");
	return (glo);
}

int ft_printf(const char *arg, ...)
{
	int i;

	i = 0;
	va_list ap;
	
	va_start(ap, arg);
	while(arg[i])
	{
		if (arg[i] == '%' && arg[i + 1] != '%')
		{
			i++;
			ft_convert(arg[i],va_arg(ap, void *));
		}
		else if (arg[i] == '%' && arg[i + 1] == '%')
		{
			write(1, "%", 1);
			i++;
		}
		else
		{
			write(1, &arg[i], 1);
			glo++;
		}
		i++;

	}
	return(glo);

}
int	main()
{
	printf("%d", ft_printf("%d",123456));
}
