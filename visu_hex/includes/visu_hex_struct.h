/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_hex_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:37:08 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/30 12:08:46 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_HEX_STRUCT_H
# define VISU_HEX_STRUCT_H

# define WIDTH 1200
# define HEIGHT 750
# define START_X 50
# define START_Y 50
# define CHAR_W 3
# define CHAR_H 15
# define TEXT_X 47
# define TEXT_Y 24

typedef struct				s_img
{
	void					*img;
	char					*str;
	int						bpp;
	int						sz_ln;
	int						endian;
}							t_img;

typedef struct				s_b
{
	t_a						*a;
	void					*mlx;
	void					*win;
	t_img					img;
	double					zoom;
	int						step;
	int						max_x;
	int						max_y;
	int						min_x;
	int						min_y;
}							t_b;

typedef struct				s_coord
{
	int						x1;
	int						y1;
	int						c1;
	int						x2;
	int						y2;
	int						c2;
}							t_coord;

typedef struct				s_rgb
{
	unsigned int			b : 8;
	unsigned int			g : 8;
	unsigned int			r : 8;
	unsigned int			a : 8;
}							t_rgb;

#endif
