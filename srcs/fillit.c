/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:31:13 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/13 13:51:40 by kemethen         ###   ########.fr       */
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
		++j;
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
		++j;
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

void	changecoord(t_var *v, char sign, t_tetri **t)
{
	if (sign == 'A')
	{
		++v->j;
		v->x = 0;
		v->y = 0;
	}
	if (sign == 'B')
	{
		tocorner(*t);
		*t = (*t)->prev;
		--v->ltr;
		v->x = offset_x(*t);
		v->y = offset_y(*t);
	}
	if (sign == 'C')
	{
		recoord(*t, v->x, v->y, '-');
		++v->x;
	}
	if (sign == 'D')
	{
		v->x = 0;
		++v->y;
	}
}

void	changecoord2(t_var *v, t_tetri *t)
{
	++v->ltr;
	recoord(t, v->x, v->y, '+');
	v->x = 0;
	v->y = 0;
}

char	**fillit(t_tetri *t, t_var *v, char **map)
{
	while (t != NULL)
	{
		if (lastline(t, v))
		{
			if (last_tetri_offmap(v, t))
				map = remake(map, v, &t);
			else if (tetri_offmap(v, t))
			{
				changecoord(v, 'B', &t);
				map = setpoint(map, t);
				changecoord(v, 'C', &t);
			}
			else
				++v->x;
		}
		else if (last_column(v, t))
			changecoord(v, 'D', &t);
		else if (placeable(v, t, map))
			map = placetetri(map, &t, v);
		else
			++v->x;
	}
	return (map);
}
