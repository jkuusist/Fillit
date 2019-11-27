/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:32:01 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/27 17:50:38 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

char			*check_input(int fd);
unsigned int	*create_block_array(char *string);
int				binary_checker(unsigned int *semi_valid_array);
unsigned int	str_to_bin(unsigned char *block);

#endif
