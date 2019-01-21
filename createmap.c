/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:05:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/21 19:08:54 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*char	*fillmap(t_tetri *tetri, short line, short count)
{
	short	i;
	char	*str;

//	ft_putstr("Je rentre dans fillmap\nLine = ");
//	ft_putnbr(line);
//	ft_putchar('\n');
	str = ft_strnew(20);
	i = 0;
	while (i < 20)
		str[i++] = '.';
	str[4] = '\n';
	str[9] = '\n';
	str[14] = '\n';
	str[19] = '\n';q
	str[tetri->a.x + tetri->a.y * 5] = '@' + count - line;
	str[tetri->b.x + tetri->b.y * 5] = '@' + count - line;
	str[tetri->c.x + tetri->c.y * 5] = '@' + count - line;
	str[tetri->d.x + tetri->d.y * 5] = '@' + count - line;
	return (str);
}
*/

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


void		firstlink(t_tetri *tetri)
{
	while (tetri->prev)
	{
		ft_putstr("Je remonte dans la liste\n");
		tetri = tetri->prev;
	}
	tetri->next = tetri;
}
void	createmap(t_tetri *t, short count)
{
	char	**map;
	short	i;
	short	j;
	char	sharp;

	i = 0;
	j = 0;
	sharp = 'A';
	map = (char **)malloc(sizeof(char *) * (21));
	map[20] = NULL;
	while (j < 20)
		map[j++] = ft_strdup("....................\n");
	while (t->prev)
		t = t->prev;
	while (t->next)
	{
		if (map[t->a.y][t->a.x] == '.' && map[t->b.y][t->b.x] == '.'
			&& map[t->c.y][t->c.x] == '.' && map[t->d.y][t->d.x == '.'])
		{
			map[t->a.y][t->a.x] = sharp;
			map[t->b.y][t->b.x] = sharp;
			map[t->c.y][t->c.x] = sharp;
			map[t->d.y][t->d.x] = sharp;
			t = t->next;
			sharp = sharp + 1;
		}
		else
		{
			t->a.x++;
			t->b.x++;
			t->c.x++;
			t->d.x++;
		}
	}
	ft_displaytab(map);
}
