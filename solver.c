/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:07:31 by lharvey           #+#    #+#             */
/*   Updated: 2020/01/07 13:50:34 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "Libft/libft.h"
#include <stdlib.h>

/*
** check_tblocks returns -1 on NULL pointer, i (index) for unused t_blocks and
** finally, returns -2 if EVERY SINGLE ONE has been stamped.
*/

void		reset_tetrino(unsigned short *tetrino, unsigned int map_size)
{
	while (shift_left(tetrino, 1, map_size) == 1)
		;
	while (shift_up(tetrino, 1) == 1)
		;
}

t_block		**algorithm_alpha(unsigned short *map_field, t_block **bit_field,
		unsigned int map_size)
{
	int		index;

	while ((index = check_tblocks(bit_field)) != -2)
	{
		if (bit_field == NULL)
			return (NULL);
		while (index >= 0)
		{
			if (stamp_map(map_field, bit_field[index]->tetrino_field))
			{
				bit_field[index]->used_flag = 1;
				index = check_tblocks(bit_field);
			}
			else if (shifter(bit_field[index]->tetrino_field, 1, map_size) == 0)
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
				{
					reset_tetrino(bit_field[index]->tetrino_field, map_size);
					index--;
				}
				else
					break ;
			}
			if (index == -1)
				return (NULL);
		}
	}
	return (bit_field);
}

t_block			**solver(unsigned short *binary_map)
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
		bit_field = create_tblocks(binary_map, tetrino_count);
		temp_field = bit_field;
		ft_bzero(map_field, (14 * 2));
		if ((bit_field = algorithm_alpha(map_field, bit_field,
						map_size)) != NULL)
		{
			if (map_size < 4)
				map_size = check_four(map_field, map_size);
			print_map(bit_field, map_size, tetrino_count);
			free_tblocks(temp_field);
			break ;
		}
		map_size++;
		free_tblocks(temp_field);
	}
	return (bit_field);
}
