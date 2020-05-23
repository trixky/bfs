/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direct_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:37:13 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/23 14:35:03 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*ft_best_path(t_path *paths)
{
	t_path *tmp;

	tmp = paths;
	while (paths)
	{
		if ((tmp->nb_ants + tmp->length) > (paths->nb_ants + paths->length))
			tmp = paths;
		paths = paths->next;
	}
	return (tmp);
}

void	ft_direct_ants(t_ant *ants, t_path *paths)
{
	t_path	*tmp;

	while (ants)
	{
		tmp = ft_best_path(paths);
		ants->next_path = tmp->path->next;
		tmp->nb_ants++;
		ants = ants->next;
	}
}
