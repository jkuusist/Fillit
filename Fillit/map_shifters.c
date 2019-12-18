/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shifters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:03:13 by lharvey           #+#    #+#             */
/*   Updated: 2019/12/18 14:11:07 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "fillit.h"

unsigned short	shift_left(unsigned short *bit_field, int shift_amount,
		unsigned int mask_size)
{
	int				i;
	unsigned int	l_mask;

	i = 0;
	if (shift_amount == 0)
		return (0);
	l_mask = l_shift_create(mask_size);
	while (i < (int)mask_size)
	{
		if ((bit_field[i] & l_mask) != 0)
			return (0);
		i++;
	}
	while (i >= 0)
	{
		bit_field[i] <<= 1;
		i--;
	}
	return (1);
}

unsigned short	shift_right(unsigned short *bit_field, int shift_amount,
		unsigned int mask_size)
{
	int				i;
	unsigned int	r_mask;

	i = 0;
	if (shift_amount == 0)
		return (0);
	r_mask = r_shift_create(mask_size);
	while (i < (int)mask_size)
	{
		if ((bit_field[i] & r_mask) != 0)
			return (0);
		i++;
	}
	while (i >= 0)
	{
		bit_field[i] >>= shift_amount;
		i--;
	}
	return (1);
}

unsigned short	shift_up(unsigned short *bit_field, int shift_amount)
{
	int i;
	int j;
	int temp;

	if ((bit_field[0] & 65535) != 0)
		return (0);
	i = 0;
	j = 0;
	while (i < shift_amount)
	{
		while (j < 11)
		{
			temp = bit_field[++j];
			bit_field[j - 1] = temp;
		}
		j = 0;
		i++;
	}
	i = (11 - shift_amount);
	while (i < 11)
	{
		bit_field[i] = 0;
		i++;
	}
	return (1);
}

unsigned short	shift_down(unsigned short *bit_field, int shift_amount,
		unsigned int mask_size)
{
	int i;
	int j;
	int temp;

	i = mask_size - 1;
	while (i < 10)
	{
		if ((bit_field[i] & 65535) != 0)
			return (0);
		i++;
	}
	i = 0;
	j = mask_size;
	while (i < shift_amount)
	{
		while (j >= 0)
		{
			temp = bit_field[--j];
			bit_field[j + 1] = temp;
		}
		j = mask_size;
		i++;
	}
	i = 0;
	while (i < shift_amount)
	{
		bit_field[i] = 0;
		i++;
	}
	shift_left(bit_field, (mask_size - 1), mask_size);
	return (1);
}

unsigned short	shifter(unsigned short *map_field, int shift_amount,
		unsigned int mask_size)
{
	unsigned int	rshift_amount;

	rshift_amount = 1;
	if (shift_right(map_field, rshift_amount, mask_size) == 0)
	{
		while (rshift_amount < mask_size)
		{
			if (shift_right(map_field, rshift_amount, mask_size) == 0)
				rshift_amount++;
			else
				return (1);
		}
		if (shift_down(map_field, shift_amount, mask_size) == 1)
			while (shift_left(map_field, 1, mask_size) == 1)
				;
	}
	else
		return (1);
	return (0);
}
