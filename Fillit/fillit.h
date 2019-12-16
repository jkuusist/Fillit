/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:32:01 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/16 17:11:32 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

unsigned char		*check_input(int fd);
unsigned short		*create_block_array(unsigned char *string);
unsigned short		*binary_checker(unsigned short *semi_valid_array);
unsigned short		shift_left(unsigned short *bit_field, int shift_amount,
		unsigned int mask_size);
unsigned short		shift_right(unsigned short *bit_field, int shift_amount,
		unsigned int mask_size);
unsigned short		shift_up(unsigned short *bit_field, int shift_amount);
unsigned short		shift_down(unsigned short *bit_field, int shift_amount,
		unsigned int mask_size);
unsigned short		r_shift_create(unsigned int min_size);
unsigned short		l_shift_create(unsigned int min_size);
typedef struct		s_block
{
	unsigned char		id;
	unsigned short		*tetrino_field;
	unsigned char		used_flag;
}					t_block;
t_block				**create_tblocks(unsigned short *binary_map,
		unsigned int tetrino_count);
t_block				**solver(unsigned short *binary_map);
void				print_map(t_block **bit_field, unsigned int map_size,
		unsigned int num_tetrinos);
t_block				**copy_tblocks(t_block **src);
void				free_tblocks(t_block **array);
unsigned long long	square_root(unsigned long long x);
unsigned int		check_four(unsigned short *map_field, unsigned int map_size);

#endif
