/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:34:46 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/22 16:39:10 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 512
#include <unistd.h>

#include <stdio.h>

static int	check_character(char c)
{
	if ((c == '#') || (c == '.') || (c == '\n'))
		return (1);
	else
		return (0);
}

static int linelength(char *s)
{
	int i;

	i = 0;
	while ((s[i] != '\0') && check_character(s[i]))
		i++;
	return (i);
}

int		check_input(int fd)
{
	char map[BUFF_SIZE];
	int ret;
	int i;

	if ((ret = read(fd, map, BUFF_SIZE) < 0))
		return (0);
	int length = linelength(map);
	printf("line length is: %d\n", length);
	if (length != 4)
		return (0);
	return (1);
}		
