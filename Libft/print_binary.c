/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:01:49 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/12 13:28:07 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_binary(unsigned char byte)
{
	int				i;
	unsigned char	str[9];

	i = 128;
	str[0] = '\0';
	while (i > 0)
	{
		ft_strcat((char*)str, ((byte & i) == i) ? "1" : "0");
		i >>= 1;
	}
	ft_putstr((char*)str);
}
