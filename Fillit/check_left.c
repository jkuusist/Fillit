/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:45:19 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/26 11:54:36 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_left(unsigned char *semi_valid_map)
{
	int	i;
	int	empty_edge;

	i = 0;
	empty_edge = 0;
	while (semi_valid_map[i] == '.' && empty_edge++ <= 4)
		i + 5;
	if (empty_edge == 4)
		return (1);
	else
		return (0);
}
