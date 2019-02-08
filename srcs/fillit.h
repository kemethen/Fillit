/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:49:28 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/08 18:21:55 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_case
{
	short x;
	short y;
}				t_case;
typedef struct	s_tetri
{
	t_case			a;
	t_case			b;
	t_case			c;
	t_case			d;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}				t_tetri;

short			check_file(int fd);
t_tetri			*lstfill(char *buff, t_tetri **tetri);
void			tocorner(t_tetri *t);
void			fillit(t_tetri *tetri);
short			offset_x(t_tetri *t);
short			offset_y(t_tetri *t);

#endif
