/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_blocks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:30:28 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/09 13:29:25 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "../Libft/libft.h"

//DELET THIS
#include <stdio.h>

/*
void	tblock_conversion(unsigned short *binary_map, unsigned short *array,
		int j)
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
*/
t_block	**create_tblock(unsigned short *binary_map)
{
	int				i;
	int				j;
	unsigned char	id;
	t_block			*temp;
	t_block			**bit_field;
	unsigned short	array[10];

	i = 0;
	j = 0;
	id = 'A';
	bit_field = (t_block**)malloc(sizeof(t_block) * 10);
	while (binary_map[i] != 0)
	{
		bit_field[i] = (t_block*)malloc(sizeof(t_block));
		bit_field[i]->tetrino_field = malloc(sizeof(unsigned short) * 10);
		temp = (t_block*)malloc(sizeof(t_block));
		temp->tetrino_field = (unsigned short*)malloc(sizeof(unsigned short) * 10);
		temp->id = id;
		while (j < 10)
		{
			//tblock_conversion(binary_map, array, j);

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
			j++;
		}
		temp->tetrino_field = array;
//ZERO ARRAY BEFOER NEXT LOOP
		
		printf("temp->id is: %c\n", temp->id);

		bit_field[i] = temp;

		printf("bit_field[%d]->id is: %c\n", i, bit_field[i]->id);

		ft_bzero(array, 10);
		j = 0;
		//free(temp->tetrino_field);
		free(temp);
		id++;
		i++;
	}
	return (bit_field);
}
