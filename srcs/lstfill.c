/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:10:46 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/08 15:28:23 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tocorner(t_tetri *t)
{
	while (t->a.x != 0 && t->b.x != 0 && t->c.x != 0 && t->d.x != 0)
	{
		t->a.x--;
		t->b.x--;
		t->c.x--;
		t->d.x--;
	}
	while (t->a.y != 0 && t->b.y != 0 && t->c.y != 0 && t->d.y != 0)
	{
		t->a.y--;
		t->b.y--;
		t->c.y--;
		t->d.y--;
	}
}

void	put_coord(int i, int sharp, t_tetri *tetri)
{
	if (sharp == 0)
	{
		tetri->a.x = i % 5;
		tetri->a.y = i / 5;
	}
	if (sharp == 1)
	{
		tetri->b.x = i % 5;
		tetri->b.y = i / 5;
	}
	if (sharp == 2)
	{
		tetri->c.x = i % 5;
		tetri->c.y = i / 5;
	}
	if (sharp == 3)
	{
		tetri->d.x = i % 5;
		tetri->d.y = i / 5;
	}
}

t_tetri	*createlist(void)
{
	t_tetri *list;

	if (!(list = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_tetri	*firstlink(char *buff, t_tetri *t)
{
	short	i;
	short	sharp;

	i = 0;
	sharp = 0;
	t = createlist();
	while (i < 19)
	{
		if (buff[i] == '#')
			put_coord(i, sharp++, t);
		++i;
	}
	tocorner(t);
	buff += 21;
	return (t);
}

t_tetri	*lstfill(char *buff, t_tetri **t)
{
	short	i;
	short	sharp;
	t_tetri *flink;
	t_tetri	*tmp;

	flink = firstlink(buff, *t);
	buff += 21;
	tmp = flink;
	while (*buff)
	{
		i = -1;
		sharp = 0;
		*t = createlist();
		while (++i < 19)
		{
			if (buff[i] == '#')
				put_coord(i, sharp++, *t);
		}
		tocorner(*t);
		flink->next = *t;
		flink->next->prev = flink;
		buff += 21;
		flink = flink->next;
	}
	return (tmp);
}
