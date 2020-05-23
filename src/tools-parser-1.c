/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools-parser-1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:52:38 by mabois            #+#    #+#             */
/*   Updated: 2020/05/23 11:52:39 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_skip_comment(t_af *af, int pos)
{
	if (af->conf[pos] && af->conf[pos] == '#'
			&& af->conf[pos + 1] && af->conf[pos + 1] != '#')
		while (af->conf[pos] && af->conf[pos] != '\n')
			pos++;
	else
		return (pos);
	return (ft_skip_comment(af, ++pos));
}

int		ft_parse_start_command_line(t_af *af, int pos)
{
	if (af->conf[pos] && af->conf[pos] == '#' &&
			af->conf[pos + 1] && af->conf[pos + 1] == '#' &&
			af->conf[pos + 2] && af->conf[pos + 2] == 's' &&
			af->conf[pos + 3] && af->conf[pos + 3] == 't' &&
			af->conf[pos + 4] && af->conf[pos + 4] == 'a' &&
			af->conf[pos + 5] && af->conf[pos + 5] == 'r' &&
			af->conf[pos + 6] && af->conf[pos + 6] == 't' &&
			af->conf[pos + 7] && af->conf[pos + 7] == '\n')
	{
		if (af->next_is_start != NOTHING ||
				af->next_is_end == TRUE)
			ft_exit(af, 5);
		af->next_is_start = TRUE;
		pos += 8;
	}
	return (pos);
}

int		ft_parse_end_command_line(t_af *af, int pos)
{
	if (af->conf[pos] && af->conf[pos] == '#' &&
			af->conf[pos + 1] && af->conf[pos + 1] == '#' &&
			af->conf[pos + 2] && af->conf[pos + 2] == 'e' &&
			af->conf[pos + 3] && af->conf[pos + 3] == 'n' &&
			af->conf[pos + 4] && af->conf[pos + 4] == 'd' &&
			af->conf[pos + 5] && af->conf[pos + 5] == '\n')
	{
		if (af->next_is_end != NOTHING ||
				af->next_is_start == TRUE)
			ft_exit(af, 6);
		af->next_is_end = TRUE;
		pos += 6;
	}
	return (pos);
}

int		ft_parse_unknown_command_line(t_af *af, int pos)
{
	if (af->conf[pos] && af->conf[pos] == '#' &&
			af->conf[pos + 1] && af->conf[pos + 1] == '#')
	{
		while (af->conf[pos] && af->conf[pos] != '\n')
			pos++;
		pos++;
	}
	return (pos);
}

int		ft_evaluate_commande(t_af *af, int pos)
{
	int last_pos;

	last_pos = NOTHING;
	while (last_pos != pos)
	{
		last_pos = pos;
		pos = ft_parse_start_command_line(af, pos);
		pos = ft_parse_end_command_line(af, pos);
		pos = ft_parse_unknown_command_line(af, pos);
		pos = ft_skip_comment(af, pos);
	}
	return (pos);
}
