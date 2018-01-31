/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:30:22 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/30 16:24:14 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_print_result.c                                        |
**   |     ft_put_room(20 lines)                                |
**   |     ft_put_legende(17 lines)                             |
**   |     ft_put_str_room(32 lines)                            |
**   |         MEUUUU too many lines                            |
**   |     ft_print_result(20 lines)                            |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <visu_hex.h>

static void	ft_put_room(t_b *b, t_room *room)
{
	int		i;
	t_coord	c;

	i = -1;
	if (room->tab == NULL)
		return ;
	while (room->tab[++i])
	{
		c.x1 = room->x * b->zoom + START_X - b->min_x * b->zoom;
		c.y1 = room->y * b->zoom + START_Y - b->min_y * b->zoom;
		c.x2 = room->tab[i]->x * b->zoom + START_X - b->min_x * b->zoom;
		c.y2 = room->tab[i]->y * b->zoom + START_Y - b->min_y * b->zoom;
		c.c1 = 0x0000ff;
		c.c2 = 0x0000ff;
		(*(t_rgb*)&(c.c1)).r = c.x2 / (double)WIDTH * 255;
		(*(t_rgb*)&(c.c2)).r = c.x1 / (double)WIDTH * 255;
		(*(t_rgb*)&(c.c1)).g = 255 - c.x2 / (double)WIDTH * 255;
		(*(t_rgb*)&(c.c2)).g = 255 - c.x1 / (double)WIDTH * 255;
		ft_put_line_color(b, c);
	}
}

static void	ft_put_legende(t_b *b)
{
	int		y;

	y = HEIGHT - CHAR_H;
	mlx_string_put(b->mlx, b->win, 70, (y -= CHAR_H), 0x00ff00,
			"all ant (finish)");
	mlx_string_put(b->mlx, b->win, 70, (y -= CHAR_H), 0xffff00, ">= 1 ant");
	mlx_string_put(b->mlx, b->win, 70, (y -= CHAR_H), 0x999999, "0 ant");
	mlx_string_put(b->mlx, b->win, 40, (y -= CHAR_H), 0xffffff, "END:");
	mlx_string_put(b->mlx, b->win, 70, (y -= CHAR_H), 0xff0000,
			"> 1 ant (error)");
	mlx_string_put(b->mlx, b->win, 70, (y -= CHAR_H), 0xffff00, "1 ant");
	mlx_string_put(b->mlx, b->win, 70, (y -= CHAR_H), 0x999999, "0 ant");
	mlx_string_put(b->mlx, b->win, 40, (y -= CHAR_H), 0xffffff, "NORMAL:");
	mlx_string_put(b->mlx, b->win, 70, (y -= CHAR_H), 0xffff00, ">= 1 ant");
	mlx_string_put(b->mlx, b->win, 70, (y -= CHAR_H), 0x999999, "0 ant");
	mlx_string_put(b->mlx, b->win, 40, (y -= CHAR_H), 0xffffff, "START:");
	mlx_string_put(b->mlx, b->win, 10, (y -= CHAR_H), 0xffffff, "LEM-IN:");
}

static void	ft_put_str_room_2(t_b *b, t_room *room, t_rgb color, long long xy)
{
	char	str[20];
	char	*str_nb;
	int		x;
	int		y;

	x = ft_get2arg(xy, 0);
	y = ft_get2arg(xy, 1);
	if (room->state == START || room->state == END)
	{
		str[0] = '\0';
		ft_strcpy(str, ((room->state == START) ? "start:" : "end:"));
		if (!(str_nb = ft_itoa(room->nb)))
			ft_error2(__FILE__, (char*)__func__, __LINE__, NULL);
		ft_strcat(str, str_nb);
		ft_fruit(1, str_nb);
		mlx_string_put(b->mlx, b->win, x - 10, y + CHAR_H, *(int*)&color, str);
	}
}

static void	ft_put_str_room(t_b *b, t_room *room)
{
	t_rgb	color;
	char	str[20];
	char	*str_nb;
	int		x;
	int		y;

	color.r = (room->nb == (int)b->a->nb_ant && room->state == END) ? 0 : 255;
	color.g = (room->nb > 1 && room->state == NOT) ? 0 : 255;
	color.b = 0;
	if (room->nb == 0)
		*(int*)&color = 0x999999;
	x = room->x * b->zoom - b->min_x * b->zoom + TEXT_X -
		(ft_strlen(room->name) << 1) * CHAR_W;
	y = room->y * b->zoom - b->min_y * b->zoom + TEXT_Y -
		((room->state == START || room->state == END) ? CHAR_H : 0);
	mlx_string_put(b->mlx, b->win, x, y, *(int*)&color, room->name);
	ft_put_str_room_2(b, room, color, ft_2arg(x, y));
	if (!(str_nb = ft_itoa(b->step)))
		ft_error2(__FILE__, (char*)__func__, __LINE__, NULL);
	ft_strcpy(str, "STEP: ") && ft_strcat(str, str_nb);
	ft_fruit(1, str_nb);
	mlx_string_put(b->mlx, b->win, 10, 8, 0xffffff, str);
	ft_put_legende(b);
}

void		ft_print_result(t_b *b)
{
	t_room	*room;

	ft_reset_win(b);
	room = b->a->room;
	while (room)
	{
		ft_put_room(b, room);
		room = room->next;
	}
	ft_put_line_color(b, ft_set_coord_color(ft_2arg(0, HEIGHT - 200),
				0xffffff, ft_2arg(250, HEIGHT - 200), 0xff5555));
	ft_put_line_color(b, ft_set_coord_color(ft_2arg(250, HEIGHT - 200),
				0xff5555, ft_2arg(250, HEIGHT), 0xffffff));
	ft_print_win(b);
	room = b->a->room;
	while (room)
	{
		ft_put_str_room(b, room);
		room = room->next;
	}
}
