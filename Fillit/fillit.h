/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:32:01 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/10 15:23:50 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

unsigned char		*check_input(int fd);
unsigned short		*create_block_array(unsigned char *string);
unsigned short		*binary_checker(unsigned short *semi_valid_array);
unsigned short		shift_left(unsigned short *bit_field, int shift_amount);
unsigned short		shift_right(unsigned short *bit_field, int shift_amount);
unsigned short		shift_up(unsigned short *bit_field, int shift_amount);
unsigned short		shift_down(unsigned short *bit_field, int shift_amount);
unsigned short		R_SHIFT_create(void);
unsigned short		L_SHIFT_create(void);
typedef struct		s_block
{
	unsigned char		id;
	unsigned short		*tetrino_field;
	unsigned char		used_flag;
}						t_block;

#endif
