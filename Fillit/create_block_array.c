/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_block_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:17:19 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/27 12:43:41 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "../Libft/libft.h"

void			write_temp(char **string, unsigned char *temp, int *nl_count)
{
	int i;

	i = 0;
	while (**string != '\0' && *nl_count < 6)
	{
		if (**string == '\n')
			nl_count++;
		temp[i++] = **string;
		(*string)++;
	}
}

unsigned int	*create_block_array(char *string, int num_blocks)
{
	int				i;
	int				j;
	int				nl_count;
	unsigned char	*temp;
	unsigned int	*array;

	i = 0;
	j = 0;
	nl_count = 0;
	array = (unsigned int*)malloc(sizeof(unsigned int*) * 27);
	while (i < num_blocks)
	{
		temp = (unsigned char *)malloc((sizeof(unsigned char*)) * 21);
		write_temp(&string, temp, &nl_count);
		string++;
		array[i] = str_to_bin(temp);
		ft_strdel((char**)&temp);
		j = 0;
		nl_count = 0;
		i++;
	}
	array[i] = 0;
	return (array);
}
