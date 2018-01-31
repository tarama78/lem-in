/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:02:48 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/30 12:08:44 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | main.c                                                   |
**   |     ft_set_maxmin(20 lines)                              |
**   |     main(15 lines)                                       |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <visu_hex.h>

static void	ft_set_maxmin(t_b *b)
{
	t_room	*room;

	b->min_x = INT_MAX;
	b->min_y = INT_MAX;
	b->max_x = INT_MIN;
	b->max_y = INT_MIN;
	room = b->a->room;
	while (room)
	{
		if (room->x < b->min_x)
			b->min_x = room->x;
		if (room->y < b->min_y)
			b->min_y = room->y;
		if (room->x > b->max_x)
			b->max_x = room->x;
		if (room->y > b->max_y)
			b->max_y = room->y;
		room = room->next;
	}
	b->max_y = (b->max_y == 0) ? 1 : b->max_y;
}

int			main(int ac, char **av)
{
	t_b		b;

	(void)ac;
	(void)av;
	if (!(b.a = malloc(sizeof(t_a))))
		return (EXIT_FAILURE);
	ft_read(b.a);
	if (ft_init_ant(b.a) == ERROR)
		return (1);
	ft_set_maxmin(&b);
	ft_init_win(&b);
	mlx_hook(b.win, 2, 0, ft_key_event, &b);
	ft_print_result(&b);
	mlx_loop(b.mlx);
	return (0);
}
