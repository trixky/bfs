/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes-1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:51:21 by mabois            #+#    #+#             */
/*   Updated: 2020/05/23 11:51:22 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_pipe_already_exist(t_af *af, t_room *room_a, t_room *room_b)
{
	t_pipe *temp_pipe_a;

	temp_pipe_a = room_a->pipes;
	while (temp_pipe_a != NULL)
	{
		if (temp_pipe_a->room->name_pos_start == room_b->name_pos_start)
			return (TRUE);
		temp_pipe_a = temp_pipe_a->next;
	}
	return (FALSE);
}

void	ft_add_pipe(t_af *af, t_room *room_a, t_room *room_b)
{
	t_pipe *temp_pipe_a;
	t_pipe *temp_pipe_b;
	t_pipe *new_pipe_a;
	t_pipe *new_pipe_b;

	if (ft_room_cmp(room_a, room_b))
		ft_exit(af, 11);
	if (ft_pipe_already_exist(af, room_a, room_b))
		ft_exit(af, 12);
	new_pipe_a = (t_pipe *)malloc(sizeof(t_pipe) * 1);
	new_pipe_a->room = room_b;
	new_pipe_a->next = NULL;
	temp_pipe_a = room_a->pipes;
	if (temp_pipe_a == NULL)
		room_a->pipes = new_pipe_a;
	else
	{
		while (temp_pipe_a->next != NULL)
			temp_pipe_a = temp_pipe_a->next;
		temp_pipe_a->next = new_pipe_a;
	}
	new_pipe_b = (t_pipe *)malloc(sizeof(t_pipe) * 1);
	new_pipe_b->room = room_a;
	new_pipe_b->next = NULL;
	temp_pipe_b = room_b->pipes;
	if (temp_pipe_b == NULL)
		room_b->pipes = new_pipe_b;
	else
	{
		while (temp_pipe_b->next != NULL)
			temp_pipe_b = temp_pipe_b->next;
		temp_pipe_b->next = new_pipe_b;
	}
}

t_pipe	*ft_push_back_pipe(t_pipe *pipes, t_pipe *pipe)
{
	t_pipe *temp;

	if (pipes == NULL)
		return (pipe);
	if (pipe == NULL)
		return (pipes);
	temp = pipes;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = pipe;
	return (pipes);
}

t_pipe	*ft_pop_front_pipe(t_pipe *pipes)
{
	t_pipe *temp;

	if (pipes != NULL)
	{
		if (pipes->next == NULL)
			return (ft_free(pipes));
		temp = pipes;
		pipes = pipes->next;
		temp = ft_free(temp);
	}
	return (pipes);
}
