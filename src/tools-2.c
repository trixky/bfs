/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:52:18 by mabois            #+#    #+#             */
/*   Updated: 2020/05/23 11:52:21 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_str_to_nbr(t_af *af, char *str, int start, int end)
{
	int nbr;

	nbr = 0;
	while (start < end)
	{
		if (!ft_is_number(str[start]))
			ft_exit(af, 3);
		nbr *= 10;
		nbr += str[start] - 48;
		start++;
	}
	return (nbr);
}

int	ft_strcmp(char *a, int a_len, char *b, int b_len)
{
	int i;

	if (a_len != b_len)
		return (FALSE);
	i = -1;
	while (++i < a_len)
		if (a[i] != b[i])
			return (FALSE);
	return (TRUE);
}

void	ft_putnbr(int nbr)
{
	char c;

	if (nbr > 2147483647 || nbr < -2147483648)
		return ;
	if (nbr == -2147483648)
	{
		ft_putstr_fd("-2147483648", STDOUT_FILENO);
		return ;
	}
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putstr_fd("-", STDOUT_FILENO);
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		write(STDOUT_FILENO, &c, 1);
		return ;
	}
	ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(STDOUT_FILENO, &c, 1);
	return ;
}

void	ft_free_rooms_and_their_paths(t_af *af)
{
	t_room	*temp_room;
	t_room	*free_room;
	t_pipe	*temp_pipe;
	t_pipe	*free_pipe;

	temp_room = af->rooms;
	while (temp_room != NULL)
	{
		temp_pipe = temp_room->pipes;
		while (temp_pipe != NULL)
		{
			free_pipe = temp_pipe;
			temp_pipe = temp_pipe->next;
			ft_free(free_pipe);
		}
		free_room = temp_room;
		temp_room = temp_room->next;
		ft_free(free_room);
	}
}
