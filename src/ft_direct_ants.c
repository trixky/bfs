/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direct_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:37:13 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/22 13:49:27 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*ft_best_path(t_path *paths, int i)
{
	if (!paths)
		return (NULL);
	if (paths->next && paths->length > i + paths->length)
		ft_best_path(paths->next, i);
	return (paths);
}

void	ft_direct_ants(t_af af, t_ant *ants, t_path *paths)
{
	int		i;
	t_path	*tmp;

	i = 0;
	tmp = NULL;
	while (ants)
	{
		if (!tmp)
			tmp = paths;
		if (tmp->length / (af.ant - i) || tmp == paths)
		{
			ants->next_path = tmp->path->next;
			ants = ants->next;
			i++;
		}
		tmp = tmp->next;
	}
}
