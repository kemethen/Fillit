/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:49:28 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/13 12:31:48 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_var
{
	int		x;
	int		y;
	int		j;
	char	ltr;
}				t_var;

typedef struct	s_case
{
	int		x;
	int		y;
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

int				check_file(int fd, t_var *v);
t_tetri			*lstfill(char *buff, t_tetri **tetri);
void			tocorner(t_tetri *t);
char			**fillit(t_tetri *tetri, t_var *v, char **map);
int				offset_x(t_tetri *t);
int				offset_y(t_tetri *t);
void			changecoord(t_var *v, char sign, t_tetri **t);
void			changecoord2(t_var *v, t_tetri *t);
char			**remake(char **map, t_var *v, t_tetri **t);
char			**recreatemap(char **map);
void			recoord(t_tetri *t, int x, int y, char sign);
int				lastline(t_tetri *t, t_var *v);
int				tetri_offmap(t_var *v, t_tetri *t);
int				last_tetri_offmap(t_var *v, t_tetri *t);
int				last_column(t_var *v, t_tetri *t);
int				placeable(t_var *v, t_tetri *t, char **map);
char			**placetetri(char **map, t_tetri **t, t_var *v);
char			**setpoint(char **map, t_tetri *t);
char			**setletter(char **map, t_tetri *t, char letter, t_var *v);
void			fillitfree(char *buff, t_tetri *tetri, char **map, t_var *v);

#endif
