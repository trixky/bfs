#include "lem_in.h"

int 	ft_is_pipe_line(t_af *af, int pos)
{
	int i;

	i = 0;
	while (af->conf[pos] && af->conf[pos] != '-')
	{
		if (af->conf[pos] == '\n' || !ft_is_room_char(af->conf[pos]))
			return (FALSE);
		pos++;
	}
	if (af->conf[pos++] != '-')
		return (FALSE);
	while (af->conf[pos] && af->conf[pos] != '\n')
	{
		if (!ft_is_room_char(af->conf[pos]))
			return (FALSE);
		pos++;
	}
	return (TRUE);
}

int		ft_parse_pipe_line(t_af *af, int pos)
{
	int 	start;
	t_room	*room_a;
	t_room	*room_b;


	start = pos;
	while (af->conf[pos] && af->conf[pos] != '-')
	{
		pos++;
	}
	room_a = ft_find_room(af, start, pos);
	pos++;
	start = pos;
	while (af->conf[pos] && af->conf[pos] != '\n')
	{
		pos++;
	}
	room_b = ft_find_room(af, start, pos);
	if (room_a == NULL || room_b == NULL)
		ft_exit(af, 13);
	ft_add_pipe(af, room_a, room_b);
	return (++pos);
}

