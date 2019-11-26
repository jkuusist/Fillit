/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:21:04 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/26 14:54:22 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "fillit.h"
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
	if (check_input(fd) == 0)
		write(2, "error\n", 6);
	else
		write(1, "WE STILL HAVE TO DO SOMETHING FROM HERE", 40); 
	/********** TESTING PHASE FROM HERE DOWN  ****************************/
	int function_ret = check_input(fd);
	printf("open returned: %d\nCheck_input returned: %d\n", fd, function_ret);
	close(fd);
	return (0);
}
