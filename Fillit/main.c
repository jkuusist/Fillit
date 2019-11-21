/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:21:04 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/21 13:36:49 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	fd;

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(2, "Usage: fillit target_file", 26);
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		write(2, "Open failed work with file", path);
		return(-1);
	}
	return(0);
}
