/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 09:07:35 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/22 09:11:40 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	ft_nb_pipe_start_end(t_af *af)
{
	int		i;
	t_pipe	*tmp;

	i = 0;
	tmp = af->room_start->pipes;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	af->start_pipe = i;
	i = 0;
	tmp = af->room_end->pipes;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	af->end_pipe = i;
}

static void		*ft_free_paths(t_path *paths)
{
	t_path *tmp;

	while (paths)
	{
		tmp = paths->next;
		ft_free_path(paths->path);
		free(paths);
		paths = tmp;
	}
	return (NULL);
}

static t_pipe	*ft_revers_path(t_af af, t_pipe *path)
{
	t_pipe *tmp;
	t_pipe *tmp2;
	t_pipe *current;

	current = path;
	tmp = current;
	while (1)
	{
		if (current->next == NULL)
			break ;
		tmp2 = current->next;
		current->next = tmp;
		tmp = current;
		current = tmp2;
	}
	path->next = NULL;
	current->next = tmp;
	return (current);
}

static t_path	*ft_add_paths(t_af af, t_path *paths, t_pipe *path)
{
	t_path *tmp;

	if (!(tmp = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	tmp->path = path;
	tmp->nb_ants = 0;
	tmp->next = NULL;
	tmp->length = ft_path_len(path);
	if (!paths)
	{
		paths = tmp;
		paths->last = tmp;
	}
	else
	{
		paths->last->next = tmp;
		paths->last = tmp;
	}
	return (paths);
}

void			*ft_ants(t_af *af)
{
	t_path	*paths;
	t_path	*tmp_path;
	t_pipe	*temp_path;
	int		i;

	i = 0;
	ft_nb_pipe_start_end(af);
	ft_show_rooms(af);
	paths = NULL;
	while (1)
	{
		if (i == af->start_pipe || i == af->end_pipe)
			break ;
		ft_bfs(af);
		if (!(temp_path = ft_find_path(af)))
			break ;
		if (ft_path_len(temp_path) == 1 || !ft_path_is_valid(temp_path))
			break ;
		if (!(paths = ft_add_paths(*af, paths, ft_revers_path(*af, temp_path))))
			return (ft_free_paths(paths));
		i++;
	}
	!paths ? ft_exit(af, 16) : 0;
	ft_display_ants_move(af, paths);
	return (ft_free_paths(paths));
}
