/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_block_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:17:19 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/25 17:04:08 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned char	**create_block_array(char *string, int num_blocks)
{
	int				i;
	int				j;
	int				nl_count;
	unsigned char	**array;

	i = 0;
	j = 0;
	nl_count = 0;
	array = (unsigned char**)malloc(sizeof(unsigned char**) * 26);
	while (i < num_blocks)
	{
		array[i] = (unsigned char *)malloc((sizeof(unsigned char*)) * 21);
		while (*string != '\0' && nl_count < 5)
		{
			if (*string == '\n')
				nl_count++;
			array[i][j++] = *string;
			string++;
		}
		array[i++][j - 1] = '\0';
		j = 0;
		nl_count = 0;
	}
	array[i] = 0;
	return (array);
}
