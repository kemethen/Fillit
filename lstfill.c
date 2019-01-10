/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:25:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/10 19:16:41 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		lstfill(char *buff, t_tetri *tetri)
{
	short	i;
	short	sharp;

	i = 0;
	sharp = 0;
	while (i < 19)
	{
		if (buff[i] == '#')
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
			++sharp;
		}
		++i;
	}
	ft_putstr("A.X : ");
	ft_putnbr(tetri->a.x);
	ft_putchar('\n');
	ft_putstr("A.Y : ");
	ft_putnbr(tetri->a.y);
	ft_putchar('\n');
	ft_putstr("B.X : ");
	ft_putnbr(tetri->b.x);
	ft_putchar('\n');
	ft_putstr("B.Y : ");
	ft_putnbr(tetri->b.y);
	ft_putchar('\n');
	ft_putstr("C.X : ");
	ft_putnbr(tetri->c.x);
	ft_putchar('\n');
	ft_putstr("C.Y : ");
	ft_putnbr(tetri->c.y);
	ft_putchar('\n');
	ft_putstr("D.X : ");
	ft_putnbr(tetri->d.x);
	ft_putchar('\n');
	ft_putstr("D.Y : ");
	ft_putnbr(tetri->d.y);
	ft_putstr("\n_______________________________________________________________________________________________________________________\n");
}
