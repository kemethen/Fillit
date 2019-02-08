/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:52:43 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/08 17:55:05 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

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
		struct s_tetri *prev;
}				t_tetri;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strnew(size_t size);
void			ft_putchar(char c);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putstr(const char *s);
void			ft_displaytab(char **tab);
char			*ft_strndup(char *s1, int n);

#endif
