/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 09:03:56 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/22 12:26:32 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	*ft_free_ants(t_ant *begin, int size)
{
	t_ant	*tmp;
	int		i;

	i = 0;
	tmp = begin;
	while (i++ < size && tmp)
	{
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
	return (NULL);
}

t_ant	*ft_create_ant(int ant_id)
{
	t_ant *ret;

	if (!(ret = malloc(sizeof(t_ant))))
		return (NULL);
	ret->ant_id = ant_id;
	ret->next = NULL;
	ret->room = NULL;
	ret->end = FALSE;
	return (ret);
}

t_ant	*ft_init_ants(int nb_ants, t_room *start)
{
	int		i;
	t_ant	*begin;
	t_ant	*tmp;
	t_ant	*last;

	begin = NULL;
	i = 0;
	while (++i <= nb_ants)
	{
		if (!(tmp = ft_create_ant(i)))
			return (ft_free_ants(begin, i));
		tmp->room = start;
		tmp->next_moved = NULL;
		begin != NULL ? last->next = tmp : 0;
		begin != NULL ? last = tmp : 0;
		begin == NULL ? last = tmp : 0;
		begin == NULL ? begin = tmp : 0;
	}
	return (begin);
}

void	ft_print_move(t_af af, t_ant *ants)
{
	while (ants)
	{
		write(STDOUT_FILENO, "L", 1);
		ft_putnbr(ants->ant_id);
		write(STDOUT_FILENO, "-", 1);
		write(STDOUT_FILENO, af.conf + ants->room->name_pos_start,
		ants->room->name_pos_end - ants->room->name_pos_start);
		if (ants->next)
			write(STDOUT_FILENO, " ", 1);
		ants->room->ant = 0;
		ants = ants->next_moved;
	}
	write(STDOUT_FILENO, "\n", 1);
}

char	*ft_display_ants_move(t_af *af, t_path *paths)
{
	t_ant *ants;

	if (!(ants = ft_init_ants(af->ant, af->room_start)))
		return (NULL);
	ft_moving_ants(*af, ants, paths);
	ft_free_ants(ants, af->ant);
	return (NULL);
}
