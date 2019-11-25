/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:34:46 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/25 12:01:19 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 512
#include <unistd.h>
#include <stdio.h>

static int	line_checker(char *map)
{
	unsigned char	str_length;
	unsigned char	tetri_height;
	unsigned char	num_tetri;

	str_length = 0;
	num_tetri = 0;
	tetri_height = 0;
	while ((*map == '#' || *map == '.' || *map == '\n' || *map == '\0') 
			&& (str_length++ < 6) && (num_tetri <= 26 && (tetri_height <= 4)))
	{
		if ((str_length == 0) && (*map == '\n')
				&& (*(map + 1) != '#') && (*(map + 1) != '.'))
			return (0);
		if (str_length == 0 && *map == '\n')
		{
			tetri_height = 0;
			num_tetri++;
		}
		if (*map == '\0')
		{
			if (str_length == 5 && tetri_height == 4)
			{
				num_tetri++;
				return (1);
			}
			if (num_tetri && (str_length == 1 && tetri_height == 0))
				return (1);
			else
				return (0);
		}
		if (str_length == 5 && *map == '\n')
		{
			str_length = 0;
			tetri_height++;
		}
		map++;
	}
	return (0);
}

int			check_input(int fd)
{
	char	map[BUFF_SIZE];
	int		ret;
	int		line_checker_ret;

	if ((ret = read(fd, map, BUFF_SIZE) < 0))
		return (0);
	line_checker_ret = line_checker(map);
	printf("line checker returned: %d\n", line_checker_ret);
	return (1);
}
