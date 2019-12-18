/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_array_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:05:39 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/18 17:11:45 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned short	l_shift_create()
{
	return (32768);
}

unsigned short	r_shift_create(unsigned int min_size)
{
	unsigned int	i;
	unsigned short	bitmask;

	i = 0;
	bitmask = 32768;
	while (i < (min_size - 2))
	{
		bitmask = (bitmask >> 1) | bitmask;
		i++;
	}
	return (~bitmask);
}
