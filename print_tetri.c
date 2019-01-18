/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:30:35 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/11 18:18:57 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tetri(t_tetri *tetri, short cnt)
{
	while (cnt--)
	{
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
		tetri = tetri->next;
	}
}
