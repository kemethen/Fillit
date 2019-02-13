/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:58:57 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/13 12:38:46 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**setpoint(char **map, t_tetri *t)
{
	map[t->a.y][t->a.x] = '.';
	map[t->b.y][t->b.x] = '.';
	map[t->c.y][t->c.x] = '.';
	map[t->d.y][t->d.x] = '.';
	return (map);
}

char	**setletter(char **map, t_tetri *t, char letter, t_var *v)
{
	map[t->a.y + v->y][t->a.x + v->x] = letter;
	map[t->b.y + v->y][t->b.x + v->x] = letter;
	map[t->c.y + v->y][t->c.x + v->x] = letter;
	map[t->d.y + v->y][t->d.x + v->x] = letter;
	return (map);
}

void	fillitfree(char *buff, t_tetri *tetri, char **map, t_var *v)
{
	int		j;
	t_tetri *tmp;

	free(buff);
	while (tetri)
	{
		tmp = tetri->next;
		free(tetri);
		tetri = tmp;
	}
	ft_displaytab(map);
	j = 0;
	while (map[j] != NULL)
	{
		free(map[j]);
		++j;
	}
	free(map);
	free(v);
}
