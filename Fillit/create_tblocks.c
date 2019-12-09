/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_blocks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:30:28 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/09 14:20:54 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "../Libft/libft.h"

//DELET THIS
#include <stdio.h>

void	stack_to_heap(unsigned short *array, t_block *temp)
{
	int i;

	i = 0;
	while (i <= 9)
	{
		temp->tetrino_field[i] = array[i];
		i++;
	}
}

void	tblock_conversion(unsigned short *binary_map, unsigned short *array)
{
	int	j;

	j = 0;
	while (j < 10)
	{
		if (j == 0)
			array[j] = (binary_map[j] & 61440);
		else if (j == 1)
			array[j] = (binary_map[j] & 3840);
		else if (j == 2)
			array[j] = (binary_map[j] & 240);
		else if (j == 3)
			array[j] = (binary_map[j] & 15);
		else
			array[j] = 0;
	}
}

t_block	**create_tblock(unsigned short *binary_map)
{
	int				i;
	unsigned char	id;
	t_block			*temp;
	t_block			**bit_field;
	unsigned short	array[10];

	i = 0;
	id = 'A';
	bit_field = (t_block**)malloc(sizeof(t_block) * 10);
	while (binary_map[i] != 0)
	{
		temp = (t_block*)malloc(sizeof(t_block));
		temp->tetrino_field = (unsigned short *)malloc(sizeof(unsigned short) * 10);
		temp->id = id;
		tblock_conversion(binary_map, array);
		stack_to_heap(array, temp);
//DELETE THE PRINTF EXTRAVAGANZA 
		
		printf("temp->id is: %c\n", temp->id);
		bit_field[i] = temp;
		printf("bit_field[%d]->id is: %c\n", i, bit_field[i]->id);

		ft_bzero(array, 10);
		id++;
		i++;
	}
	return (bit_field);
}
