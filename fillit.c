/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:31:13 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/07 20:33:25 by kemethen         ###   ########.fr       */
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
	short	x = 0;
	short	y = 0;
	char	sharp;

	j = 0;
	sharp = 'A';
	cnt = msize(&t);
	map = (char **)malloc(sizeof(char *) * (cnt + 1));
	map[cnt] = NULL;
	while (j < cnt)
		map[j++] = ft_strndup("...........", cnt);
	while (t != NULL)
	{
		ft_putstr("Sharp = ");
		ft_putchar(sharp);
		ft_putchar('\n');
		ft_putstr("J = ");
		ft_putnbr(j);
		ft_putchar('\n');
		ft_putstr("A.X : ");
		ft_putnbr(t->a.x + x);
		ft_putchar('\n');
		ft_putstr("A.Y : ");
		ft_putnbr(t->a.y + y);
		ft_putchar('\n');
		ft_putstr("B.X : ");
		ft_putnbr(t->b.x + x);
		ft_putchar('\n');
		ft_putstr("B.Y : ");
		ft_putnbr(t->b.y + y);
		ft_putchar('\n');
		ft_putstr("C.X : ");
		ft_putnbr(t->c.x + x);
		ft_putchar('\n');
		ft_putstr("C.Y : ");
		ft_putnbr(t->c.y + y);
		ft_putchar('\n');
		ft_putstr("D.X : ");
		ft_putnbr(t->d.x + x);
		ft_putchar('\n');
		ft_putstr("D.Y : ");
		ft_putnbr(t->d.y + y);
		ft_putstr("\n_______________________________________________________________________________________________________________________\n");
		if (t->a.y + y >= j || t->b.y + y >= j || t->c.y + y >= j || t->d.y + y >= j)
		{
			ft_putstr("Derniere ligne\n");
			if (sharp == 'A' && (t->a.x + x >= j || t->b.x + x >= j || t->c.x + x >= j || t->d.x + x >= j))
			{
				tocorner(t);
				ft_putstr("Je refais la map\n");
				map = recreatemap(map);
				++j;
				x = 0;
				y = 0;
			}
			else if (sharp >= 'B' && (t->a.x + x >= j || t->b.x + x >= j || t->c.x + x >= j || t->d.x + x >= j))
			{
				ft_putstr("Je reviens sur la piece d'avant\n");
				tocorner(t);
				t = t->prev;
				--sharp;
				map[t->a.y][t->a.x] = '.';
				map[t->b.y][t->b.x] = '.';
				map[t->c.y][t->c.x] = '.';
				map[t->d.y][t->d.x] = '.';
				x = 1;
				y = 0;
			}	
			else
			{
				ft_putstr("Je me deplace sur la derniere ligne\n");
				++x;
			}
		}
		else if (t->a.x + x >= j || t->b.x + x >= j || t->c.x + x >= j || t->d.x + x >= j)
		{
			ft_putstr("Bout de ligne\n");
			x = 0;
			++y;
		}
		else if (map[t->a.y + y][t->a.x + x] == '.' && map[t->b.y + y][t->b.x + x] == '.'
				&& map[t->c.y + y][t->c.x + x] == '.' && map[t->d.y + y][t->d.x + x] == '.')
		{
			ft_putstr("Je place ma piece\n");
			map[t->a.y + y][t->a.x + x] = sharp;
			map[t->b.y + y][t->b.x + x] = sharp;
			map[t->c.y + y][t->c.x + x] = sharp;
			map[t->d.y + y][t->d.x + x] = sharp;
			++sharp;
			t->a.x = t->a.x + x;
			t->a.y = t->a.y + y;
			t->b.x = t->b.x + x;
			t->b.y = t->b.y + y;
			t->c.x = t->c.x + x;
			t->c.y = t->c.y + y;
			t->d.x = t->d.x + x;
			t->d.y = t->d.y + y;
			x = 0;
			y = 0;
			t = t->next;
			ft_putstr("Pour le moment ma map ressemble a \n");
			ft_displaytab(map);
			ft_putchar('\n');
		}
		else
			++x;
	}
	ft_displaytab(map);
	free(map);
	free(t);
}
