/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:17:00 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/26 15:22:05 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

unsigned int		binary_atoi(const unsigned char *str, int len)
{
	unsigned long long	binary_value;
	unsigned long long	result;

	binary_value = 1;
	result = 0;
	len--;
	while ((str[len] == '0' || str[len] == '1') && len >= 0)
	{
		if (str[len] == '1')
			result += binary_value;
		binary_value *= 2;
		len--;
	}
	return (result);
}

unsigned int		str_to_bin(unsigned char *block)
{
	int				i;
	int				length;
	unsigned char	*binstr;
	unsigned int	result;

	i = 0;
	length = 0;
	binstr = (unsigned char *)malloc(sizeof(unsigned char) * 16);
	while (block[i] != '\0')
	{
		if (block[i] == '#')
		{
			ft_strcat((char*)binstr, "1");
			length++;
		}
		if (block[i] == '.')
		{
			ft_strcat((char*)binstr, "0");
			length++;
		}
		i++;
	}
	result = binary_atoi(binstr, length);
	return (result);
}
