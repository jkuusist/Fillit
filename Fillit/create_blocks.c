/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_blocks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:30:28 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/05 13:36:54 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

t_block	*create_block(unsigned short *binary_map)
{
	int				i;
	int				j;
	unsigned char	id;
	t_block			temp;
	t_block			*bit_field;

	i = 0;
	j = 0;
	id = 'A';
	bit_field = malloc(sizeof(t_block) * 10);
	while (binary_map[i] != 0)
	{
		temp.id = id;
		temp.tetrino_field = malloc(sizeof(unsigned short) * 10);
		while (j < 10)
		{
			if (j == 0)
				bit_field[j].tetrino_field[j] = (binary_map[j] | 61440);
			else if (j == 1)
				bit_field[j].tetrino_field[j] = (binary_map[j] | 3840);
			else if (j == 2)
				bit_field[j].tetrino_field[j] = (binary_map[j] | 240);
			else if (j == 3)
				bit_field[j].tetrino_field[j] = (binary_map[j] | 15);
			else
				bit_field[j].tetrino_field[j] = 0;
			j++;
		}
		bit_field[i] = temp;
		id++;
		i++;
	}
	return (bit_field);
}
