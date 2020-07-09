/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:55:57 by lharvey           #+#    #+#             */
/*   Updated: 2019/10/28 12:17:09 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*s1;

	i = 0;
	ch = (unsigned char)c;
	s1 = (unsigned char*)s;
	while (i < n)
	{
		if (s1[i] == ch)
		{
			return (s1 + i);
		}
		i++;
	}
	return (0);
}
