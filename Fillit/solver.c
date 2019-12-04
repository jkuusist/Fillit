/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:42:24 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/04 10:56:45 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"

/*
** (13 x 13) is max array (169 bits) - (11 * 2 * 8  == 176)
*/

static unsigned short check_lowestfield(unsigned short *bit_field)
{
	if ((bit_field[10] & 65535) != 0)
		return (0);
	return (1);
}

static unsigned short check_highestfield(unsigned short *bit_field)
{
	if ((bit_field[0] & 65535) != 0)
		return (0);
	return (1);
}

static unsigned short check_rightfield(unsigned short *bit_field)
{
	int i;

	i = 0;
	while (i < 11)
		if ((bit_field[i] & 1) != 0)
			return (0);
	return (1);
}

static unsigned short check_leftfield(unsigned short *bit_field)
{
	int i;

	i = 0;
	while (i < 11)
		if ((bit_field[i] & 32768) != 0)
			return (0);
	return (1);
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
	int i;
	unsigned short bit_field[10];
//	int map_size;

	while (i <= 10)
		ft_memset(bit_field[i++], 0, 1);
//	i = 0;
//	while (binary_map[i] != 0)
//		i++;
//	map_size = squaireroot(i * 4);
}
