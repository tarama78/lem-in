/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:35:07 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/30 12:08:43 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	ft_error(int nb)
{
	if (nb == ERROR)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(1);
	}
}
