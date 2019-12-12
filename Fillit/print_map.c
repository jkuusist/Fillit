/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:45:18 by lharvey           #+#    #+#             */
/*   Updated: 2019/12/12 14:50:33 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../Libft/libft.h"

static unsigned short		check_bit(unsigned short *bit_field,
		unsigned int bit_nb)
{
	if (bit_field[bit_nb] & (32768 >> (bit_nb)))
		return (1);
	else
		return (0);
}

void	print_map(t_block **bit_field, unsigned int map_size, unsigned int num_tetrinos)
{
	char	char_map[(map_size*map_size) + map_size];
	unsigned int i;
	unsigned int checked_bits;
	unsigned int checked_rows;

	i = 0;
	checked_bits = 0;
	checked_rows = 0;
	while (i <= num_tetrinos)
		ft_memset((&(char_map[i++])), '.', 1);
	i = 0;
	while (bit_field[i] != NULL)
	{
		while (checked_rows <= map_size)
		{
			if (checked_bits / 16 == 0)
			{
				checked_rows++;
				checked_bits = 0;
			}
			if (checked_bits / map_size == 0)
				char_map[i++] = '\n';
			if (check_bit(&(bit_field[i]->tetrino_field[checked_rows]), checked_bits++))
				char_map[i] = bit_field[i]->id; 
		}
		checked_rows = 0;
		i++;
	}
	ft_putstr(char_map);
}
