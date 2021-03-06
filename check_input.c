/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:34:46 by jkuusist          #+#    #+#             */
/*   Updated: 2020/01/07 16:17:39 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAP_SIZE 550
#include <unistd.h>
#include "Libft/libft.h"

/*
** A penultimate check for any tetrino, ensuring almost all criteria.
*/

static int		get_return_value(unsigned int line_length,
		unsigned int tetri_height, unsigned int num_hashtags)
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

static int		handle_newline(unsigned int *line_length,
		unsigned int *tetri_height, unsigned int *num_tetri,
		unsigned int *num_hashtags)
{
	if (*line_length != 1 && *line_length != 5)
		return (0);
	else if (*line_length == 1 && *tetri_height == 4)
	{
		*tetri_height = 0;
		*line_length = 0;
		(*num_tetri)++;
		*num_hashtags = 0;
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

static int		line_checker(char *map)
{
	unsigned int	line_length;
	unsigned int	tetri_height;
	unsigned int	num_tetri;
	unsigned int	num_hashtags;

	line_length = 0;
	num_tetri = 0;
	tetri_height = 0;
	num_hashtags = 0;
	while ((*map == '#' || *map == '.' || *map == '\n' || *map == '\0')
			&& (line_length++ < 6) && (num_tetri <= 26) && (tetri_height <= 4)
			&& (num_hashtags <= 4))
	{
		if (*map == '#')
			num_hashtags++;
		if (*map == '\0')
			return (get_return_value(line_length, tetri_height, num_hashtags));
		if (*map == '\n')
			if (!(handle_newline(&line_length, &tetri_height, &num_tetri,
			&num_hashtags)))
				return (0);
		map++;
	}
	return (0);
}

unsigned char	*check_input(int fd)
{
	char		map[MAP_SIZE];

	ft_memset(map, 0, (MAP_SIZE - 1));
	if (read(fd, map, MAP_SIZE) < 0)
		return (NULL);
	if (line_checker(map) != 0)
		return ((unsigned char *)ft_strdup(map));
	return (NULL);
}
