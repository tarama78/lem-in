/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_hex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:04:08 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/30 12:08:46 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_HEX_H
# define VISU_HEX_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <lem_in.h>
# include <visu_hex_struct.h>

/*
**	LEGENDE:
**		NOT:
**			yellow : 1 ant
**			white : 0 ant
**			red : > 1 ant
**		START:
**			yellow : >= 1 ant
**			white : 0 ant
**		END:
**			yellow : >= 1 ant
**			white : 0 ant
**			green : all ants
*/

void		ft_close(t_b *b);
void		ft_error2(char *file, char *func, int line, char *msg);
void		ft_init_win(t_b *b);
int			ft_key_event(int keycode, t_b *b);
void		ft_print_result(t_b *b);
void		ft_next_step(t_b *b);

void		ft_reset_win(t_b *b);
t_coord		ft_set_coord(int x1, int y1, int x2, int y2);
void		ft_put_px(t_b *b, int x, int y, t_ui color);
t_coord		ft_set_coord_color(long long xy1, int c1, long long xy2, int c2);
void		ft_put_line_color(t_b *b, t_coord c);
void		ft_put_line(t_b *b, t_coord c, t_ui color);
void		ft_print_win(t_b *b);

#endif
