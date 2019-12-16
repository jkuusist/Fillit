/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:42:24 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/16 17:09:54 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../Libft/libft.h"
#include <stdlib.h>

/*
** check_tblocks returns -1 on NULL pointer, i (index) for unused t_blocks and
** finally, returns -2 if EVERY SINGLE ONE has been stamped.
*/

static int					check_tblocks(t_block **src)
{
	int i;

	i = 0;
	if (*src == NULL)
		return (-1);
	while ((src[i] != NULL) && (src[i]->used_flag == 1))
		i++;
	if ((src[i] != NULL) && (src[i]->used_flag == 0))
		return (i);
	return (-2);
}

static int 					stamp_map(unsigned short *map_field, unsigned short *tetrino)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if ((map_field[i] & tetrino[i]) == 0)
			i++;
		else 
			return (0);
	}
	i = 0;
	while (i < 10)
	{
		map_field[i] |= tetrino[i];
		i++;
	}
	return (1);
}

void						unstamp_map(unsigned short *map_field, unsigned short *tetrino)
{
	int i;

	i = 0;
	while (i < 10)
	{
		map_field[i] ^= tetrino[i];
		i++;
	}
}

t_block						**algorithm_alpha(unsigned short *map_field, t_block **bit_field, unsigned int map_size, unsigned int tetrino_count)
{
	unsigned int	i;
	t_block			**bit_field_copy;

	i = 0;
	bit_field_copy = copy_tblocks(bit_field);
//	TRY ALL POSSIBLE TETRINO BOYS FOR THIS PLACE (loop)
	while (check_tblocks(bit_field_copy) >= 0)
	{
		while ((i < tetrino_count) && (stamp_map(map_field, bit_field_copy[i]->tetrino_field) == 1))
		{
			bit_field_copy[i]->used_flag = 1;
			i++;
		}
		while ((i < tetrino_count) && (stamp_map(map_field, bit_field_copy[i]->tetrino_field) == 0))
		{
			if ((shift_right(bit_field_copy[i]->tetrino_field, 1, map_size)) == 0)
			{
				if (shift_down(bit_field_copy[i]->tetrino_field, 1, map_size) == 0)
				{
					if ((bit_field_copy[i] != NULL) && (bit_field_copy[i]->used_flag == 0))
					{
						i--;
						unstamp_map(map_field, bit_field_copy[i]->tetrino_field);	
						bit_field_copy[i]->used_flag = 0;
					}
				}
			}
		}
		if (check_tblocks(bit_field_copy) != -2)
			algorithm_alpha(map_field, bit_field_copy, map_size, tetrino_count);
		if (bit_field_copy[i] == NULL)
			i = 0;
		else
			i++;
	}
	if (check_tblocks(bit_field_copy) == -2)
	{
		free_tblocks(bit_field);
		bit_field = bit_field_copy;
		return (bit_field);
	}
	free_tblocks(bit_field_copy);
	return (NULL);
}

t_block						**solver(unsigned short *binary_map)
{
	unsigned int	tetrino_count;
	unsigned short	map_field[10];
	unsigned int	map_size;
	t_block			**bit_field;
	unsigned int	i;

	tetrino_count = 0;
	i = 0;
	while (binary_map[tetrino_count] != 0)
		tetrino_count++;
	ft_bzero(map_field, 10);
	map_size = (unsigned int)square_root(tetrino_count * 4);
	bit_field = create_tblocks(binary_map, tetrino_count);
	while (map_size <= 10)
	{
		if ((bit_field = algorithm_alpha(map_field, bit_field, map_size, tetrino_count)) != NULL)
		{
			if (map_size < 4)
				map_size = check_four(map_field, map_size);
			print_map(bit_field, map_size, tetrino_count);
			free_tblocks(bit_field);
			break;
		}
		map_size++;
	}
	return (bit_field);
}
