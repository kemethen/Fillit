/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:49:28 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/07 23:28:59 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

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
	char			l;
	struct s_tetri	*prev;
	struct s_tetri	*next;
}				t_tetri;

void			ft_putstr(const char *s);
short			check_file(int fd);
char			*filltab(char *tab, char *buff, short rank);
t_tetri			*lstnext(t_tetri **tetri, t_tetri *tmp);
t_tetri			*lstfill(char *buff, t_tetri **tetri);
void			tocorner(t_tetri *t);
void			fillit(t_tetri *tetri);
char			*ft_strndup(char *s1, int n);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strnew(size_t size);
char			*ft_strdup(const char *s1);
void			ft_putchar(char c);
void			ft_putnbr(int n);
size_t			ft_strlen(const char *str);
short			offset_x(t_tetri *t);
short			offset_y(t_tetri *t);
int             ft_lstlen(t_tetri **list);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_displaytab(char **tab);

#endif
