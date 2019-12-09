/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:42:24 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/09 15:39:53 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** (13 x 13) is max array (169 bits) - (11 * 2 * 8  == 176)
*/

unsigned long long	squareroot(unsigned long long x)
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

static unsigned short	check_bit(unsigned short *bit_field,
		unsigned short bit_nb)
{
	if (bit_field[bit_nb / 16] & (1 << (bit_nb % 16)))
		return (1);
	else
		return (0);
}

static void				set_bit(unsigned short *bit_field,
		unsigned short bit_nb)
{
	bit_field[bit_nb / 16] |= (1 << (bit_nb % 16));
}

static void				clear_bit(unsigned short *bit_field,
		unsigned short bit_nb)
{
	bit_field[bit_nb / 16] &= ~(1 << (bit_nb % 16));
}

void					*solver(unsigned short *binary_map)
{
	unsigned int	i;
	unsigned short	map_field[10];
	unsigned int	min_size;
	t_block			*bit_field;

	while (i <= 10)
		ft_memset(map_field[i++], 0, 1);
	i = 0;
	while (binary_map[i] != 0)
		i++;
	min_size = (unsigned int)squareroot(i * 4);
	ft_putnbr((int)min_size);
	bit_field = create_tblocks(binary_map);
	while (min_size <= 16)
	{
		
	}
	return (0);
}
