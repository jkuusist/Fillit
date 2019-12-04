/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:32:01 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/04 17:17:20 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

unsigned char	*check_input(int fd);
unsigned short	*create_block_array(unsigned char *string);
unsigned short	*binary_checker(unsigned short *semi_valid_array);
unsigned short	str_to_bin(unsigned char *block);
unsigned long long	squareroot(unsigned long long x);

#endif
