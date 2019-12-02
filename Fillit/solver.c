/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:42:24 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/02 14:29:56 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*solver(unsigned short *binary_map)
{
	int i;
	int map_size;

	i = 0;
	while (binary_map[i] != 0)
		i++;
	map_size = squareroot(i * 4);

}
