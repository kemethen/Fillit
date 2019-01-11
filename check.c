/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:25:59 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/11 15:48:54 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static short	check_format(char *buff)
{
	short	i;

	i = 0;
	while (i++ < 20)
	{
		if (!(i % 5) && buff[i - 1] != '\n')
			return (0);
		if (i % 5 && buff[i - 1] != '#' && buff[i - 1] != '.')
			return (0);
	}
	return (1);
}

static short	check_tetri(char *buff)
{
	short	i;
	short	hashtag;
	short	link;

	i = 0;
	hashtag = 0;
	link = 0;
	while (i < 19)
	{
		if (buff[i] == '#')
		{
			++hashtag;
			if (buff[i + 1] == '#')
				++link;
			if (i < 14 && buff[i + 5] == '#')
				++link;
		}
		++i;
	}
	if (hashtag != 4 || link < 3)
		return (0);
	return (1);
}

short			check_file(int fd, char *buff)
{
	short	ret;
	short	last_ret;
	short	cnt;
	t_tetri	*tetri;

	last_ret = 0;
	cnt = 0;
	if (!(tetri = (t_tetri *)malloc(sizeof(*tetri))))
		return (0);
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[ret] = '\0';
		last_ret = ret;
		if (ret < 20)
			return (0);
		if (!check_format(buff))
			return (0);
		if (!check_tetri(buff))
			return (0);
		tetri = lstfill(buff, tetri);
		cnt++;
		//ft_lstpush(&tetri, tetri->next);
		if (ret == 21 && buff[20] != '\n')
			return (0);
	}
	print_tetri(tetri, cnt);
	return (last_ret == 20);
}
