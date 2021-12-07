/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:02:16 by kcatrix           #+#    #+#             */
/*   Updated: 2021/12/07 10:46:54 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_verif(char	*str, char	no)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		if (str[i] == no)
			return (0);
		i++;
	}
	return(1);
}

void	ft_union(char *str, char *str2)
{
	int		i;
	int		y;
	int		z;
	char	res[128];

	i = 0;
	y = 0;
	z = 0;

	while (str[i])
	{
		if (ft_verif(res,str[i]) == 1)
            {
                res[z] = str[i];
                z++;
            }
		i++;
	}
	while(str2[y])
	{
		if (ft_verif(res,str2[y]) == 1)
		{
			res[z] = str2[y];
			z++;	
		}
		y++;
	}
	res[z] = '\0';
	i = 0;
	while (res[i])
	{
		write(1, &res[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
int	main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);
	else
		ft_union(argv[1], argv[2]);
}
