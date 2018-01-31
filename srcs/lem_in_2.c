/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:25:07 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/31 14:23:05 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | lem_in_2.c                                               |
**   |     ft_check_nb(15 lines)                                |
**   |     ft_check_nb_ants(6 lines)                            |
**   |     ft_state_update(25 lines)                            |
**   |     ft_coord(22 lines)                                   |
**   |     ft_save_map(17 lines)                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <lem_in.h>

static int		ft_check_nb(char *s, int *nb)
{
	int		i;
	t_ll	nb_ll;

	i = (s[0] == '-') ? 0 : -1;
	while (ft_isdigit(s[++i]) && s[i])
		;
	if (s[i] != '\0')
		return (ERROR);
	if (i > 12)
		return (ERROR);
	nb_ll = ft_atol(s);
	if (nb_ll > INT_MAX || nb_ll < INT_MIN)
		return (ERROR);
	*nb = (int)nb_ll;
	return (SUCCESS);
}

int				ft_check_nb_ants(t_a *a, char *str, int *i)
{
	if (str[0] == '#')
		return (SUCCESS);
	if (ft_check_nb(str, (int*)&a->nb_ant) == ERROR)
		return (ERROR);
	++(*i);
	return (SUCCESS);
}

static void		ft_state_update(t_a *a, t_room *tmp)
{
	tmp->state = NOT;
	if (a->wait_start == 1)
	{
		tmp->state = START;
		a->check.start = 1;
		a->wait_start = 0;
	}
	else if (a->wait_end == 1)
	{
		tmp->state = END;
		a->check.end = 1;
		a->wait_end = 0;
	}
	tmp->weight = OK_PAR;
	tmp->par = NO_VISITED;
	if (a->room == NULL)
	{
		a->room = tmp;
		a->cur = tmp;
	}
	else
	{
		a->cur->next = tmp;
		a->cur = tmp;
	}
}

int				ft_coord(t_a *a, char **tab_coor)
{
	int		i;
	int		j;
	t_room	*tmp;

	i = 0;
	while (tab_coor[++i] && i < 3)
		if (ft_check_nb(tab_coor[i], &j) == ERROR)
			return (ERROR);
	if (!(tmp = (t_room *)malloc(sizeof(t_room))))
		return (ERROR);
	tmp->x = ft_atoi(tab_coor[1]);
	tmp->y = ft_atoi(tab_coor[2]);
	if (tab_coor[0][0] == 'L')
		return (ERROR);
	tmp->name = ft_strnew(ft_strlen(tab_coor[0]));
	tmp->name = ft_strcpy(tmp->name, tab_coor[0]);
	tmp->nb = 0;
	tmp->tab = NULL;
	tmp->prev = NULL;
	tmp->next = NULL;
	ft_state_update(a, tmp);
	return (SUCCESS);
}

void			ft_save_map(t_a *a, char *line)
{
	t_map	*new;
	t_map	*last;

	ft_error(!(new = malloc(sizeof(t_map))));
	ft_error(!(new->str = ft_strdup(line)));
	new->next = NULL;
	if (a->map == NULL)
	{
		a->map = new;
		return ;
	}
	last = a->map;
	while (last->next)
	{
		last = last->next;
	}
	last->next = new;
}
