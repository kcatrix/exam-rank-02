/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:34:14 by kcatrix           #+#    #+#             */
/*   Updated: 2021/12/06 13:40:52 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
int main()
{
    char chaine[] = "jesui";
    char chaine2[] = "sasas";

    ft_inter(chaine, chaine2);
}