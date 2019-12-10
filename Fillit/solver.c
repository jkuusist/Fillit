/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:42:24 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/10 16:06:04 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** (13 x 13) is max array (169 bits) - (11 * 2 * 8  == 176)
*/

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
		if (map_field[i] & tetrino[i] == 0)
			i++;
		else 
			return (0)
	}
	i = 0;
	while (i < 10)
	{
		map_field[i] &= tetrino[i];
		i++;
	}
	return (1);
}

static int					algorithm_alpha(unsigned short *map_field, t_block **bit_field, unsigned int min_size)
{
	int i;

	i = 0;
	if (stamp_map(map_field, bit_field[i]->tetrino_field) == 1)
	{
		bit_field[i]->used_flag = 1;
		i++;
	}
	else 
	{
		if ((algorithm_alpha(map_field, bit_field[i]->tetrino_field)) == 0) 
				algorithm_alpha(map_field, bit_field[i++]->tetrino_field);
	}
	while (stamp_map(map_field, tetrino) == 0)
	{

	}
}

void						*solver(unsigned short *binary_map)
{
	unsigned int	tetrino_count;
	unsigned short	map_field[10];
	unsigned int	min_size;
	t_block			**bit_field;
	int				i;

	tetrino_count = 0;
	i = 0;
	while (binary_map[tetrino_count] != 0)
		tetrino_count++;
	while (i <= tetrino_count)
		ft_memset(map_field[i++], 0, 1);
	i = 0;
	min_size = (unsigned int)squareroot(tetrino_count * 4);
	bit_field = create_tblocks(binary_map, tetrino_count);
	while (min_size <= 10)
	{
		if (algorith_alpha(map_field, tetrino, min_size) == 1)
			break;
		min_size++;
	}
	return (0);
}
