/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_array_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:05:39 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/10 14:12:42 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned short	R_SHIFT_create(void)
{
	unsigned short	value;
	int				i;
	unsigned short	bitmask;

	i = 0;
	bitmask = 1;
	while (i < 16)
	{
		bitmask = (bitmask << 1) | bitmask;
	}
	return (bitmask);
}

unsigned short	L_SHIFT_create(void)
{
	unsigned short	value;
	int				i;
	unsigned short	bitmask;

	i = 0;
	bitmask = 32768;
	while (i < 16)
	{
		bitmask = (bitmask >> 1) | bitmask;
	}
	return (bitmask);
}
