/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_block_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:17:19 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/28 14:19:55 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "../Libft/libft.h"
#include <stdio.h>

void			write_temp(unsigned char *string, unsigned char *temp, int *nl_count)
{
	//printf("string passed to temp is: %s", *string);
	int i;

	i = 0;
	while (*string != '\0' && *nl_count < 6)
	{
		if (*string == '\n')
			(*nl_count)++;
		//printf("nl_count is: %d current char is: %c\n", *nl_count, **string);
		temp[i++] = *string;
		string++;
	}
}

int				get_block_count(unsigned char *string)
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

unsigned int	*create_block_array(unsigned char *string)
{
	int				i;
	int				block_count;
	int				nl_count;
	unsigned char	*temp;
	unsigned int	*array;

	i = 0;
	block_count = get_block_count(string);
	nl_count = 0;
	array = (unsigned int*)malloc(sizeof(unsigned int*) * 27);
	while (i < block_count)
	{
		temp = (unsigned char *)malloc((sizeof(unsigned char*)) * 21);
		write_temp(string, temp, &nl_count);
		string++;

		printf("temp is: %s", temp);

		array[i] = str_to_bin(temp);

		printf("array[i] is: %d\n", array[i]);

		ft_strdel((char**)&temp);
		nl_count = 0;
		i++;
	}
	array[i] = 0;
	return (array);
}
