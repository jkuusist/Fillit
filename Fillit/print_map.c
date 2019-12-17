/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:45:18 by lharvey           #+#    #+#             */
/*   Updated: 2019/12/17 11:50:25 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../Libft/libft.h"

#include <stdio.h>

static unsigned short		check_bit(unsigned short tetrino_field,
		unsigned int bit_nb)
{
	if (tetrino_field & (32768 >> bit_nb))
		return (1);
	else
		return (0);
}

unsigned int				check_four(unsigned short *map_field, unsigned int map_size)
{
	unsigned int	i;
	
	i = 0;
	while ((map_size < 5) && (i < 5))
	{
		if (check_bit(map_field[i], map_size) == 1)
			map_size++;
		i++;
	}
	while ((map_size < 5) && (map_field[map_size] != 0))
		map_size++;
	return (map_size);
}

void						print_map(t_block **bit_field,
		unsigned int map_size, unsigned int num_tetrinos)
{
	char			char_map[(map_size * 2) + map_size];
	unsigned int	i;
	unsigned int	checked_bits;
	unsigned int	checked_rows;


	printf("map size passed into printer is %d\n", map_size);

	i = 0;
	checked_bits = 0;
	checked_rows = 0;
	while (i <= (map_size * 2 + map_size))
		ft_memset((&(char_map[i++])), '.', 1);
	i = 0;
	printf("i is now %d\n", i);
	while ((bit_field[i] != NULL) || (i < num_tetrinos))
	{
		//printf();

		while (checked_rows <= map_size)
		{
		/*	for (int k = 0; k < 10; k++)
				printf("bit_field[%d]->tetrino_field[%d] is %d\n", i, k, bit_field[i]->tetrino_field[k]);
		*/

			if ((i < num_tetrinos) && (check_bit(bit_field[i]->tetrino_field[checked_rows],
						checked_bits)))
			{
				char_map[i] = bit_field[i]->id;
				checked_bits++;
			}
			if (/* (checked_bits != 0) && (*/checked_bits % map_size == 0)
			{
				char_map[i] = '\n';
				i++;
			}
			if (checked_bits == map_size) //16)
			{
				checked_rows++;
				checked_bits = 0;
			}
		}
		checked_rows = 0;
		checked_bits = 0;
		i++;
	}
	ft_putstr(char_map);
}
