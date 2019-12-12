/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:42:24 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/12 14:54:00 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../Libft/libft.h"
#include <stdlib.h>

/*
** (13 x 13) is max array (169 bits) - (11 * 2 * 8  == 176)
*/

int							check_tblocks(t_block **src)
{
	int i;

	i = 0;
	if (src[i] == NULL)
		return (0);
	while ((src[i] != NULL) && (src[i]->used_flag == 1))
		i++;
	if (src[i]->used_flag == 0)
		return (i);
	return (0);
}


t_block						**copy_tblocks(t_block **src)
{
	int		i;
	int		j;
	t_block **copy;

	i = 0;
	j = 0;
	while (src[i] != 0)
		i++;
	copy = (t_block **)malloc(sizeof(t_block) * i);
	i = 0;
	while(src[i] != 0)
	{
		copy[i] = (t_block*)malloc(sizeof(t_block));
		copy[i]->tetrino_field = (unsigned short *)malloc(sizeof(unsigned short) * 10);
		copy[i]->id = src[i]->id;
		copy[i]->used_flag = src[i]->used_flag;
		while (j < 10)
		{
			copy[i]->tetrino_field[j] = src[i]->tetrino_field[j];
			j++;
		}
		i++;
	}
	return (copy);
}

void						free_tblocks(t_block **array)
{
	int i;

	i = 0;
	while (array[i] != 0)
	{
		free(array[i]->tetrino_field);
		free(array[i]);
		i++;
	}
	free(array);
}

static unsigned long long	squareroot(unsigned long long x)
{
	unsigned long long start;
	unsigned long long end;
	unsigned long long result;
	unsigned long long mid;

	if (!x || x > 18446744073709551615U)
		return (0);
	if (x == 0 || x == 1)
		return (x);
	start = 1;
	end = x;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid * mid == x)
			return (mid);
		if (mid * mid < x)
		{
			start = mid + 1;
			result = mid;
		}
		else
			end = mid - 1;
	}
	return (result);
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

t_block						**algorithm_alpha(unsigned short *map_field, t_block **bit_field, unsigned int map_size)
{
	int 	i;
	t_block	**bit_field_copy;

	i = 0;
	bit_field_copy = copy_tblocks(bit_field);
//	TRY ALL POSSIBLE TETRINO BOYS FOR THIS PLACE (loop)
	while (check_tblocks(bit_field_copy) != 0)
	{
		while (stamp_map(map_field, bit_field_copy[i]->tetrino_field) == 1)
		{
			bit_field_copy[i]->used_flag = 1;
			i++;
			while (stamp_map(map_field, bit_field_copy[i]->tetrino_field) == 0)
			{
				while (shift_right(bit_field_copy[i]->tetrino_field, 1, map_size) == 0)
				{
					while (shift_down(bit_field_copy[i]->tetrino_field, 1, map_size) == 1)
					if (shift_down(bit_field_copy[i]->tetrino_field, 1, map_size) == 0)
						if (bit_field_copy[i]->used_flag == 0 && bit_field_copy[i] != NULL)
						{
							i--;
							unstamp_map(map_field, bit_field_copy[i]->tetrino_field);	
							bit_field_copy[i]->used_flag = 0;
						}
				}
			}
		}				
		algorithm_alpha(map_field, bit_field, map_size);
		if (bit_field_copy[i] == NULL)
			i = 0;
		else
			i++;
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
	while (i <= tetrino_count)
		ft_memset(map_field[i++], 0, 1);
	i = 0;
	map_size = (unsigned int)squareroot(tetrino_count * 4);
	bit_field = create_tblocks(binary_map, tetrino_count);
	while (map_size <= 10)
	{
		if (algorithm_alpha(map_field, bit_field, map_size) == 1)
			break;
		map_size++;
	}
	return (bit_field);
}
