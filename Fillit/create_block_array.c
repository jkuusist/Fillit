/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_block_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:17:19 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/29 10:21:17 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "../Libft/libft.h"

static void		write_temp(unsigned char **string, unsigned char *temp,
				int *nl_count)
{
	int i;

	i = 0;
	if (**string == '\n')
		(*string)++;
	while (**string != '\0' && *nl_count < 5)
	{
		if (**string == '\n')
			(*nl_count)++;
		temp[i++] = **string;
		(*string)++;
	}
}

static int		get_block_count(unsigned char *string)
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

unsigned short	*create_block_array(unsigned char *string)
{
	int				i;
	int				block_count;
	int				nl_count;
	unsigned char	*temp;
	unsigned short	*array;

	i = 0;
	block_count = get_block_count(string);
	nl_count = 0;
	array = (unsigned short*)malloc(sizeof(unsigned short*) * 27);
	while (i < block_count)
	{
		temp = (unsigned char *)malloc((sizeof(unsigned char*)) * 20);
		write_temp(&string, temp, &nl_count);
		array[i] = str_to_bin(temp);
		ft_strdel((char**)&temp);
		nl_count = 0;
		i++;
	}
	array[i] = 0;
	return (array);
}
