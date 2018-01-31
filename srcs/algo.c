/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:37:23 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/31 14:45:16 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | algo.c                                                   |
**   |     ft_get_min(13 lines)                                 |
**   |     ft_resolve(23 lines)                                 |
**   |     ft_dji_aux(9 lines)                                  |
**   |     ft_dji(25 lines)                                     |
**   |     ft_algo(9 lines)                                     |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <lem_in.h>

static t_room		*ft_get_min(t_a *a)
{
	t_room	*min;
	t_room	*tmp;

	min = NULL;
	tmp = a->room;
	while (tmp != NULL)
	{
		if (tmp->weight > OK_PAR && tmp->par == NO_VISITED)
			if (min == NULL || tmp->weight < min->weight)
			{
				min = tmp;
				if (min->state == END)
					break ;
			}
		tmp = tmp->next;
	}
	return (min);
}

static int			ft_resolve(t_a *a)
{
	t_room	*end;
	t_room	*tmp;
	t_path	*path;

	end = ft_init_end(a);
	tmp = end;
	path = NULL;
	if (ft_update_path(&path, tmp) == ERROR)
		return (ERROR);
	while (tmp->state != START)
	{
		tmp = tmp->prev;
		if (tmp->state != START)
			tmp->par = PATH;
		if (ft_update_path(&path, tmp) == ERROR)
			return (ERROR);
	}
	a->path = path;
	if (ft_put_path(a) == ERROR)
		return (ERROR);
	return (PATH_FOUND);
}

static int			ft_dji_aux(t_a *a)
{
	t_room	*end;

	end = ft_init_end(a);
	if (end->weight == OK_PAR)
		return (PATH_END);
	if (ft_resolve(a) == ERROR)
		return (ERROR);
	ft_re_init(a);
	return (PATH_FOUND);
}

static int			ft_dji(t_a *a)
{
	t_room	*parent;
	int		i;
	t_room	*start;

	start = ft_init_start(a);
	start->weight = 0;
	while ((parent = ft_get_min(a)) != NULL)
	{
		parent->par = VISITED;
		if ((i = -1) && parent->state == END)
			break ;
		while (parent->tab && parent->tab[++i] != NULL)
		{
			if (parent->tab[i]->par == NO_VISITED)
			{
				if (parent->weight + 1 < parent->tab[i]->weight ||
						parent->tab[i]->weight == OK_PAR)
				{
					parent->tab[i]->weight = parent->weight + 1;
					parent->tab[i]->prev = parent;
				}
			}
		}
	}
	return (ft_dji_aux(a));
}

int					ft_algo(t_a *a)
{
	int		result;

	a->nb_path = 0;
	result = ft_dji(a);
	while (result == PATH_FOUND)
	{
		if (a->path->next->next == NULL)
			break ;
		result = ft_dji(a);
	}
	if (result == ERROR)
		return (ERROR);
	return (SUCCESS);
}
