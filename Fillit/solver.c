/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:07:31 by lharvey           #+#    #+#             */
/*   Updated: 2019/12/26 15:15:19 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../Libft/libft.h"
#include <stdlib.h>

#include <stdio.h>

//	int global_int = 0;

/*
** check_tblocks returns -1 on NULL pointer, i (index) for unused t_blocks and
** finally, returns -2 if EVERY SINGLE ONE has been stamped.
*/

static void	reset_tetrino(unsigned short *tetrino, unsigned int map_size)
{
	while (shift_left(tetrino, 1, map_size) == 1)
		;
	while (shift_up(tetrino, 1) == 1)
		;
}

t_block		**algorithm_alpha(unsigned short *map_field, t_block **bit_field,
		unsigned int map_size, unsigned int tetrino_count)
{
	int		index;


//	printf("global_int is now %d\n", global_int);
//	global_int++;

	if (bit_field == NULL)
		return (NULL);
	index = check_tblocks(bit_field);
	if (index == -2)
		return (bit_field);
	while (index >= 0)
	{
		if (stamp_map(map_field, bit_field[index]->tetrino_field))
		{
			bit_field[index]->used_flag = 1;
			index = check_tblocks(bit_field);
		}
		else
			if (shifter(bit_field[index]->tetrino_field, 1, map_size) == 0)
				break ;
	}
	if (index >= 0)
	{
		reset_tetrino(bit_field[index]->tetrino_field, map_size);
		index--;
		while (index >= 0)
		{
			unstamp_map(map_field, bit_field[index]->tetrino_field);
			bit_field[index]->used_flag = 0;
			if (shifter(bit_field[index]->tetrino_field, 1, map_size) == 0)
				index--;
			else
				break ;
		}
		if (index == -1)
			return (NULL);
	}
	return (algorithm_alpha(map_field, bit_field,
				map_size, tetrino_count));
}

t_block		**solver(unsigned short *binary_map)
{
	unsigned int	tetrino_count;
	unsigned short	map_field[14];
	unsigned int	map_size;
	t_block			**bit_field;
	t_block			**temp_field;

	tetrino_count = 0;
	while (binary_map[tetrino_count] != 0)
		tetrino_count++;
	map_size = (unsigned int)square_root(tetrino_count * 4);
	while (map_size <= 14)
	{
//		map_field = (unsigned short*)malloc(sizeof(unsigned short) * map_size);
		printf("map_size is now %d\n", map_size);

		bit_field = create_tblocks(binary_map, tetrino_count);
		temp_field = bit_field;
		ft_bzero(map_field, (14 * 2));
		if ((bit_field = algorithm_alpha(map_field, bit_field,
						map_size, tetrino_count)) != NULL)
		{
			if (map_size < 4)
				map_size = check_four(map_field, map_size);
			print_map(bit_field, map_size, tetrino_count);
			break ;
		}
		map_size++;
		free_tblocks(temp_field);
	}
	return (bit_field);
}
