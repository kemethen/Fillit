/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:37:18 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/03 15:58:40 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check(char *buff, int fd, int cnt, int pnt, int lnk)
{
	int		ret;
	int		i;
	int		cnt;
	int		pnt;
	int		lnk;

	while (((ret = read(fd, buff, 21)) > 0))
	{
		buff[20] = '\0';
		i = 0;
		cnt = 0;
		pnt = 0;
		lnk = 0;
		while (buff[i] == '#' || buff[i] == '.' || buff[i] == '\n')
		{
			if (buff[i] == '#')
				cnt++;
			if (buff[i] == '.')
				pnt++;
			if ((buff[i] == '#' && buff[i + 1] == '#') ||
				(buff[i] == '#' && buff[i + 5] == '#'))
				lnk++;
			i++;
		}
		if (buff[i] != '\0' || cnt != 4 || pnt != 12 || lnk < 3)
			return (-1);
	}
	return (0);
}
