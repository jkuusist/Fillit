/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:45:18 by lharvey           #+#    #+#             */
/*   Updated: 2019/12/12 13:34:09 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_map(t_block **bit_field, unsigned int map_size, unsigned int num_tetrinos)
{
	char	char_map[(map_size*map_size) + map_size];
	int i;

	i = 0;
	while (i <= num_tetrinos)
		ft_memset((&(char_map[i++])), '.', 1)
	
}
