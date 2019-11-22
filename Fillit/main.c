/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:21:04 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/22 11:40:50 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		main(int argc, char **argv)
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
	close(fd);
	return (0);
}
