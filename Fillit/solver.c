/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:42:24 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/03 13:02:38 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"

/*
** (13 x 13) is max array (169 bits) - (11 * 2 * 8  == 176)
*/

static unsigned short	check_bit(unsigned short *bit_field,
		unsigned short bit_nb)
{
	unsigned short index;
	unsigned short position;
	unsigned short flag;

	index = bit_nb / 16;
	position = bit_nb % 16;
	flag = (1 << position);
	if (bit_field[index] & flag)
		return (1);
	else
		return (0);
}

static void				set_bit(unsigned short *bit_field,
		unsigned short bit_nb)
{
	unsigned short index;
	unsigned short position;
	unsigned short flag;

	index = bit_nb / 16;
	position = bit_nb % 16;
	flag = (1 << position);
	bit_field[index] |= flag;
}

void					*solver(unsigned short *binary_map)
{
	int i;
//	int map_size;
	unsigned short bit_field[10];

	while (i <= 10)
		ft_memset(bit_field[i++], 0, 1);
//	i = 0;
//	while (binary_map[i] != 0)
//		i++;
//	map_size = squaireroot(i * 4);
}
