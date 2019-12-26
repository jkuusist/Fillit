/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_block_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:17:19 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/20 14:48:12 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "../Libft/libft.h"

static unsigned short		binary_atoi(const unsigned char *str, int len)
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

static unsigned short		str_to_bin(unsigned char *block)
{
	int				i;
	int				length;
	unsigned char	*binstr;
	unsigned short	result;

	i = 0;
	length = 0;
	binstr = (unsigned char *)malloc(sizeof(unsigned char) * 17);
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
	free(binstr);
	return (result);
}

static void					write_temp(unsigned char **string,
		unsigned char *temp)
{
	int i;
	int nl_count;

	i = 0;
	nl_count = 0;
	if (**string == '\n')
		(*string)++;
	while (**string != '\0' && nl_count < 5)
	{
		if (**string == '\n')
			nl_count++;
		temp[i] = **string;
		i++;
		(*string)++;
	}
	return ;
}

static int					get_block_count(unsigned char *string)
{
	int	i;
	int	block_count;

	i = 0;
	block_count = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			block_count++;
		i++;
	}
	if (block_count != 0)
		block_count++;
	return (block_count / 5);
}

unsigned short				*create_block_array(unsigned char *string)
{
	int				i;
	int				block_count;
	unsigned char	*temp;
	unsigned short	*array;

	i = 0;
	block_count = get_block_count(string);
	array = (unsigned short *)malloc(sizeof(unsigned short) * (block_count + 1));
	while (i < block_count)
	{
		temp = (unsigned char *)malloc((sizeof(unsigned char)) * 20);
		write_temp(&string, temp);
		array[i] = str_to_bin(temp);
		ft_strdel((char**)&temp);
		i++;
	}
	array[i] = 0;
	return (array);
}
