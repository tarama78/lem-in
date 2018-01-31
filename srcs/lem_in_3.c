/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:28:54 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/31 14:21:21 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | lem_in_3.c                                               |
**   |     ft_realloc_room_tab(24 lines)                        |
**   |     ft_find_room(6 lines)                                |
**   |     ft_tube_aux(9 lines)                                 |
**   |     ft_tube(25 lines)                                    |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <lem_in.h>

static int		ft_realloc_room_tab(t_room ***tab, t_room *room)
{
	t_room	**new;
	int		i;

	i = 0;
	if (*tab == NULL)
	{
		if (!(*tab = (t_room **)malloc(sizeof(t_room *) * 2)))
			return (ERROR);
		(*tab)[0] = room;
		(*tab)[1] = NULL;
		return (SUCCESS);
	}
	while ((*tab)[++i])
		;
	if (!(new = (t_room **)malloc(sizeof(t_room *) * (i + 2))))
		return (ERROR);
	i = -1;
	while ((*tab)[++i])
		new[i] = (*tab)[i];
	new[i] = room;
	new[++i] = NULL;
	free(*tab);
	*tab = new;
	return (SUCCESS);
}

static void		ft_find_room(t_room **tmp, char *room)
{
	while (*tmp)
	{
		if (ft_strcmp((*tmp)->name, room) == 0)
			break ;
		(*tmp) = (*tmp)->next;
	}
}

static int		ft_tube_aux(t_room **tmp, t_room **cur)
{
	if (*tmp == NULL || *cur == NULL)
		return (ERROR);
	if (ft_realloc_room_tab(&(*tmp)->tab, *cur) == ERROR)
		return (ERROR);
	if (ft_realloc_room_tab(&(*cur)->tab, *tmp) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int		ft_error_tube(char ***tab_tube)
{
	int		i;

	i = -1;
	while ((*tab_tube)[++i])
		free((*tab_tube)[i]);
	ft_fruit(1, *tab_tube);
	return (ERROR);
}

int				ft_tube(t_a *a, char *line)
{
	t_room	*tmp;
	t_room	*cur;
	char	**tab_tube;
	int		i;

	i = 0;
	if (!(tab_tube = ft_strsplit(line, '-')))
		return (ERROR);
	while (tab_tube[++i])
		;
	if (i != 2)
		return (ERROR);
	tmp = a->room;
	cur = a->room;
	ft_find_room(&tmp, tab_tube[0]);
	ft_find_room(&cur, tab_tube[1]);
	if (ft_tube_aux(&tmp, &cur) == ERROR)
		return (ft_error_tube(&tab_tube));
	i = -1;
	while (tab_tube[++i])
		free(tab_tube[i]);
	return (ft_fruit(1, tab_tube) ? SUCCESS : SUCCESS);
}
