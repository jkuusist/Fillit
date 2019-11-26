/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:45:19 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/26 16:55:20 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_left(unsigned char *semi_valid_map)
{
	unsigned int	leftmost_mask;

	leftmost_mask = 34952;	
	if (*semi_valid_map & leftmost_mask >= 1)
		return (1);
	else
		return (0);
}

void	shift_left(unsigned char *semi_valid_map)
{
	while (check_left(semi_valid_map) == 1)
		*semi_valid_map <<= 1;
}
