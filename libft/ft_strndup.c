/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:26:09 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/25 13:12:11 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s1, int n)
{
	char	*s2;

	s2 = ft_strnew((size_t)n);
	return (s2 = ft_strncpy(s2, (const char *)s1, n));
}
