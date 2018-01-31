/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:58:21 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/30 16:53:17 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | main.c                                                   |
**   |     main(17 lines)                                       |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <lem_in.h>

int				main(int argc, char **argv)
{
	t_a		a;

	(void)argv;
	(void)argc;
	if (ft_read(&a) == FAIL)
	{
		ft_fruit_a(&a);
		ft_errprintf("Error\n");
		return (EXIT_FAILURE);
	}
	if (ft_init_ant(&a) == SUCCESS)
	{
		if (ft_algo(&a) == ERROR)
		{
			ft_fruit_a(&a);
			return (EXIT_FAILURE);
		}
		ft_dispatch(&a);
	}
	ft_fruit_a(&a);
	return (EXIT_SUCCESS);
}
