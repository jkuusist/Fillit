/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:59:39 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/26 16:57:18 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_up(unsigned char *semi_valid_map)
{
	if (*semi_valid_map < 4096)
		return (1);
	else 
		return (0);
}

void	shift_up(unsigned char *semi_valid_map)
{
	while (check_up(semi_valid_map) == 1)
		*semi_valid_map <<= 4;
}
