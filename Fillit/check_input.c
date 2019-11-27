/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:34:46 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/27 13:32:43 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 512
#include <unistd.h>

/*
** A penultimate check for any tetrino, ensuring almost all criteria.
*/

static int	get_return_value(unsigned char line_length,
		unsigned char tetri_height, unsigned char num_hashtags)
{
	if ((line_length == 5 || line_length == 1)
					&& tetri_height == 4 && num_hashtags == 4)
		return (1);
	else
		return (0);
}

/*
**  Checks lengths of tetrinos, subfn of line checker
*/

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

/*
** Ensure no invalid chars, over/under length/height but no N.N. check
*/

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
	return (NULL);
}

char		*check_input(int fd)
{
	char	map[BUFF_SIZE];

	if ((read(fd, map, BUFF_SIZE) < 0))
		return (NULL);
	if (line_checker(map) != 0)
		return (map);
	else
		return (NULL);
}
