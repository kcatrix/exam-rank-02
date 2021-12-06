/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:34:14 by kcatrix           #+#    #+#             */
/*   Updated: 2021/12/06 15:40:17 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	strverif(char *strv, char no)
{
	int i;

	i = 0;
	while(strv[i])
	{
		if(strv[i] == no)
			return (0);
		i++;
	}
	return(1);
}

void	ft_inter(char *str, char *str2)
{
	int i;
	int y;
	int z;
	char *res;

	i = 0;
	y = 0;
	z = 0;

	while(str[i])
	{
		while(str2[y])
		{
			if (str[i] == str2[y] && (strverif(res, str2[y]) == 1))
			{
				res[z] =  str2[y];
				z++;
			}
			y++;
		}
		i++;
		y = 0;
	}
	res[z] = '\0';
	i = 0;
	while(res[i])
	{
		write(1, &res[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
int main(int argc, char **argv)
{
	int i;
	
	i = 1;
	if (argc != 3)
		write(1,"\n",1);
	else
    	ft_inter(argv[i], argv[i + 1]);
}
