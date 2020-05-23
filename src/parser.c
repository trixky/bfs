/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:50:47 by mabois            #+#    #+#             */
/*   Updated: 2020/05/23 11:50:54 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_parse_ant(t_af *af, int pos)
{
	int start;

	pos = ft_evaluate_commande(af, pos);
	start = pos;
	while (af->conf[pos] && af->conf[pos] != '\n')
		if (!af->conf[++pos])
			ft_exit(af, 2);
	af->ant = ft_str_to_nbr(af, af->conf, start, pos);
	if (af->ant == 0 ||
			af->next_is_start != NOTHING ||
			af->next_is_end != NOTHING)
		ft_exit(af, 4);
	return (++pos);
}

int		ft_parse_rooms(t_af *af, int pos)
{
	int last_pos;

	last_pos = NOTHING;
	while (last_pos != pos)
	{
		last_pos = pos;
		pos = ft_evaluate_commande(af, pos);
		if (!ft_is_room_line(af, pos))
			return (pos);
		pos = ft_parse_room_line(af, pos);
	}
	return (pos);
}

int		ft_parse_pipes(t_af *af, int pos)
{

	int last_pos;

	last_pos = NOTHING;
	while (last_pos != pos)
	{
		last_pos = pos;
		pos = ft_evaluate_commande(af, pos);
		if (!ft_is_pipe_line(af, pos))
			return (pos);
		pos = ft_parse_pipe_line(af, pos);
	}
	return (pos);
}

void	ft_parser(t_af *af)
{
	int pos;

	if (af->conf == NULL || af->conf[0] == '\0')
		ft_exit(af, 15);
	pos = ft_parse_pipes(af, ft_parse_rooms(af, ft_parse_ant(af, 0)));
	if (af->conf[pos] != '\0')
		ft_exit(af, 9);
	if (af->room_start == NULL || af->room_end == NULL)
		ft_exit(af, 14);
}
