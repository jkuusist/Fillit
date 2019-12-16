/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:45:18 by lharvey           #+#    #+#             */
/*   Updated: 2019/12/16 15:19:55 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../Libft/libft.h"

#include <stdio.h>

static unsigned short		check_bit(unsigned short *bit_field,
		unsigned int bit_nb)
{
	//printf("bit_field[bit_nb] is %d\n32768 >> bit_nb is %d\n", bit_field[bit_nb], (32768 >> bit_nb));

	if (bit_field[bit_nb] & (32768 >> (bit_nb)))
		return (1);
	else
		return (0);
}

void						print_map(t_block **bit_field,
		unsigned int map_size, unsigned int num_tetrinos)
{
	char			char_map[(map_size * map_size) + map_size];
	unsigned int	i;
	unsigned int	checked_bits;
	unsigned int	checked_rows;

	i = 0;
	checked_bits = 0;
	checked_rows = 0;
	while (i <= (map_size * map_size + map_size))
		ft_memset((&(char_map[i++])), '.', 1);
	i = 0;

	printf("bit_field[i] is %p\n", bit_field[i]);

	while ((bit_field[i] != NULL) && (i < num_tetrinos))
	{

		printf("i is %d. checked_rows is %d. num_tet is %d. map_size is %d\n", i, checked_rows, num_tetrinos, map_size);
		printf("bit_field[i]->tetrino_field[checked_rows] is %d\n", bit_field[i]->tetrino_field[checked_rows]);
		
		while (checked_rows <= map_size)
		{

		printf("INSIDE WHILE LOOP. checked_rows is now %d\n", checked_rows);

			if (checked_bits == 16)//(checked_bits / 16 == 0)
			{
				checked_rows++;
				checked_bits = 0;
			}

	printf("i is %d. checked_rows is %d\n", i, checked_rows);
	//printf("bit_field[i]->tetrino_field[checked_rows] is %d\n", bit_field[i]->tetrino_field[checked_rows]);
	
			if (check_bit(&(bit_field[i]->tetrino_field[checked_rows]),
						checked_bits++))
			{
				printf("char should be put on map here\n");
				char_map[i] = bit_field[i]->id;
			}
			if ((checked_bits != 0) && (checked_bits % map_size == 0))
				char_map[i++] = '\n';
		}
		checked_rows = 0;
		i++;
	}
	ft_putstr(char_map);
}
