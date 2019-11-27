/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:56:47 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/27 17:23:06 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Decimal representations of each (Top & Leftmost version) valid tetrino.
*/

static int		valid_maps(unsigned int *tetrino_block)
{
	if (*tetrino_block != 52224 || *tetrino_block != 58368 ||
		*tetrino_block != 19520 || *tetrino_block != 35968 ||
		*tetrino_block != 19968 || *tetrino_block != 59392 ||
		*tetrino_block != 36352 || *tetrino_block != 57856 ||
		*tetrino_block != 11776 || *tetrino_block != 61440 ||
		*tetrino_block != 34952 || *tetrino_block != 17600 ||
		*tetrino_block != 36352 || *tetrino_block != 35008 ||
		*tetrino_block != 51328 || *tetrino_block != 50688 ||
		*tetrino_block != 19584 || *tetrino_block != 27648 ||
		*tetrino_block != 35904)
		return (0);
	else
		return (1);
}

/*
** Shift functions move the bitmaps up/left via the magic of bit masks.
*/

static void		shift_left(unsigned int *semi_valid_map)
{
	while ((*semi_valid_map & 34952) >= 1)
		*semi_valid_map <<= 1;
}

static void		shift_up(unsigned int *semi_valid_map)
{
	while (*semi_valid_map < 4096)
		*semi_valid_map <<= 4;
}

unsigned int	*binary_checker(unsigned int *semi_valid_array)
{
	int	i;

	i = 0;
	while (semi_valid_array[i] != 0)
	{
		shift_up(&(semi_valid_array[i]));
		shift_left(&(semi_valid_array[i]));
		if (!(valid_maps(&(semi_valid_array[i]))))
			return (0);
		i++;
	}
	return (semi_valid_array);
}
