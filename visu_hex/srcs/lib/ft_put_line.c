/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:16:26 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/30 12:08:45 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_put_line.c                                            |
**   |     ft_get_color(15 lines)                               |
**   |     ft_put_line_color_2(14 lines)                        |
**   |     ft_put_line_color(17 lines)                          |
**   |     ft_put_line(25 lines)                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <visu_hex.h>

static int	ft_get_color(t_b *b, t_coord c, int x)
{
	t_rgb	color;
	t_rgb	color_s;
	t_rgb	color_e;

	(void)b;
	color_s = *(t_rgb*)&c.c1;
	color_e = *(t_rgb*)&c.c2;
	c.x2 = (c.x2 - (double)c.x1 == 0) ? c.x2++ : c.x2;
	color.r = (int)(color_e.r + floor((double)(color_s.r - color_e.r) /
				(double)(c.x2 - c.x1) * (x - c.x1)));
	color.g = (int)(color_e.g + floor((double)(color_s.g - color_e.g) /
				(double)(c.x2 - c.x1) * (x - c.x1)));
	color.b = (int)(color_e.b + floor((double)(color_s.b - color_e.b) /
				(double)(c.x2 - c.x1) * (x - c.x1)));
	return (*(int*)&color);
}

static void	ft_put_line_color_2(t_b *b, t_coord c)
{
	int		x;

	if (c.y2 - c.y1 < 0)
	{
		ft_swap_int(&c.x1, &c.x2);
		ft_swap_int(&c.y1, &c.y2);
		ft_swap_int(&c.c1, &c.c2);
	}
	ft_swap_int(&c.x1, &c.y1);
	ft_swap_int(&c.x2, &c.y2);
	x = c.x1 - 1;
	while (++x < c.x2)
		ft_put_px(b, c.y1 + ((c.y2 - c.y1) * (x - c.x1) / (c.x2 - c.x1)), x,
					ft_get_color(b, c, x));
}

void		ft_put_line_color(t_b *b, t_coord c)
{
	int		x;

	if (abs(c.x2 - c.x1) >= abs(c.y2 - c.y1))
	{
		if (c.x2 - c.x1 < 0)
		{
			ft_swap_int(&c.x1, &c.x2);
			ft_swap_int(&c.y1, &c.y2);
			ft_swap_int(&c.c1, &c.c2);
		}
		x = c.x1 - 1;
		while (++x < c.x2)
			ft_put_px(b, x, c.y1 + ((c.y2 - c.y1) * (x - c.x1) / (c.x2 - c.x1)),
					ft_get_color(b, c, x));
	}
	else
		ft_put_line_color_2(b, c);
}

void		ft_put_line(t_b *b, t_coord c, t_ui color)
{
	int		x;

	if (abs(c.x2 - c.x1) >= abs(c.y2 - c.y1))
	{
		if (c.x2 - c.x1 < 0)
		{
			ft_swap_int(&c.x1, &c.x2);
			ft_swap_int(&c.y1, &c.y2);
		}
		x = c.x1 - 1;
		while (++x < c.x2)
			ft_put_px(b, x, c.y1 + ((c.y2 - c.y1) * (x - c.x1) / (c.x2 - c.x1)),
					color);
		return ;
	}
	if (c.y2 - c.y1 < 0)
		ft_swap_int(&c.x1, &c.x2);
	if (c.y2 - c.y1 < 0)
		ft_swap_int(&c.y1, &c.y2);
	ft_swap_int(&c.x1, &c.y1);
	ft_swap_int(&c.x2, &c.y2);
	x = c.x1 - 1;
	while (++x < c.x2)
		ft_put_px(b, c.y1 + ((c.y2 - c.y1) * (x - c.x1) / (c.x2 - c.x1)), x,
				color);
}
