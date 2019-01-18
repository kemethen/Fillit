/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:05:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/18 13:28:15 by kemethen         ###   ########.fr       */
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
	str[19] = '\n';
	str[tetri->a.x + tetri->a.y * 5] = '@' + count - line;
	str[tetri->b.x + tetri->b.y * 5] = '@' + count - line;
	str[tetri->c.x + tetri->c.y * 5] = '@' + count - line;
	str[tetri->d.x + tetri->d.y * 5] = '@' + count - line;
	return (str);
}
*/
void	createmap(t_tetri *tetri, short count)
{
	char	**map;
	short	i;
	short	j;

	i = 0;
	j = 0;
	map = (char **)malloc(sizeof(char *) * (21));
	map[20] = NULL;
	while (j < 20)
	{
		map[j] = ft_strdup("....................\n");
		ft_putstr(map[j]);
		j++;
	}
}
