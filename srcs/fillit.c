/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:31:13 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/12 19:48:13 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**recreatemap(char **map)
{
	int		j;
	int		k;

	j = 0;
	while (map[j] != NULL)
	{
		free(map[j]);
		j++;
	}
	k = j + 1;
	free(map);
	if (!(map = (char **)malloc(sizeof(char *) * (k + 1))))
		return (NULL);
	map[k] = NULL;
	j = 0;
	while (j < k)
	{
		map[j] = ft_strndup("........................", k);
		j++;
	}
	return (map);
}

void	recoord(t_tetri *t, int x, int y, char sign)
{
	if (sign == '+')
	{
		t->a.x += x;
		t->a.y += y;
		t->b.x += x;
		t->b.y += y;
		t->c.x += x;
		t->c.y += y;
		t->d.x += x;
		t->d.y += y;
	}
	if (sign == '-')
	{
		t->a.x -= x;
		t->a.y -= y;
		t->b.x -= x;
		t->b.y -= y;
		t->c.x -= x;
		t->c.y -= y;
		t->d.x -= x;
		t->d.y -= y;
	}
}

char	**fillit(t_tetri *t, t_var *v, char **map)
{
	(*v).ltr = 'A';
	while (t != NULL)
	{
		if (lastline(t, v))
		{
			if (last_tetri_offmap(v, t))
			{
				map = recreatemap(map);
				++(*v).j;
				(*v).x = 0;
				(*v).y = 0;
			}
			else if (tetri_offmap(v, t))
			{
				tocorner(t);
				t = t->prev;
				--(*v).ltr;
				(*v).x = offset_x(t);
				(*v).y = offset_y(t);
				map = setpoint(map, t);
				recoord(t, (*v).x, (*v).y, '-');
				++(*v).x;
			}
			else
				++(*v).x;
		}
		else if (last_column(v, t))
		{
			(*v).x = 0;
			++(*v).y;
		}
		else if (placeable(v, t, map))
		{
			map = setletter(map, t, (*v).ltr, *v);
			++(*v).ltr;
			recoord(t, (*v).x, (*v).y, '+');
			(*v).x = 0;
			(*v).y = 0;
			t = t->next;
		}
		else
			++(*v).x;
	}
	return (map);
}
