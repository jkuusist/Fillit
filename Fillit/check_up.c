/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:59:39 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/26 12:07:33 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Searches a semi-valid map for empty lines (\n) and returns the # of them */

int	check_up(unsigned char *semi_valid_map)
{
	int	empty_above;

	empty_above = 0;
	while (*semi_valid_map == '.' || *semi_valid_map == '\n')
	{
		if (*semi_valid == '\n')
			empty_above++;
	 	semi_valid_map++;
	}
	return (empty_above)
}
