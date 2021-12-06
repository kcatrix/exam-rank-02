/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:34:14 by kcatrix           #+#    #+#             */
/*   Updated: 2021/12/06 13:57:22 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_inter(char *str, char *str2)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1,&str[i],1);
		i++;
	}
}
int main(int argc, char **argv)
{
	int i;
	
	i = 1;
	if (argc != 3)
		return (0);
    ft_inter(argv[i], argv[i + 1]);
}