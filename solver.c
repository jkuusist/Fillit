/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:07:31 by lharvey           #+#    #+#             */
/*   Updated: 2020/01/07 16:03:48 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "Libft/libft.h"

/*
**	Resets position of a tetrino to the upper-left position.
*/

static void		reset_tetrino(unsigned short *tetrino, unsigned int map_size)
{
	while (shift_left(tetrino, 1, map_size) == 1)
		;
	while (shift_up(tetrino, 1) == 1)
		;
}

static void		backtrack_beta(unsigned short *map_field, t_block **bit_field,
		unsigned int map_size, int *index)
{
	reset_tetrino(bit_field[*index]->tetrino_field, map_size);
	(*index)--;
	while (*index >= 0)
	{
		unstamp_map(map_field, bit_field[*index]->tetrino_field);
		bit_field[*index]->used_flag = 0;
		if (shifter(bit_field[*index]->tetrino_field, 1, map_size) == 0)
		{
			reset_tetrino(bit_field[*index]->tetrino_field, map_size);
			(*index)--;
		}
		else
			break ;
	}
}

/*
**	Non-recursive backtracking algorithm. Utilises bitwise checks.
**	Uses sub-function to perform the backtracking portion.
*/

static t_block	**algorithm_alpha(unsigned short *map_field,
		t_block **bit_field, unsigned int map_size)
{
	int		index;

	while ((index = check_tblocks(bit_field)) != -2)
	{
		if (bit_field == NULL)
			return (NULL);
		while (index >= 0)
		{
			if (stamp_map(map_field, bit_field[index]->tetrino_field))
			{
				bit_field[index]->used_flag = 1;
				index = check_tblocks(bit_field);
			}
			else if (shifter(bit_field[index]->tetrino_field, 1, map_size) == 0)
				break ;
		}
		if (index >= 0)
		{
			backtrack_beta(map_field, bit_field, map_size, &index);
			if (index == -1)
				return (NULL);
		}
	}
	return (bit_field);
}

static void		success_printer(unsigned int tetrino_count,
		unsigned int map_size, unsigned short map_field[14],
		t_block **bit_field)
{
	if (map_size < 4)
		map_size = check_four(map_field, map_size);
	print_map(bit_field, map_size, tetrino_count);
}

t_block			**solver(unsigned short *binary_map)
{
	unsigned int	tetrino_count;
	unsigned short	map_field[14];
	unsigned int	map_size;
	t_block			**bit_field;
	t_block			**temp_field;

	tetrino_count = 0;
	while (binary_map[tetrino_count] != 0)
		tetrino_count++;
	map_size = ((unsigned int)square_root(tetrino_count * 4) - 1);
	while (++map_size <= 14)
	{
		bit_field = create_tblocks(binary_map, tetrino_count);
		temp_field = bit_field;
		ft_bzero(map_field, (14 * 2));
		if ((bit_field = algorithm_alpha(map_field, bit_field,
						map_size)) != NULL)
		{
			success_printer(tetrino_count, map_size, map_field, temp_field);
			free_tblocks(temp_field);
			break ;
		}
		free_tblocks(temp_field);
	}
	return (bit_field);
}
