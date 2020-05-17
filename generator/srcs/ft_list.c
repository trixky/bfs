/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 01:08:52 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/17 12:03:22 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_generator.h"

t_link	*ft_create_link(int room_id)
{
	t_link *ret;

	if (!(ret = malloc(sizeof(t_link))))
		return (NULL);
	ret->room_id = room_id;
	ret->nb = 0;
	ret->next = NULL;
	return (ret);
}

t_link	**ft_init_list(int size)
{
	t_link	**ret;
	int		i;

	i = 0;
	if (!(ret = (t_link **)malloc(sizeof(t_link*) * size)))
		return (NULL);
	while (i < size)
		ret[i++] = NULL;
	return (ret);
}

void	ft_free_list(t_link **list, int size)
{
	int		i;
	t_link	*tmp;
	t_link	*current;

	i = 0;
	while (i < size)
	{
		current = list[i++];
		while (current)
		{
			tmp = current;
			current = current->next;
			free(tmp);
		}
	}
	free(list);
}
