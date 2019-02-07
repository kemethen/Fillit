/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:31:13 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/07 16:04:17 by kemethen         ###   ########.fr       */
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

void	recoord(t_tetri **t)
{
	++(*t)->a.x;
	++(*t)->b.x;
	++(*t)->c.x;
	++(*t)->d.x;
}

void	nextline(t_tetri **t, short cnt)
{
	++(*t)->a.y;
	++(*t)->b.y;
	++(*t)->c.y;
	++(*t)->d.y;
	(*t)->a.x = (*t)->a.x - cnt;
	(*t)->b.x = (*t)->b.x - cnt;
	(*t)->c.x = (*t)->c.x - cnt;
	(*t)->d.x = (*t)->d.x - cnt;
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

void	fillit(t_tetri *t)
{
	char	**map;
	short	j;
	short	cnt;
	char	sharp;

	j = 0;
	sharp = 'A';
	cnt = msize(&t);
	map = (char **)malloc(sizeof(char *) * (cnt + 1));
	map[cnt] = NULL;
	while (j < cnt)
		map[j++] = ft_strndup("...........", cnt);
	cnt = 0;
	while (t != NULL)
	{
		if (t->a.y >= j || t->b.y >= j || t->c.y >= j || t->d.y >= j)
		{
			if (sharp == 'A' && (t->a.x > j || t->b.x > j || t->c.x > j || t->d.x > j))
			{
				map = recreatemap(map);
				++j;
				while (t->prev)
				{
					t = t->prev;
					--sharp;
				}
				tocorner(t);
			}
			else if (sharp >= 'B' && (t->a.x >= j || t->b.x >= j || t->c.x >= j || t->d.x >= j))
			{
				tocorner(t);
				t = t->prev;
				map[t->a.y][t->a.x] = '.';
				map[t->b.y][t->b.x] = '.';
				map[t->c.y][t->c.x] = '.';
				map[t->d.y][t->d.x] = '.';
				recoord(&t);
				--sharp;
			}	
			else
			{
				recoord(&t);
				++cnt;
			}
			
		}
		else if (t->a.x >= j || t->b.x >= j || t->c.x >= j || t->d.x >= j)
		{
			nextline(&t, cnt);
			cnt = 0;
		}
		else if (map[t->a.y][t->a.x] == '.' && map[t->b.y][t->b.x] == '.'
			&& map[t->c.y][t->c.x] == '.' && map[t->d.y][t->d.x] == '.')
		{
			map[t->a.y][t->a.x] = sharp;
			map[t->b.y][t->b.x] = sharp;
			map[t->c.y][t->c.x] = sharp;
			map[t->d.y][t->d.x] = sharp;
			t = t->next;
			++sharp;
			cnt = 0;
		}
		else
		{
			recoord(&t);
			++cnt;
		}
	}
	ft_displaytab(map);
	free(map);
	free(t);
}
