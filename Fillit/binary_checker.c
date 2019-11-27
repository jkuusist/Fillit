/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:56:47 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/27 12:06:45 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	binary_checker(void *a_tetrino)
{
	AS STRINGS
	{
		Block = 		"##..\n##..\n....\n....\n"
		3WayD = 		"###.\n.#..\n....\n....\n"
		3WayL = 		".#..\n##..\n.#..\n....\n"
		3WayR =			"#...\n##..\n#...\n....\n"
		3WayU = 		".#..\n###.\n....\n....\n"
		H_P-PieceLD =	"###.\n#...\n....\n....\n"
		H_P-PieceLU =	"#...\n###.\n....\n....\n"
		H_P-PieceRD =	"###.\n..#.\n....\n....\n"
		H_P-PieceRU =	"..#.\n###.\n....\n....\n"
		LineH		=	"####\n....\n....\n....\n"
		LineV		=	"#...\n#...\n#...\n#...\n"
		P-PieceLD	=	".#..\n.#..\n##..\n....\n"
		P-PieceLU	=	"##..\n.#..\n.#..\n....\n"
		P-PieceRD	=	"#...\n#...\n##..\n....\n"
		P-PieceRU	=	"##..\n#...\n#...\n....\n"
		Z-PieceL	=	"##..\n.##.\n....\n....\n"
		Z-PieceLU	=	".#..\n##..\n#...\n....\n"
		Z-PieceR	=	".##.\n##..\n....\n....\n"
		Z-PieceRU	=	"#...\n##..\n.#..\n....\n"
	}

	AS BINARY
	{
		Block = 		"1100110000000000"
		3WayD = 		"1110010000000000"
		3WayL = 		"0100110001000000"
		3WayR =			"1000110010000000"
		3WayU = 		"0100111000000000"
		H_P-PieceLD =	"1110100000000000"
		H_P-PieceLU =	"1000111000000000"
		H_P-PieceRD =	"1110001000000000"
		H_P-PieceRU =	"0010111000000000"
		LineH		=	"1111000000000000"
		LineV		=	"1000100010001000"
		P-PieceLD	=	"0100010011000000"
		P-PieceLU	=	"1100010001000000"
		P-PieceRD	=	"1000100011000000"
		P-PieceRU	=	"1100100010000000"
		Z-PieceL	=	"1100011000000000"
		Z-PieceLU	=	"0100110010000000"
		Z-PieceR	=	"0110110000000000"
		Z-PieceRU	=	"1000110001000000"
	}

	AS DECIMAL
	{
		Block = 		"52224"
		3WayD = 		"58368"
		3WayL = 		"19520"
		3WayR =			"35968"
		3WayU = 		"19968"
		H_P-PieceLD =	"59392"
		H_P-PieceLU =	"36352"
		H_P-PieceRD =	"57856"
		H_P-PieceRU =	"11776"
		LineH		=	"61440"
		LineV		=	"34952"
		P-PieceLD	=	"17600"
		P-PieceLU	=	"36352"
		P-PieceRD	=	"35008"
		P-PieceRU	=	"51328"
		Z-PieceL	=	"50688"
		Z-PieceLU	=	"19584"
		Z-PieceR	=	"27648"
		Z-PieceRU	=	"35904"
	}

}
