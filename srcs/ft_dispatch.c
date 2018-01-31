/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:23:28 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/31 14:21:41 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_dispatch.c                                            |
**   |     ft_print_all(9 lines)                                |
**   |     ft_choose_path2(23 lines)                            |
**   |     ft_choose_path(20 lines)                             |
**   |     ft_dispatch(9 lines)                                 |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <lem_in.h>

static void	ft_print_all(t_a *a)
{
	t_map	*map;

	map = a->map;
	while (map)
	{
		ft_printf("%s\n", map->str);
		map = map->next;
	}
}

static int	ft_choose_path2(t_a *a, int nb_p_use, int i, int sz)
{
	if ((int)a->nb_ant - sz < 0)
	{
		if (nb_p_use == 1)
		{
			a->nb_ant_path[0] = a->nb_ant;
			return (SUCCESS);
		}
		a->nb_ant_path[nb_p_use - 1] = 0;
		return (ERROR);
	}
	else
	{
		i = -1;
		while (a->nb_ant_path[++i])
			a->nb_ant_path[i] = (a->nb_ant - sz) / nb_p_use +
				(ft_sz_lst((t_lst*)a->tab_path[nb_p_use - i - 1]) -
				ft_sz_lst((t_lst*)a->tab_path[0]));
		i = (a->nb_ant - sz) % nb_p_use + 1;
		while (--i > 0)
			a->nb_ant_path[i]++;
		return (SUCCESS);
	}
	return (SUCCESS);
}

static void	ft_choose_path(t_a *a)
{
	int		nb_p_use;
	int		i;
	int		sz;

	i = 0;
	ft_error(!(a->nb_ant_path = malloc(sizeof(int) * (a->nb_path + 1))));
	a->nb_ant_path[a->nb_path] = 0;
	nb_p_use = -1;
	while (++nb_p_use < a->nb_path)
		a->nb_ant_path[nb_p_use] = 1;
	while (42)
	{
		nb_p_use = -1;
		sz = 0;
		while (a->nb_ant_path[++nb_p_use])
			sz += ft_sz_lst((t_lst*)a->tab_path[nb_p_use]) -
				ft_sz_lst((t_lst*)a->tab_path[0]);
		if (ft_choose_path2(a, nb_p_use, i, sz) == SUCCESS)
			return ;
	}
}

void		ft_dispatch(t_a *a)
{
	if (a->tab_path == NULL)
	{
		ft_errprintf("Error\n");
		return ;
	}
	ft_print_all(a);
	ft_choose_path(a);
	ft_print_path(a);
	free(a->nb_ant_path);
}
