/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:42:24 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/02 17:49:07 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** (13 x 13) is max array (169 bits) - (11 * 2 * 8  == 176)
*/

void	*solver(unsigned short *binary_map)
{
//	int i;
//	int map_size;
	unsigned short bit_field[10];
	/* FREE THE BITFIELD OF JUNK I BEG YE */
	while (i <= 10)
		ft_memset(bit_field[i++], 0, ((sizeof(unsigned short)) * 8))
//	i = 0;
//	while (binary_map[i] != 0)
//		i++;
//	map_size = squaireroot(i * 4);



}
