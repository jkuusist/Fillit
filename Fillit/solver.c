/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:42:24 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/05 10:41:32 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"

/*
** (13 x 13) is max array (169 bits) - (11 * 2 * 8  == 176)
*/

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
	unsigned int i;
	unsigned short bit_field[10];
	unsigned int min_size;

	while (i <= 10)
		ft_memset(bit_field[i++], 0, 1);
	i = 0;
	while (binary_map[i] != 0)
		i++;
	min_size = (unsigned int)squareroot(i * 4);
	ft_putnbr((int)min_size);
	// PUT THE HECKIN TETRINO FROM MAP TO FIELD
	
}
