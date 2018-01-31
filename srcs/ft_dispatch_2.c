/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:31:34 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/31 17:13:23 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_dispatch_2.c                                          |
**   |     ft_move_ant(2 lines)                                 |
**   |     ft_get_next_path(25 lines)                           |
**   |     ft_fruit_ret_path(9 lines)                           |
**   |     ft_set_path_print(25 lines)                          |
**   |     ft_print_path(22 lines)                              |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <lem_in.h>

static void	ft_move_ant(t_ret_path *ret_path, int ant_act)
{
	if (ret_path->room_ant[ant_act]->next)
		ret_path->room_ant[ant_act] = ret_path->room_ant[ant_act]->next;
}

static int	ft_get_next_path(t_ret_path *ret_path, int *write)
{
	int		i;
	int		space;

	if (ret_path->nb_ant == 0 || ret_path->step == ret_path->nb_ant +
			ret_path->size)
		return (GNL_END);
	if ((i = -1) && *write)
		ft_printf(" ");
	space = 0;
	while (++i < ret_path->nb_ant && i <= ret_path->step)
	{
		if (space)
			ft_printf(" ");
		if (ret_path->room_ant[i]->room->state != END)
		{
			*write = 1;
			space = 1;
			ft_move_ant(ret_path, i);
			ft_printf("L%d-%s", ret_path->first_ant + i,
					ret_path->room_ant[i]->room->name);
		}
	}
	if (++ret_path->step == ret_path->nb_ant + ret_path->size)
		return (GNL_END);
	return (GNL_LINE_READ);
}

static void	ft_fruit_ret_path(t_a *a, t_ret_path **ret_path)
{
	int		i;

	i = -1;
	while (++i < a->nb_path)
	{
		free(ret_path[i]->room_ant);
		free(ret_path[i]);
	}
	free(ret_path);
}

static void	ft_set_path_print(t_a *a, t_ret_path ***ret_path)
{
	int		i;
	int		j;

	ft_error(!(*ret_path = malloc(sizeof(t_ret_path*) * (a->nb_path + 1))));
	(*ret_path)[a->nb_path] = NULL;
	i = -1;
	while (++i < a->nb_path)
	{
		ft_error(!((*ret_path)[i] = malloc(sizeof(t_ret_path))));
		(*ret_path)[i]->path = a->tab_path[i];
		if (i == 0)
			(*ret_path)[i]->first_ant = 1;
		else
			(*ret_path)[i]->first_ant = (*ret_path)[i - 1]->first_ant +
				a->nb_ant_path[i - 1];
		(*ret_path)[i]->size = ft_sz_lst((t_lst*)(*ret_path)[i]->path);
		(*ret_path)[i]->nb_ant = a->nb_ant_path[i];
		ft_error(!((*ret_path)[i]->room_ant = malloc(sizeof(t_path*) *
						((int64_t)(*ret_path)[i]->nb_ant + 1))));
		(*ret_path)[i]->room_ant[(*ret_path)[i]->nb_ant] = NULL;
		j = -1;
		while (++j < (*ret_path)[i]->nb_ant)
			(*ret_path)[i]->room_ant[j] = (*ret_path)[i]->path;
		(*ret_path)[i]->step = 0;
	}
}

void		ft_print_path(t_a *a)
{
	t_ret_path	**ret_path;
	int			i;
	int			j;
	int			end;

	ft_set_path_print(a, &ret_path);
	ft_printf("\n");
	end = 0;
	while (end == 0)
	{
		j = 0;
		end = 1;
		i = -1;
		while (++i < (int)a->nb_path)
		{
			if (ft_get_next_path(ret_path[i], &j) == GNL_LINE_READ)
				end = 0;
		}
		if (j == 1)
			ft_printf("\n");
	}
	ft_fruit_ret_path(a, ret_path);
}
