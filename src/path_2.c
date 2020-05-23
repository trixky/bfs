/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path-2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:51:11 by mabois            #+#    #+#             */
/*   Updated: 2020/05/23 11:51:12 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_pipe	*ft_free_path(t_pipe *path)
{
	t_pipe *temp;
	t_pipe *temp_free;

	temp = path;
	while (temp != NULL)
	{
		temp_free = temp;
		temp = temp->next;
		temp_free = ft_free(temp_free);
	}
	return (NULL);
}
