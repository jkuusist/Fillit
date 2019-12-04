/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:32:01 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/04 14:41:06 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

unsigned char	*check_input(int fd);
unsigned short	*create_block_array(unsigned char *string);
unsigned short	*binary_checker(unsigned short *semi_valid_array);
unsigned short	str_to_bin(unsigned char *block);
unsigned long long	squareroot(unsigned long long x);
typedef enum	e_shift_left
{
	0, 32768, 49152, 57344, 61440, 63488, 64512, 
	65024, 65280, 65408, 65472, 65504, 65520, 65528, 65532, 65534, 65535
}				t_shift_left;
typedef enum	e_shift_right
{
	0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 
	4095, 8191, 16383, 32767, 65535
}				t_shift_right;

#endif
