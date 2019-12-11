/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_blocks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:30:28 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/11 12:06:54 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "../Libft/libft.h"

void	stack_to_heap(unsigned short *array, t_block *temp)
{
	int k;

	k = 0;
	while (k < 10)
	{
		temp->tetrino_field[k] = array[k];
		k++;
	}
}

void	tblock_conversion(unsigned short binary_mapi, unsigned short *array)
{
	int	j;

	j = 0;
	while (j < 10)
	{
		if (j == 0)
			array[j] = binary_mapi & 61440;
		else if (j == 1)
			array[j] = ((binary_mapi & 3840) << 4);
		else if (j == 2)
			array[j] = ((binary_mapi & 240) << 8);
		else if (j == 3)
			array[j] = ((binary_mapi & 15) << 12);
		else
			array[j] = 0;
		j++;
	}
}

t_block	**create_tblock(unsigned short *binary_map, unsigned int tetrino_count)
{
	int				i;
	unsigned char	id;
	t_block			*temp;
	t_block			**bit_field;
	unsigned short	array[10];

	i = 0;
	id = 'A';
	bit_field = (t_block**)malloc(sizeof(t_block) * tetrino_count + 1);
	while (binary_map[i] != 0)
	{
		temp = (t_block*)malloc(sizeof(t_block));
		temp->tetrino_field =
			(unsigned short *)malloc(sizeof(unsigned short) * 10);
		temp->id = id;
		temp->used_flag = 0;
		tblock_conversion(binary_map[i], array);
		stack_to_heap(array, temp);
		bit_field[i] = temp;
		id++;
		i++;
	}
	bit_field[i] = NULL;
	return (bit_field);
}
