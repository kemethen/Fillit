/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:20:33 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/08 18:20:35 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

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
