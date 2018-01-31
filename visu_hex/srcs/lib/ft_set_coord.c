/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:46:06 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/30 12:08:45 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_set_coord.c                                           |
**   |     ft_set_coord(9 lines)                                |
**   |     ft_set_coord_color(9 lines)                          |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <visu_hex.h>

t_coord		ft_set_coord(int x1, int y1, int x2, int y2)
{
	t_coord	c;

	c.x1 = x1;
	c.y1 = y1;
	c.c1 = 0xFFFFFF;
	c.x2 = x2;
	c.y2 = y2;
	c.c2 = 0xFFFFFF;
	return (c);
}

t_coord		ft_set_coord_color(long long xy1, int c1, long long xy2, int c2)
{
	t_coord	c;

	c.x1 = ft_get2arg(xy1, 0);
	c.y1 = ft_get2arg(xy1, 1);
	c.c1 = c1;
	c.x2 = ft_get2arg(xy2, 0);
	c.y2 = ft_get2arg(xy2, 1);
	c.c2 = c2;
	return (c);
}
