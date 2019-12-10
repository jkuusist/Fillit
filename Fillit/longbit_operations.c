/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longbit_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:38:45 by lharvey           #+#    #+#             */
/*   Updated: 2019/12/10 12:39:49 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** These functions are used when a series of shorts/variables are considered
** as part of one contiguous set of bytes. 
*/

static unsigned short		check_bit(unsigned short *bit_field,
		unsigned short bit_nb)
{
	if (bit_field[bit_nb / 16] & (1 << (bit_nb % 16)))
		return (1);
	else
		return (0);
}

static void					set_bit(unsigned short *bit_field,
		unsigned short bit_nb)
{
	bit_field[bit_nb / 16] |= (1 << (bit_nb % 16));
}

static void					clear_bit(unsigned short *bit_field,
		unsigned short bit_nb)
{
	bit_field[bit_nb / 16] &= ~(1 << (bit_nb % 16));
}
