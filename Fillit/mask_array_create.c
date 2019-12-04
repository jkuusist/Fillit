/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_array_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:05:39 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/04 17:30:23 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned short	*R_SHIFT_array_create(void)
{
	unsigned short	*array;
	int				i;
	unsigned short	bitmask;

	array = (unsigned short*)malloc(sizeof(unsigned short) * 16);
	i = 0;
	bitmask = 1;
	while (i < 16)
	{
		array[i++] = bitmask;
		bitmask = (bitmask << 1) | bitmask;
	}
	return (array);
}

unsigned short	*L_SHIFT_array_create(void)
{
	unsigned short	*array;
	int				i;
	unsigned short	bitmask;

	array = (unsigned short*)malloc(sizeof(unsigned short) * 16);
	i = 0;
	bitmask = 32768;
	while (i < 16)
	{
		array[i++] = bitmask;
		bitmask = (bitmask >> 1) | bitmask;
	}
	return (array);
}
