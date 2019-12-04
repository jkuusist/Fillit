/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_array_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:05:39 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/04 17:07:46 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned short	*array_create(void)
{
	unsigned short	*result;
	int				i;
	unsigned short	value;
	unsigned short	temp;

	result = (unsigned short*)malloc(sizeof(unsigned short) * 16);
	i = 0;
	value = 1;
	temp = 1;
	while (i < 16)
	{
		if (value <= 65535)
		{
			result[i++] = value;
			temp <<= 1;
			value = temp | value;
		}
		else
			return (result);
	}
	return (result);
}
