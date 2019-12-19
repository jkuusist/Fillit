/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:21:04 by lharvey           #+#    #+#             */
/*   Updated: 2019/12/19 16:32:27 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static unsigned short	*check_validity(unsigned char *file_map)
{
	unsigned short	*semi_valid_array;

	semi_valid_array = create_block_array(file_map);
	if (binary_checker(semi_valid_array))
		return (semi_valid_array);
	return (0);
}

static int				check_file(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		write(2, "Usage: fillit target_file\n", 26);
		return (-1);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		write(2, "Open failed work with file\n", 26);
		return (-1);
	}
	return (fd);
}

int						main(int argc, char **argv)
{
	int				fd;
	unsigned char	*file_map;
	unsigned short	*binary_map;
	t_block			**bit_field;

	if ((fd = check_file(argc, argv)) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	file_map = check_input(fd);
	if (!file_map)
		write(1, "error\n", 6);
	else if ((binary_map = check_validity(file_map)))
	{
		if ((bit_field = solver(binary_map)) == NULL)
			return (0);
	}
	else
		write(1, "error\n", 6);
	close(fd);
	return (0);
}
