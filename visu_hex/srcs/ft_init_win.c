/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:05:05 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/30 16:16:07 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_init_win.c                                            |
**   |     ft_init_win(16 lines)                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <visu_hex.h>

void		ft_init_win(t_b *b)
{
	b->img.bpp = 32;
	b->img.sz_ln = WIDTH * 4;
	b->img.endian = 0;
	b->zoom = (WIDTH - (START_X << 1)) / (double)b->max_x;
	b->zoom = ((HEIGHT - (START_Y << 1)) / (double)b->max_y < b->zoom) ?
		(HEIGHT - (START_Y << 1)) / (double)b->max_y : b->zoom;
	b->step = 0;
	if (!(b->mlx = mlx_init()))
		ft_error2(__FILE__, (char*)__func__, __LINE__, NULL);
	if (!(b->win = mlx_new_window(b->mlx, WIDTH, HEIGHT, "lem-in")))
		ft_error2(__FILE__, (char*)__func__, __LINE__, NULL);
	if (!(b->img.img = mlx_new_image(b->mlx, WIDTH, HEIGHT)))
		ft_error2(__FILE__, (char*)__func__, __LINE__, NULL);
	if (!(b->img.str = mlx_get_data_addr(b->img.img, &b->img.bpp, &b->img.sz_ln,
			&b->img.endian)))
		ft_error2(__FILE__, (char*)__func__, __LINE__, NULL);
}
