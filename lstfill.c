/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:25:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/18 19:34:53 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*lstfill(char *buff, t_tetri *tetri)
{
	short	i;
	short	sharp;
	t_tetri *tmp;

	i = 0;
	sharp = 0;
	tmp = malloc(sizeof(t_tetri));
	while (i < 19)
	{
		if (buff[i] == '#')
		{
			if (sharp == 0)
			{
				tmp->a.x = i % 5;
				tmp->a.y = i / 5;
			}
			if (sharp == 1)
			{
				tmp->b.x = i % 5;
				tmp->b.y = i / 5;
			}
			if (sharp == 2)
			{
				tmp->c.x = i % 5;
				tmp->c.y = i / 5;
			}
			if (sharp == 3)
			{
				tmp->d.x = i % 5;
				tmp->d.y = i / 5;
				tmp->next = tetri;
			}
			++sharp;
		}
		++i;
	}
	return (tmp);
}
