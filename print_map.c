/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:45:18 by lharvey           #+#    #+#             */
/*   Updated: 2020/01/07 11:02:54 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "Libft/libft.h"

static unsigned short		check_bit(unsigned short tetrino_field,
		unsigned int bit_nb)
{
	if (tetrino_field & (32768 >> bit_nb))
		return (1);
	else
		return (0);
}

unsigned int				check_four(unsigned short *map_field,
		unsigned int map_size)
{
	unsigned int	i;

	i = 0;
	while ((map_size < 5) && (i < 5))
	{
		while (check_bit(map_field[i], map_size) == 1)
			map_size++;
		i++;
	}
	while ((map_size < 5) && (map_field[map_size] != 0))
		map_size++;
	return (map_size);
}

static unsigned int			fill_charmap(unsigned int map_size,
		t_block **bit_field, char *char_map, unsigned int i)
{
	unsigned int	j;
	unsigned int	checked_bits;
	unsigned int	checked_rows;

	j = 0;
	checked_bits = 0;
	checked_rows = 0;
	while (checked_rows < map_size)
	{
		if (check_bit(bit_field[i]->tetrino_field
					[checked_rows], checked_bits++))
			char_map[j++] = bit_field[i]->id;
		else
			j++;
		if (checked_bits == map_size)
		{
			checked_rows++;
			char_map[j++] = '\n';
			checked_bits = 0;
		}
	}
	return (j);
}

void						print_map(t_block **bit_field,
		unsigned int map_size, unsigned int num_tetrinos)
{
	char			char_map[((map_size * map_size) + map_size) + 1];
	unsigned int	i;
	unsigned int	j;

	i = 0;
	ft_memset(char_map, '.', ((map_size * map_size) + map_size));
	while ((bit_field[i] != NULL) && (i < num_tetrinos))
	{
		j = fill_charmap(map_size, bit_field, char_map, i);
		i++;
	}
	char_map[j] = '\0';
	ft_putstr(char_map);
}
