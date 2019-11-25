/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:34:46 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/25 14:58:42 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 512
#include <unistd.h>
#include <stdio.h>

static int	get_return_value(unsigned char line_length,
		unsigned char tetri_height, unsigned char num_hashtags)
{
	if ((line_length == 5 || line_length == 1)
					&& tetri_height == 4 && num_hashtags != 0)
		return (1);
	else
		return (0);
}

static int	handle_newline(unsigned char *line_length,
		unsigned char *tetri_height, unsigned char *num_tetri)
{
	if (*line_length != 1 && *line_length != 5)
		return (0);
	else if (*line_length == 1 && *tetri_height == 4)
	{
		*tetri_height = 0;
		*line_length = 0;
		(*num_tetri)++;
	}
	else if (*line_length == 5)
	{
		*line_length = 0;
		(*tetri_height)++;
	}
	return (1);
}

static int	line_checker(char *map)
{
	unsigned char	line_length;
	unsigned char	tetri_height;
	unsigned char	num_tetri;
	unsigned char	num_hashtags;

	line_length = 0;
	num_tetri = 0;
	tetri_height = 0;
	num_hashtags = 0;
	while ((*map == '#' || *map == '.' || *map == '\n' || *map == '\0')
			&& (line_length++ < 6) && (num_tetri <= 26 && (tetri_height <= 4)))
	{
		if (*map == '#')
			num_hashtags++;
		if (*map == '\0')
			return (get_return_value(line_length, tetri_height, num_hashtags));
		handle_newline(&line_length, &tetri_height, &num_tetri);
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
