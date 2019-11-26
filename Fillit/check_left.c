/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:45:19 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/26 16:31:41 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_left(unsigned char *semi_valid_map)
{
	unsigned int	leftmost_mask;

	leftmost_mask = 34952;	
	
	if (*semi_valid_map & leftmost_mask >= 1)
		return (1);
	else
		return (0);
}
