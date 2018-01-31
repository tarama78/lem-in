/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:33:04 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/31 14:13:23 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS		0
# define ERROR			1
# define FAIL			2
# define PATH_FOUND		3
# define PATH_END		4

# define OK_PAR			-1

typedef unsigned int		t_ui;
typedef unsigned long long	t_ull;
typedef long long			t_ll;

typedef enum		e_state
{
	START, END, NOT
}					t_state;

typedef enum		e_par
{
	VISITED, NO_VISITED, PATH
}					t_par;

typedef struct		s_room
{
	struct s_room	*next;
	struct s_room	*prev;
	char			*name;
	int				x;
	int				y;
	int				nb;
	int				weight;
	t_state			state;
	t_par			par;
	struct s_room	**tab;
}					t_room;

typedef struct		s_map
{
	struct s_map	*next;
	char			*str;
}					t_map;

typedef struct		s_path
{
	struct s_path	*next;
	t_room			*room;

}					t_path;

typedef struct		s_ret_path
{
	t_path			*path;
	int				size;
	int				first_ant;
	int				nb_ant;
	t_path			**room_ant;
	int				step;
}					t_ret_path;

typedef struct		s_check
{
	char			start : 1;
	char			end : 1;
	char			pad : 6;
}					t_check;

typedef struct		s_a
{
	t_room			**tab_end;
	t_path			*path;
	t_path			**tab_path;
	t_room			*room;
	t_room			*cur;
	t_room			**ant;
	t_map			*map;
	t_check			check;
	int				nb_path;
	int				*nb_ant_path;
	size_t			nb_ant;
	int				wait_start;
	int				wait_end;
}					t_a;

typedef struct		s_lst
{
	struct s_lst	*next;
}					t_lst;

void				ft_error(int nb);
int					ft_sz_lst(t_lst *lst);
void				ft_fruit_lst(t_lst *lst, void (*f)(t_lst *lst));
void				ft_print_path(t_a *a);
void				ft_dispatch(t_a *a);
int					ft_tube(t_a *a, char *line);
int					ft_check_nb_ants(t_a *a, char *str, int *i);
int					ft_coord(t_a *a, char **tab_coor);
int					ft_read(t_a *a);
int					ft_init_ant(t_a *a);
int					ft_algo(t_a *a);
void				ft_fruit_a(t_a *a);
void				ft_save_map(t_a *a, char *line);
void				ft_re_init(t_a *a);
t_room				*ft_init_start(t_a *a);
t_room				*ft_init_end(t_a *a);
int					ft_update_path(t_path **path, t_room *tmp);
int					ft_realloc_path(t_path ***tab_path, t_a *a);
int					ft_put_path(t_a *a);

#endif
