/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tblocks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:05:55 by lharvey           #+#    #+#             */
/*   Updated: 2019/12/26 10:57:47 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "../Libft/libft.h"

int			check_tblocks(t_block **src)
{
	int i;

	i = 0;
	if (src == NULL)
		return (-1);
	while ((src[i] != NULL) && (src[i]->used_flag == 1))
		i++;
	if ((src[i] != NULL) && (src[i]->used_flag == 0))
		return (i);
	return (-2);
}

void		free_tblocks(t_block **array)
{
	int i;

	i = 0;
	while (array[i] != 0)
	{
		free(array[i]->tetrino_field);
		free(array[i]);
		i++;
	}
	free(array);
}

static void	stack_to_heap(unsigned short *array, t_block *temp)
{
	int k;

	k = 0;
	while (k < 14)
	{
		temp->tetrino_field[k] = array[k];
		k++;
	}
}

static void	tblock_conversion(unsigned short binary_mapi, unsigned short *array)
{
	int	j;

	j = 0;
	while (j < 14)
	{
		if (j == 0)
			array[j] = binary_mapi & 61440;
		else if (j == 1)
			array[j] = ((binary_mapi & 3840) << 4);
		else if (j == 2)
			array[j] = ((binary_mapi & 240) << 8);
		else if (j == 3)
			array[j] = ((binary_mapi & 15) << 12);
		else
			array[j] = 0;
		j++;
	}
}

t_block		**create_tblocks(unsigned short *binary_map,
		unsigned int tetrino_count)
{
	int				i;
	unsigned char	id;
	t_block			*temp;
	t_block			**bit_field;
	unsigned short	array[14];

	i = 0;
	id = 'A';
	bit_field = (t_block**)malloc(sizeof(t_block) * tetrino_count + 1);
	while (binary_map[i] != 0)
	{
		temp = (t_block*)malloc(sizeof(t_block));
		temp->tetrino_field =
			(unsigned short *)malloc(sizeof(unsigned short) * 14);
		ft_bzero(temp->tetrino_field, 20);
		temp->id = id;
		temp->used_flag = 0;
		tblock_conversion(binary_map[i], array);
		stack_to_heap(array, temp);
		bit_field[i] = temp;
		id++;
		i++;
	}
	bit_field[i] = NULL;
	return (bit_field);
}
