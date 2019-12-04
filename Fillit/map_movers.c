/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_movers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:50:51 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/04 13:09:12 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"

void	shift_left(unsigned short *bit_field, int shift_amount)
{
	int i;

	i = 0;
	while (i <= 11)
	{
		bit_field[i] <<= shift_amount;
		i++;
	}
}

void	shift_right(unsigned short *bit_field, int shift_amount)
{
	int i;

	i = 0;
	while (i <= 11)
	{
		bit_field[i] >>= shift_amount;
		i++;
	}
}

void	shift_up(unsigned short *bit_field, int shift_amount)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	while (i < shift_amount)
	{
		while (j <= 11)
		{
			temp = bit_field[j + 1];
			bit_field[j] = temp;
			j++;
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
}

void	shift_down(unsigned short *bit_field, int shift_amount)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 10;
	while (i < shift_amount)
	{
		while (j >= 0)
		{
			temp = bit_field[j - 1];
			bit_field[j] = temp;
			j--;
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
}
