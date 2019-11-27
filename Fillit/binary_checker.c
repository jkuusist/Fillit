/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:56:47 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/27 12:21:10 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	binary_checker(unsigned int *tetrino_block)
{
	if (*tetrino_block != 52224 || *tetrino_block != 58368 ||
		*tetrino_block != 19520 || *tetrino_block != 35968 ||
		*tetrino_block != 19968 || *tetrino_block != 59392 ||
		*tetrino_block != 36352 || *tetrino_block != 57856 ||
		*tetrino_block != 11776 || *tetrino_block != 61440 ||
		*tetrino_block != 34952 || *tetrino_block != 17600 ||
		*tetrino_block != 36352 || *tetrino_block != 35008 ||
		*tetrino_block != 51328 || *tetrino_block != 50688 ||
		*tetrino_block != 19584 || *tetrino_block != 27648 ||
		*tetrino_block != 35904)
		return (0);
	else
		return (1);
}
