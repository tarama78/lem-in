/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:29:07 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/30 12:28:09 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_next_step.c                                           |
**   |     ft_move_ant(14 lines)                                |
**   |     ft_exec_step(11 lines)                               |
**   |     ft_next_step(20 lines)                               |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <visu_hex.h>

static void	ft_move_ant(t_b *b, char *name, int n)
{
	int		i;

	--n;
	b->a->ant[n]->nb--;
	i = -1;
	while (b->a->ant[n]->tab[++i] != NULL)
	{
		if (ft_strcmp(b->a->ant[n]->tab[i]->name, name) == 0)
			break ;
	}
	if (b->a->ant[n]->tab[i] == NULL)
	{
		ft_close(b);
		ft_error2(__FILE__, (char*)__func__, __LINE__, "Forbidden path");
	}
	b->a->ant[n] = b->a->ant[n]->tab[i];
	b->a->ant[n]->nb++;
}

static void	ft_exec_step(t_b *b, char *step)
{
	char	*name;
	int		n;

	n = ft_atoi(++step);
	while (ft_isdigit(*step))
		++step;
	if (n == 0 || *step != '-')
	{
		ft_close(b);
		ft_error2(__FILE__, (char*)__func__, __LINE__,
				"Move not well formated");
	}
	name = ++step;
	ft_move_ant(b, name, n);
}

void		ft_next_step(t_b *b)
{
	char	*line;
	char	**step;
	int		i;
	int		ret;

	if ((ret = get_next_line(STDIN_FILENO, &line)) == GNL_LINE_READ)
	{
		step = ft_strsplit(line, ' ');
		i = -1;
		while (step[++i])
		{
			ft_exec_step(b, step[i]);
			free(step[i]);
		}
		free(step);
		free(line);
		b->step++;
	}
	else if (ret == GNL_ERROR)
		ft_error2(__FILE__, (char*)__func__, __LINE__, NULL);
}
