/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tblocks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:05:55 by lharvey           #+#    #+#             */
/*   Updated: 2020/01/07 14:23:29 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "Libft/libft.h"

/*
**	This function returns -1 on NULL (an error catch), but provides the caller
**	with an index of the first unused tetrino, searching linearly. If all
**	tetrinos are being used, then -2 is returned; indication completion.
*/

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
	int j;

	if (array == NULL)
		return ;
	i = 0;
	j = 0;
	while (array[i] != 0)
	{
		free(array[i]->tetrino_field);
		array[i]->tetrino_field = NULL;
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

/*
**	This function assigns value to 'rows' that lie within inside
**	t_block->tetrino_field[0-13] (named temp).
*/

static void	assign_row_values(unsigned short *array, t_block *temp)
{
	int k;

	k = 0;
	while (k < 14)
	{
		temp->tetrino_field[k] = array[k];
		k++;
	}
}

/*
**	Data is set here in this function. Tetrinos were 16-bit shorts and need
**	coversion into 4 'rows' [0-3] via this bitwise &.
*/

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

/*
**	Creates the array of tetrino blocks utilised by the solver. Bzero clears,
**	space for the fields is malloc'd, tetrino ID/flags are set. Data is set
**	by converting the 16-bit short into 4 'lines' of shorts, with the
**	remaining data being zeroed.
*/

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
	bit_field = (t_block**)malloc(sizeof(t_block) * (tetrino_count + 1));
	while (binary_map[i] != 0)
	{
		temp = (t_block*)malloc(sizeof(t_block));
		temp->tetrino_field =
			(unsigned short *)malloc(sizeof(unsigned short) * 14);
		ft_bzero(temp->tetrino_field, 28);
		temp->id = id;
		temp->used_flag = 0;
		tblock_conversion(binary_map[i], array);
		assign_row_values(array, temp);
		bit_field[i] = temp;
		id++;
		i++;
	}
	bit_field[i] = NULL;
	return (bit_field);
}
