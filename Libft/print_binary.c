/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:01:49 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/05 11:15:29 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_binary(uint8_t byte)
{
	int		i;
	uint8_t	str[9];

	i = 128;
	str[0] = '\0';
	while (i > 0)
	{
		ft_strcat(str, ((byte & i) == i) ? "1" : "0");
		i >>= 1;
	}
	ft_putstr(str);
}
