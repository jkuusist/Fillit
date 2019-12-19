/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:07:31 by lharvey           #+#    #+#             */
/*   Updated: 2019/12/19 15:51:06 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../Libft/libft.h"
#include <stdlib.h>

#include <stdio.h>

/*
** check_tblocks returns -1 on NULL pointer, i (index) for unused t_blocks and
** finally, returns -2 if EVERY SINGLE ONE has been stamped.
*/

static int	check_tblocks(t_block **src)
{
	int i;

	i = 0;
	if (src == NULL)
		return (-1);
	while ((src[i] != NULL) && (src[i]->used_flag == 1))
		i++;
	if ((src[i] != NULL) && (src[i]->used_flag == 0))
		return (i);
	return (-2);
}

static int	stamp_map(unsigned short *map_field, unsigned short *tetrino)
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

void		unstamp_map(unsigned short *map_field, unsigned short *tetrino)
{
	int i;

	i = 0;
	while (i < 10)
	{
		map_field[i] ^= tetrino[i];
		i++;
	}
}

unsigned short  shift_up(unsigned short *bit_field, int shift_amount)
{
    int 			i;
	int				j;
    unsigned short	temp;

	i = 0;
	j = 0;
	while ((i < shift_amount) && (bit_field[i] & 65535) == 0)
		i++;
	if ((bit_field[0] & 65535) != 0)
        return (0);
    while (j < shift_amount)
	{
		i = 0;
		while (i < 9)
		{
			temp = bit_field[++i];
			bit_field[--i] = temp;
			i++;
		}
		j++;
    }
    while (i < 9)
    {
        bit_field[i] = 0;
        i++;
    }
    return (1);
}

void		reset_tetrino(unsigned short *tetrino, unsigned int map_size)
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
	if (bit_field == NULL)
		return (NULL);
	if ((check_tblocks(bit_field)) == -2)
		return (bit_field);
	index = check_tblocks(bit_field);
	
	
	if	(stamp_map(map_field, bit_field[index]->tetrino_field))
	{
		bit_field[index]->used_flag = 1;
		if (algorithm_alpha(map_field, bit_field,
						map_size, tetrino_count) != NULL)
			return (bit_field);
		else 
			return (NULL);
	}
	else
	{
		while (shifter(bit_field[index]->tetrino_field, 1, map_size))
		{
			if	(stamp_map(map_field, bit_field[index]->tetrino_field))
			{
				bit_field[index]->used_flag = 1;
				if (algorithm_alpha(map_field, bit_field,
							map_size, tetrino_count) != NULL)
					return (bit_field);
				else
					return (NULL);
			}
		}
		if ((index != 0) && (shifter(bit_field[index]->tetrino_field, 1, map_size) == 0))
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
			if (algorithm_alpha(map_field, bit_field,
						map_size, tetrino_count) != NULL)
				return (bit_field);
			else 
				return (NULL);
		}
	}
	return (NULL);
}

t_block		**solver(unsigned short *binary_map)
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
	map_size = (unsigned int)square_root(tetrino_count * 4);
	while (map_size <= 10)	
	{
		bit_field = create_tblocks(binary_map, tetrino_count);
		ft_bzero(map_field, 20);
		if ((bit_field = algorithm_alpha(map_field, bit_field,
						map_size, tetrino_count)) != NULL)
		{
			if (map_size < 4)
				map_size = check_four(map_field, map_size);
			print_map(bit_field, map_size, tetrino_count);
			free_tblocks(bit_field);
			break ;
		}
		map_size++;
	}
	return (bit_field);
}
