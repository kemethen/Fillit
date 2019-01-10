/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filltab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:25:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/10 15:29:02 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_tetri(char *tab, char *buff, short count, short rank)
{
	short	i;
	short	j;

	i = 0;
	j = 0;
	while (buff[i])
	{
		if (j == 6 && count == 1)
			break ;
		else if (j == 7 && count == 0)
			break ;
		else if (j == 8 && count == 2)
			break ;
		if (buff[i] == '#')
			tab[j++] = buff[i] + 30 + rank;
		if ((buff[i] == '\n' && buff[i - 1] == '#')
			|| (buff[i] == '\n' && buff[i - 2] == '#')
			|| (buff[i] == '\n' && buff[i - 3] == '#'))
			tab[j++] = buff[i];
		i++;
	}
	tab[j] = '\0';
	return (tab);
}

char	*filltab(char *tab, char *buff, short rank)
{
	short	i;
	short	count;

	i = 0;
	count = 0;
	tab = NULL;
	while (buff[i++])
	{
		if (buff[i] == '#' && buff[i + 1] == '#' && buff[i + 2] == '#'
			&& buff[i + 3] == '#' && tab == NULL)
		{
			tab = ft_memalloc(6);
			count++;
		}
		else if (buff[i] == '#' && buff[i + 5] == '#' && buff[i + 10]
				&& buff[i + 15] == '#' && tab == NULL)
		{
			tab = ft_memalloc(9);
			count = 2;
		}
		else if (buff[i] == '#' && tab == NULL)
			tab = ft_memalloc(8);
	}
	return (tab = get_tetri(tab, buff, count, rank));
}
