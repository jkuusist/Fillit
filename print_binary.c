/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:01:49 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/21 11:02:25 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_binary.h"
#include "libft.h"

void	print_binary(char c)
{
	int		i;
	char	str[9];

	i = 128;
	str[0] = '\0';
	while (i > 0)
	{
		ft_strcat(str, ((c & i) == i) ? "1" : "0");
		i >>= 1;
	}
	ft_putstr(str);
}
