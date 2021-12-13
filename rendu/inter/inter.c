/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:28:17 by kevyn             #+#    #+#             */
/*   Updated: 2021/12/13 10:43:27 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int		ft_verif(char val, char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == val)
			return (0);
		i++;
	}
	return(1);
}

void	ft_inter(char *str, char *str2)
{
	int	i;
	int	y;
	int z;
	char res[250];
	
	i = 0;
	y = 0;
	z = 0;
	while(str[i])
	{
		while(str2[y])
		{
			if (str[i] == str2[y] && ft_verif(str[i], res) == 1)
			{
				res[z] = str[i];
				z++;
			}
			y++;
		}
		y = 0;
		i++;
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

int main(int argc, char **argv)
{
	if(argc != 3)
		write(1, "\n", 1);
	else
		ft_inter(argv[1], argv[2]);
}
