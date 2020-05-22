/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 09:05:23 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/22 13:47:06 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	*ft_move_ants_2(t_ant *ants, t_ant *moved_ants)
{
	t_ant *tmp;

	ants->room->ant = 0;
	ants->room->ptrant = NULL;
	ants->room = ants->next_path->room;
	ants->next_path = ants->next_path->next;
	ants->room->ptrant = ants;
	ants->room->ant = 1;
	if (!moved_ants)
		moved_ants = ants;
	else
	{
		tmp = moved_ants;
		while (tmp->next_moved)
			tmp = tmp->next_moved;
		tmp->next_moved = ants;
	}
	return (moved_ants);
}

t_ant	*ft_move_ants(t_af af, t_ant *ants, t_path *paths)
{
	t_ant *moved_ants;
	t_ant *tmp;

	moved_ants = NULL;
	while (ants)
	{
		if (ants->room != af.room_end)
		{
			ants->next_moved = NULL;
			if (ants->next_path->room->ant == 0
			|| ants->next_path->room == af.room_end)
			{
				moved_ants = ft_move_ants_2(ants, moved_ants);
			}
		}
		ants = ants->next;
	}
	return (moved_ants);
}

void	ft_moving_ants(t_af af, t_ant *ants, t_path *paths)
{
	t_ant *moved_ants;

	ft_direct_ants(af, ants, paths);
	while (!ft_check_ants(af, ants))
	{
		moved_ants = ft_move_ants(af, ants, paths);
		ft_print_move(af, moved_ants);
	}
}
