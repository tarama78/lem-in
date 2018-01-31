/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fruit_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:57:07 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/31 14:08:04 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_fruit_a.c                                             |
**   |     ft_fruit_room(5 lines)                               |
**   |     ft_fruit_tube(1 lines)                               |
**   |     ft_fruit_path(1 lines)                               |
**   |     ft_fruit_a(12 lines)                                 |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <lem_in.h>

static void	ft_fruit_room(t_lst *lst)
{
	t_room	*room;

	room = (t_room*)lst;
	free(room->name);
	free(room->tab);
}

static void	ft_fruit_map(t_lst *lst)
{
	free(((t_map*)lst)->str);
}

static void	ft_fruit_path(t_lst *lst)
{
	(void)lst;
}

void		ft_fruit_a(t_a *a)
{
	int		i;

	ft_fruit_lst((t_lst*)a->room, ft_fruit_room);
	free(a->ant);
	ft_fruit_lst((t_lst*)a->map, ft_fruit_map);
	if (a->tab_path)
	{
		i = -1;
		while (a->tab_path[++i])
			ft_fruit_lst((t_lst*)a->tab_path[i], ft_fruit_path);
		free(a->tab_path);
	}
}
