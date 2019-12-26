/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stampers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:11:11 by lharvey           #+#    #+#             */
/*   Updated: 2019/12/26 11:00:51 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		stamp_map(unsigned short *map_field, unsigned short *tetrino)
{
	int i;

	i = 0;
	while (i < 14)
	{
		if ((map_field[i] & tetrino[i]) == 0)
			i++;
		else
			return (0);
	}
	i = 0;
	while (i < 14)
	{
		map_field[i] |= tetrino[i];
		i++;
	}
	return (1);
}

void	unstamp_map(unsigned short *map_field, unsigned short *tetrino)
{
	int i;

	i = 0;
	while (i < 14)
	{
		map_field[i] ^= tetrino[i];
		i++;
	}
}
