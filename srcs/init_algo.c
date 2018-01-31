/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:21:11 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/31 11:15:53 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | init_algo.c                                              |
**   |     ft_re_init(12 lines)                                 |
**   |     ft_init_start(10 lines)                              |
**   |     ft_init_end(10 lines)                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <lem_in.h>

void		ft_re_init(t_a *a)
{
	t_room *room;

	room = a->room;
	while (room)
	{
		if (room->par != PATH)
		{
			room->weight = OK_PAR;
			room->par = NO_VISITED;
		}
		room = room->next;
	}
}

t_room		*ft_init_start(t_a *a)
{
	t_room *room;

	room = a->room;
	while (room)
	{
		if (room->state == START)
			break ;
		room = room->next;
	}
	return (room);
}

t_room		*ft_init_end(t_a *a)
{
	t_room *room;

	room = a->room;
	while (room)
	{
		if (room->state == END)
			break ;
		room = room->next;
	}
	return (room);
}
