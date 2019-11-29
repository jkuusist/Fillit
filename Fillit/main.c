/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:21:04 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/29 13:02:28 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

unsigned short	*check_validity(unsigned char *file_map)
{
	unsigned short	*semi_valid_array;

	semi_valid_array = create_block_array(file_map);
	if (binary_checker(semi_valid_array))
		return (semi_valid_array);
	return (0);
}

int				main(int argc, char **argv)
{
	int				fd;
	unsigned char	*file_map;
	unsigned short	*binary_map;

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
	file_map = check_input(fd);
	if (!file_map)
		write(1, "error\n", 6);
	else if ((binary_map = check_validity(file_map)))
		write(1, "Algorithm_Nonsence_That_Needs_Creating\n", 39);
	else
		write(1, "error\n", 6);
	close(fd);
	return (0);
}
