/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:37:18 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/04 14:59:08 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		links(char *buff, int i)
{
	int		lnk;

	lnk = 0;
	if (buff[i] == '#' && buff[i + 1] == '#')
		lnk++;
	if (buff[i] == '#' && buff[i + 5] == '#')
		lnk++;
	return (lnk);
}

int		check(char *buff, int fd)
{
	int		ret;
	int		i;
	int		cnt;
	int		pnt;
	int		lnk;

	while (((ret = read(fd, buff, 21)) > 0))
	{
		i = 0;
		cnt = 0;
		pnt = 0;
		lnk = 0;
		while (buff[i] == '#' || buff[i] == '.' || buff[i] == '\n')
		{
			if (buff[0] == '\n' || (buff[i] == '\n' && buff[i + 1] == '\n'))
				return (-1);
			if (buff[i] == '#')
				cnt++;
			if (buff[i] == '.')
				pnt++;
			lnk = lnk + links(buff, i);
			i++;
		}
		if (buff[i] != '\0' || cnt != 4 || pnt != 12 || lnk < 3 || i == 0)
			return (-1);
		bzero(buff, 21);
	}
	if (i == 0)
		return (-1);
	return (0);
}
