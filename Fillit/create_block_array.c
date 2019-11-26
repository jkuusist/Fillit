/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_block_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:17:19 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/26 17:32:35 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "../Libft/libft.h"

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
	array = (unsigned int*)malloc(sizeof(unsigned int*) * 26);
	while (i < num_blocks)
	{
		temp = (unsigned char *)malloc((sizeof(unsigned char*)) * 21);
		while (*string != '\0' && nl_count < 5)
		{
			if (*string == '\n')
				nl_count++;
			*temp++ = *string++;
		}
		array[i++] = str_to_bin(temp);
		ft_strdel((char**)&temp);
		j = 0;
		nl_count = 0;
	}
	return (array);
}
