/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:31:10 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/31 14:52:42 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | lem_in.c                                                 |
**   |     ft_room(20 lines)                                    |
**   |     ft_handle_instruct(20 lines)                         |
**   |     ft_init_a(11 lines)                                  |
**   |     ft_read(25 lines)                                    |
**   |     ft_init_ant(20 lines)                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <lem_in.h>

static int		ft_room(t_a *a, char *line)
{
	char	**tab;
	int		i;
	int		ret;

	i = 0;
	if (ft_strchr(line, '-') != NULL)
		return (ft_tube(a, line));
	if (!(tab = ft_strsplit(line, ' ')))
		return (ERROR);
	while (tab[++i])
		;
	if (i == 3)
		ret = ft_coord(a, tab);
	else
		ret = ERROR;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (ret);
}

static int		ft_handle_instruct(t_a *a, char *line)
{
	static int	i = 0;

	if (line == NULL || line[0] == '\0')
		return (ERROR);
	else if (i == 0)
		return (ft_check_nb_ants(a, line, &i));
	else if (ft_strcmp(line, "##start") == 0 && a->check.start == 0)
	{
		a->wait_start = 1;
		return (SUCCESS);
	}
	else if (ft_strcmp(line, "##end") == 0 && a->check.end == 0)
	{
		a->wait_end = 1;
		return (SUCCESS);
	}
	else if (line[0] == '#')
		return (SUCCESS);
	else
		return (ft_room(a, line));
}

static void		ft_init_a(t_a *a)
{
	a->room = NULL;
	a->cur = NULL;
	a->map = NULL;
	a->path = NULL;
	a->tab_path = NULL;
	a->nb_ant_path = NULL;
	a->ant = NULL;
	a->nb_ant = 0;
	a->wait_start = 0;
	a->wait_end = 0;
	*(char *)&a->check = 0;
}

int				ft_read(t_a *a)
{
	int		i;
	char	*line;

	ft_init_a(a);
	i = GNL_LINE_READ;
	line = NULL;
	while (i == GNL_LINE_READ)
	{
		line = NULL;
		if ((i = get_next_line(STDIN_FILENO, &line)) == GNL_ERROR)
			return (FAIL);
		if (i == GNL_END)
		{
			free(line);
			break ;
		}
		if (ft_handle_instruct(a, line) == ERROR)
		{
			free(line);
			return ((*(char*)&a->check == 3) ? ERROR : FAIL);
		}
		ft_save_map(a, line);
		free(line);
	}
	return ((*(char*)&a->check == 3) ? SUCCESS : FAIL);
}

int				ft_init_ant(t_a *a)
{
	t_room		*room;
	int			i;

	room = a->room;
	while (room)
	{
		if (room->state == START)
			break ;
		room = room->next;
	}
	if (room == NULL)
		return (ERROR);
	room->nb = a->nb_ant;
	if (!(a->ant = malloc(sizeof(t_room*) * (a->nb_ant + 1))))
		return (ERROR);
	a->ant[a->nb_ant] = NULL;
	i = -1;
	while (++i < (int)a->nb_ant)
		a->ant[i] = room;
	return (SUCCESS);
}
