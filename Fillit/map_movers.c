/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_movers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:50:51 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/04 14:20:18 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "fillit.h"

unsigned short	shift_left(unsigned short *bit_field, int shift_amount)
{
	int i;

	i = -1;
	if (shift_amount == 0)
		return (0);
	while (++i < 11)
		if ((bit_field[i] & 32768) != 0)
			return (0);
	while (i >= 0)
	{
		bit_field[i] <<= 1;
		i--;
	}
	return (1);
}

unsigned short	shift_right(unsigned short *bit_field, int shift_amount)
{
	int i;

	i = -1;
	while (++i < 11)
		if ((bit_field[i] & 1) != 0)
			return (0);
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
		while (j <= 11)
		{
			temp = bit_field[++j];
			bit_field[j - 1] = temp;
		}
		j = 0;
		i++;
	}
	i = (11 - shift_amount);
	while (i <= 11)
	{
		ft_bzero(&(bit_field[i]), 1);
		i++;
	}
	return (1);
}

unsigned short	shift_down(unsigned short *bit_field, int shift_amount)
{
	int i;
	int j;
	int temp;

	if ((bit_field[10] & 65535) != 0)
		return (0);
	i = 0;
	j = 10;
	while (i < shift_amount)
	{
		while (j >= 0)
		{
			temp = bit_field[--j];
			bit_field[j + 1] = temp;
		}
		j = 10;
		i++;
	}
	i = 0;
	while (i < shift_amount)
	{
		ft_bzero(&(bit_field[i]), 1);
		i++;
	}
	return (1);
}
