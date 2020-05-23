/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path-1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:51:03 by mabois            #+#    #+#             */
/*   Updated: 2020/05/23 11:51:06 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_pipe	*ft_find_best_room(t_af *af, t_room *room)
{
	int		best_dist;
	t_pipe	*new_pipe;
	t_pipe	*temp;
	t_room	*tr;

	best_dist = NOTHING;
	new_pipe = (t_pipe *)malloc(sizeof(t_pipe) * 1);
	new_pipe->room = NULL;
	new_pipe->next = NULL;
	temp = room->pipes;
	while (temp != NULL && ((tr = temp->room) || TRUE))
	{
		if (tr->reserved == FALSE && tr->dist != NOTHING && tr->type != END_ROOM
				&& (tr->dist < best_dist || best_dist == NOTHING) &&
				(room->type != END_ROOM || temp->room->type != START_ROOM ||
				af->path_start_end_finded == FALSE))
		{
			best_dist = tr->dist;
			new_pipe->room = tr;
		}
		temp = temp->next;
	}
	if (new_pipe->room != NULL && new_pipe->room->type != START_ROOM)
		new_pipe->room->reserved = TRUE;
	return (new_pipe);
}

t_room	*ft_find_last_room_path(t_pipe *path)
{
	t_pipe *temp;

	temp = path;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->room);
}

int		ft_path_is_valid(t_pipe *path)
{
	t_room	*last_room;

	last_room = ft_find_last_room_path(path);
	return (last_room != NULL && last_room->type == START_ROOM);
}

int		ft_path_len(t_pipe *path)
{
	int		len;
	t_pipe	*temp;

	len = 0;
	temp = path;
	while (temp->next != NULL)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

t_pipe	*ft_find_path(t_af *af)
{
	t_pipe	*path;
	t_pipe	*new_pipe;

	path = (t_pipe *)malloc(sizeof(t_pipe) * 1);
	path->room = af->room_end;
	path->next = NULL;
	new_pipe = NULL;
	while (ft_find_last_room_path(path) != NULL
	&& ft_find_last_room_path(path)->type != START_ROOM)
	{
		new_pipe = ft_find_best_room(af, ft_find_last_room_path(path));
		ft_push_back_pipe(path, new_pipe);
	}
	if (ft_path_is_valid(path) && ft_path_len(path) == 1)
		af->path_start_end_finded = TRUE;
	return (path);
}
