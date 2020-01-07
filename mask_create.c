/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:19:10 by lharvey           #+#    #+#             */
/*   Updated: 2020/01/07 15:24:07 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned short	l_shift_create(void)
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
