/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:31:13 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/08 15:39:27 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**recreatemap(char **map)
{
	short	j;
	short	k;

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

int		msize(t_tetri **t)
{
	int		cnt;
	int		racine;

	racine = 1;
	cnt = 1;
	while ((*t)->next)
	{
		if ((*t)->next)
			*t = (*t)->next;
		++cnt;
	}
	while ((*t)->prev)
	{
		if ((*t)->prev)
			*t = (*t)->prev;
	}
	cnt *= 4;
	while (racine * racine < cnt)
		++racine;
	return (racine);
}

void	recoord(t_tetri *t, short x, short y, char sign)
{
	if (sign == '+')
	{
		t->a.x = t->a.x + x;
		t->a.y = t->a.y + y;
		t->b.x = t->b.x + x;
		t->b.y = t->b.y + y;
		t->c.x = t->c.x + x;
		t->c.y = t->c.y + y;
		t->d.x = t->d.x + x;
		t->d.y = t->d.y + y;
	}
	if (sign == '-')
	{
		t->a.x = t->a.x - x;
		t->a.y = t->a.y - y;
		t->b.x = t->b.x - x;
		t->b.y = t->b.y - y;
		t->c.x = t->c.x - x;
		t->c.y = t->c.y - y;
		t->d.x = t->d.x - x;
		t->d.y = t->d.y - y;
	}
}

void	fillit(t_tetri *t)
{
	char	**map;
	short	j;
	short	x;
	short	y;
	char	sharp;

	j = 0;
	x = 0;
	y = 0;
	sharp = 'A';
	map = (char **)malloc(sizeof(char *) * (msize(&t) + 1));
	map[msize(&t)] = NULL;
	while (j < msize(&t))
		map[j++] = ft_strndup("...........", msize(&t));
	while (t != NULL)
	{
		if (t->a.y + y >= j || t->b.y + y >= j
			|| t->c.y + y >= j || t->d.y + y >= j)
		{
			if (sharp == 'A' && (t->a.x + x >= j || t->b.x + x >= j
				|| t->c.x + x >= j || t->d.x + x >= j))
			{
				map = recreatemap(map);
				++j;
				x = 0;
				y = 0;
			}
			else if (sharp >= 'B' && (t->a.x + x >= j || t->b.x + x >= j
					|| t->c.x + x >= j || t->d.x + x >= j))
			{
				tocorner(t);
				t = t->prev;
				--sharp;
				x = offset_x(t);
				y = offset_y(t);
				map[t->a.y][t->a.x] = '.';
				map[t->b.y][t->b.x] = '.';
				map[t->c.y][t->c.x] = '.';
				map[t->d.y][t->d.x] = '.';
				recoord(t, x, y, '-');
				++x;
			}
			else
				++x;
		}
		else if (t->a.x + x >= j || t->b.x + x >= j
				|| t->c.x + x >= j || t->d.x + x >= j)
		{
			x = 0;
			++y;
		}
		else if (map[t->a.y + y][t->a.x + x] == '.'
				&& map[t->b.y + y][t->b.x + x] == '.'
				&& map[t->c.y + y][t->c.x + x] == '.'
				&& map[t->d.y + y][t->d.x + x] == '.')
		{
			map[t->a.y + y][t->a.x + x] = sharp;
			map[t->b.y + y][t->b.x + x] = sharp;
			map[t->c.y + y][t->c.x + x] = sharp;
			map[t->d.y + y][t->d.x + x] = sharp;
			++sharp;
			recoord(t, x, y, '+');
			x = 0;
			y = 0;
			t = t->next;
		}
		else
			++x;
	}
	ft_displaytab(map);
	j = 0;
	while (map[j] != NULL)
	{
		free(map[j]);
		j++;
	}
	free(map);
}
