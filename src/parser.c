#include "lem_in.h"

int		ft_parse_ant(t_af *af, int pos)
{
	int start;
	printf("****************** ft_parse_ant\n");

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
	printf("****************** ft_parse_rooms\n");
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
	printf("****************** ft_parse_pipes\n");

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

	pos = ft_parse_pipes(af, ft_parse_rooms(af, ft_parse_ant(af, 0)));
	printf("************************* ft_parser FINAL [%s][%d]\n", af->conf + pos - 3, af->conf[pos]);
	if (af->conf[pos] != '\0')
		ft_exit(af, 9);

}