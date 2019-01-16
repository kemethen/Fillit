/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:05:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/16 18:08:43 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*fillmap(t_tetri *tetri, short line)
{
	short	i;
	char	*str;

//	ft_putstr("Je rentre dans fillmap\nLine = ");
//	ft_putnbr(line);
//	ft_putchar('\n');
	str = ft_strnew(6);
	i = 0;
	if (line > 4)
		line = line % 4;
	while (i < 4)
		str[i++] = '.';
	str[4] = '\n';
	str[5] = '\0';
	if (tetri->a.x == 0 && tetri->b.x == 0 && tetri->c.x == 0 && tetri->d.x == 0)
	{
		ft_putstr(str);
		return (str);
	}
	if ((line + 4) % (tetri->a.y + 4) == 0)
	{
		str[tetri->a.x] = '#';
//		printf("Je place un sharp dans str[%d] depuis A\n", tetri->a.x);
	}
	if ((line + 4) % (tetri->b.y + 4) == 0)
	{
		str[tetri->b.x] = '#';
//		printf("Je place un sharp dans str[%d] depuis B\n", tetri->b.x);
	}
	if ((line + 4) % (tetri->c.y + 4) == 0)
	{
		str[tetri->c.x] = '#';
//		printf("Je place un sharp dans str[%d] depuis C\n", tetri->c.x);
	}
	if ((line + 4) % (tetri->d.y + 4) == 0)
	{
		str[tetri->d.x] = '#';
//		printf("Je place un sharp dans str[%d] depuis D\n", tetri->d.x);
	}
	ft_putstr(str);
	return (str);
}

void	createmap(t_tetri *tetri, short count)
{
	char	**map;
	short	i;
	short	j;

	i = 0;
	j = 0;
	map = (char **)malloc(sizeof(char *) * (count * 4 + 1));
	map[count * 4] = NULL;
	while (j < count * 4)
	{
		map[j] = ft_strdup(fillmap(tetri, j));
		if (j % 4 == 0 && j > 0)
			tetri = tetri->next;
		j++;
	}
}
