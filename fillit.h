/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:49:28 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/11 15:50:49 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_case
{
	short x;
	short y;
}				t_case;
typedef struct	s_tetri
{
	t_case a;
	t_case b;
	t_case c;
	t_case d;
	struct s_tetri *next;
}				t_tetri;

void	ft_putstr(const char *s);
int		check(char *buff, int fd);
short	check_file(int fd, char *buff);
char	*filltab(char *tab, char *buff, short rank);
t_tetri	*lstfill(char *buff, t_tetri *tetri);
void	ft_lstpush(t_tetri **alst, t_tetri *new);
void	print_tetri(t_tetri *tetri, short cnt);
char	*ft_strdup(const char *s1);
void	ft_putchar(char c);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *str);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_displaytab(const char **tab);

#endif
