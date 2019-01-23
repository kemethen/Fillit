/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:31:13 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/23 19:12:42 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_displaytab(char **tab)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = 0;
	while (tab[i] != NULL)
	{
		i++;
		size++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		i++;
	}
}

int		msize(t_tetri **t)
{
	int		cnt;
	int		racine;

	cnt = 1;
	racine = 1;
	while ((*t)->next)
	{
		if ((*t)->next)
			*t = (*t)->next;
		cnt++;
	}
	cnt = cnt * cnt;
	while (racine * racine < cnt)
		racine++;
	return (racine + 1);
}

void	createmap(t_tetri *t)
{
	char	**map;
	short	i;
	short	j;
	short	cnt1;
	char	sharp;
	short	cnt2;

	i = 0;
	j = 0;
	sharp = 'A';
	cnt1 = 0;
	cnt2 = 0;
	map = (char **)malloc(sizeof(char *) * (msize(&t)));
	while (j < msize(&t))
		map[j++] = ft_strdup(".\n");
	map[j] = NULL;
	j--;
	while (t != NULL)
	{
		if (t->a.x > j || t->b.x > j || t->c.x > j || t->d.x > j)
		{
			t->a.y++;
			t->b.y++;
			t->c.y++;
			t->d.y++;
			cnt2++;
			t->a.x = t->a.x - cnt1;
			t->b.x = t->b.x - cnt1;
			t->c.x = t->c.x - cnt1;
			t->d.x = t->d.x - cnt1;
			cnt1 = 0;
		}
		if (t->a.y > j || t->b.y > j || t->c.y > j || t->d.y > j)
		{
		//	j = 0;
		//	while (map[j] != NULL)
		//	{
		//		free(map[j]);
		//		j++;
		//	}
			free(map);
			ft_putstr("J = ");
			ft_putnbr(j);
			ft_putchar('\n');
			map = (char **)malloc(sizeof(char *) * j + 1);
			map[j] = NULL;
			while (j >= 0)
			{
				map[j] = ft_strdup("........\n");
				j--;
			}
			j = cnt2;
			ft_putstr("cnt 2 = ");
			ft_putnbr(cnt2);
			ft_putchar('\n');
			while (t->prev != NULL)
			{
				t->a.y = t->a.y - cnt2;
				t->b.y = t->b.y - cnt2;
				t->c.y = t->c.y - cnt2;
				t->d.y = t->d.y - cnt2;
				t = t->prev;
			}
			cnt2 = 0;
		}
		if (map[t->a.y][t->a.x] == '.' && map[t->b.y][t->b.x] == '.'
			&& map[t->c.y][t->c.x] == '.' && map[t->d.y][t->d.x == '.'])
		{
			map[t->a.y][t->a.x] = sharp;
			map[t->b.y][t->b.x] = sharp;
			map[t->c.y][t->c.x] = sharp;
			map[t->d.y][t->d.x] = sharp;
			t = t->next;
			sharp = sharp + 1;
			ft_displaytab(map);
			ft_putchar('\n');
		}
		else
		{
			t->a.x++;
			t->b.x++;
			t->c.x++;
			t->d.x++;
			cnt1++;
		}
	}
	ft_displaytab(map);
	free(map);
	free(t);
}
