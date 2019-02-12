/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:55:59 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/12 18:21:34 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		lastline(t_tetri *t, t_var *v)
{
	if (t->a.y + (*v).y >= (*v).j || t->b.y + (*v).y >= (*v).j
		|| t->c.y + (*v).y >= (*v).j || t->d.y + (*v).y >= (*v).j)
		return (1);
	return (0);
}

int		tetri_offmap(t_var *v, t_tetri *t)
{
	if ((*v).ltr >= 'B' && (t->a.x + (*v).x >= (*v).j
	|| t->b.x + (*v).x >= (*v).j || t->c.x + (*v).x >= (*v).j
	|| t->d.x + (*v).x >= (*v).j))
		return (1);
	return (0);
}

int		last_tetri_offmap(t_var *v, t_tetri *t)
{
	if ((*v).ltr == 'A' && (t->a.x + (*v).x >= (*v).j
	|| t->b.x + (*v).x >= (*v).j || t->c.x + (*v).x >= (*v).j
	|| t->d.x + (*v).x >= (*v).j))
		return (1);
	return (0);
}

int		last_column(t_var *v, t_tetri *t)
{
	if (t->a.x + (*v).x >= (*v).j || t->b.x + (*v).x >= (*v).j
		|| t->c.x + (*v).x >= (*v).j || t->d.x + (*v).x >= (*v).j)
		return (1);
	return (0);
}

int		placeable(t_var *v, t_tetri *t, char **map)
{
	if (map[t->a.y + (*v).y][t->a.x + (*v).x] == '.'
		&& map[t->b.y + (*v).y][t->b.x + (*v).x] == '.'
		&& map[t->c.y + (*v).y][t->c.x + (*v).x] == '.'
		&& map[t->d.y + (*v).y][t->d.x + (*v).x] == '.')
		return (1);
	return (0);
}
