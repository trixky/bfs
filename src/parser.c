#include "lem_in.h"

int		ft_skip_comment(t_af *af, int pos)
{
	if (!af->conf[pos])
		ft_exit(af, 1);
	if (af->conf[pos] && af->conf[pos] == '#'
			&& af->conf[pos + 1] && af->conf[pos + 1] != '#')
		while (af->conf[pos] && af->conf[pos] != '\n')
			pos++;
	else
		return (pos);	
	return (ft_skip_comment(af, ++pos));
}

int		ft_parse_ant(t_af *af, int pos)
{
	int start;

	pos = ft_skip_comment(af, pos);
	start = pos;
	while (af->conf[pos] && af->conf[pos] != '\n')
		if (!af->conf[++pos])
			ft_exit(af, 2);
	af->ant = ft_str_to_nbr(af, af->conf, start, pos);
	if (af->ant == 0)
		ft_exit(af, 4);
	return (pos);
}

int		ft_parse_rooms(t_af *af, int pos)
{

	return (pos);
}

int		ft_parse_pipes(t_af *af, int pos)
{

	return (pos);
}

void	ft_parser(t_af *af)
{
	ft_parse_pipes(af, ft_parse_rooms(af, ft_parse_ant(af, 0)));
}