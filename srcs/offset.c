/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:04:30 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/13 12:30:07 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		offset_x(t_tetri *t)
{
	int		*tab;
	int		tmp;
	int		i;

	tmp = 0;
	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * 4)))
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

int		offset_y(t_tetri *t)
{
	int		*tab;
	int		tmp;
	int		i;

	tmp = 0;
	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * 4)))
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

char	**remake(char **map, t_var *v, t_tetri **t)
{
	map = recreatemap(map);
	changecoord(v, 'A', t);
	return (map);
}

char	**placetetri(char **map, t_tetri **t, t_var *v)
{
	map = setletter(map, *t, v->ltr, v);
	changecoord2(v, *t);
	*t = (*t)->next;
	return (map);
}
