/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:45:18 by lharvey           #+#    #+#             */
/*   Updated: 2019/12/12 13:58:23 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_char(char *charmap, char c, int index)
{
	charmap[i] = c;
}

void	print_map(t_block **bit_field, unsigned int map_size, unsigned int num_tetrinos)
{
	char	char_map[(map_size*map_size) + map_size];
	int i;
	int checked_bits;

	i = 0;
	checked_bits = 0;
	while (i <= num_tetrinos)
		ft_memset((&(char_map[i++])), '.', 1)
	i = 0;
	while (bit_field[i] != NULL)
	{
		while ((checked_bits <= 16) && (checked_rows < 10))
		{
//			check every bit for 1
//			if 1, put -> ID in that charmap[i]
//			if 0, ++, until an entire t_block is cleared.
		}
//	Go to the next t_block
	i++;
	}
//	Print the final result
	ft_putstr(charmap);
}
