/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:04:30 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/08 13:18:09 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

short		offset_x(t_tetri *t)
{
	short	*tab;
	short	tmp;
	int		i;

	tmp = 0;
	i = 0;
	if (!(tab = (short *)malloc(sizeof(short) * 4)))
		return (-1);
	tab[0] = t->a.x;
	tab[1] = t->b.x;
	tab[2] = t->c.x;
	tab[3] = t->d.x;
	while (++i < 4)
	{
		if (tab[i - 1] > tab[i])
		{
			tmp = tab[i - 1];
			tab[i - 1] = tab[i];
			tab[i] = tmp;
			i = 0;
		}
	}
	tmp = tab[0];
	free(tab);
	return (tmp);
}

short		offset_y(t_tetri *t)
{
	short	*tab;
	short	tmp;
	int		i;

	tmp = 0;
	i = 0;
	if (!(tab = (short *)malloc(sizeof(short) * 4)))
		return (-1);
	tab[0] = t->a.y;
	tab[1] = t->b.y;
	tab[2] = t->c.y;
	tab[3] = t->d.y;
	while (++i < 4)
	{
		if (tab[i - 1] > tab[i])
		{
			tmp = tab[i - 1];
			tab[i - 1] = tab[i];
			tab[i] = tmp;
			i = 0;
		}
	}
	tmp = tab[0];
	free(tab);
	return (tmp);
}
