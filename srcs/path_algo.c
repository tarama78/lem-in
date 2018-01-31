/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:24:33 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/30 12:08:43 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | path_algo.c                                              |
**   |     ft_update_path(8 lines)                              |
**   |     ft_realloc_path(16 lines)                            |
**   |     ft_put_path(11 lines)                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <lem_in.h>

int			ft_update_path(t_path **path, t_room *tmp)
{
	t_path	*new_path;

	if (!(new_path = malloc(sizeof(t_path))))
		return (ERROR);
	new_path->room = tmp;
	new_path->next = *path;
	*path = new_path;
	return (SUCCESS);
}

int			ft_realloc_path(t_path ***tab_path, t_a *a)
{
	int		i;
	t_path	**new;

	i = 0;
	while ((*tab_path)[i])
		++i;
	if (!(new = (t_path **)malloc(sizeof(t_path *) * (i + 2))))
		return (ERROR);
	i = -1;
	while ((*tab_path)[++i] != NULL)
		new[i] = (*tab_path)[i];
	new[i] = a->path;
	new[++i] = NULL;
	ft_fruit(1, *tab_path);
	(*tab_path) = new;
	return (SUCCESS);
}

int			ft_put_path(t_a *a)
{
	a->nb_path++;
	if (a->tab_path == NULL)
	{
		if (!(a->tab_path = (t_path **)malloc(sizeof(t_path *) * 2)))
			return (ERROR);
		a->tab_path[0] = a->path;
		a->tab_path[1] = NULL;
	}
	else if (ft_realloc_path(&(a->tab_path), a) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
