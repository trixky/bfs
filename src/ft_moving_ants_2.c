/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_ants_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 09:21:38 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/22 13:35:16 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_ants(t_af af, t_ant *ants)
{
	while (ants)
	{
		if (ants->room != af.room_end)
			return (FALSE);
		ants = ants->next;
	}
	return (TRUE);
}
