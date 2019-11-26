/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:00:42 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/26 17:05:19 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	shift_left(unsigned int *semi_valid_map)
{
	unsigned int	leftmost_mask;

	leftmost_mask = 34952;
	while (*semi_valid_map & leftmost_mask >= 1)
		*semi_valid_map <<= 1;
	return ;
}
