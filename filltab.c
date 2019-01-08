/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filltab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:25:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/08 19:22:08 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**filltab(char *buff)
{
	static int	i = 0;
	int			j;
	int			k;
	char	**tab;

	j = 0;
	k = 0;
	ft_putstr("i = ");
	ft_putnbr(i);
	ft_putchar('\n');
	if (!(tab = (char **)malloc(sizeof(char *) * 6)))
		return (NULL);
	ft_putstr("slt je suis apres le malloc\n");
	if (buff)
	{
		ft_putstr("buff existe\n");
		if (!(tab[i] = (char *)malloc(sizeof(char) * 17)))
			return (NULL);
		ft_putstr("slt je suis apres le deuxieme malloc\n");
		while (buff[k] != '\0')
		{
			if (buff[k] == '\n')
				k++;
			tab[i][j++] = buff[k++];
		}
	}
	tab[5] = NULL;
	ft_displaytab((const char **)tab);
	i++;
	return (tab);
}
