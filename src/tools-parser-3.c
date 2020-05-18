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
	printf("-------- ft_is_pipe_line\n");
	return (TRUE);
}

int		ft_parse_pipe_line(t_af *af, int pos)
{
	int i;

	i = 0;
	while (af->conf[pos] && af->conf[pos] != '-')
	{
		pos++;
	}
	pos++;
	while (af->conf[pos] && af->conf[pos] != '\n')
	{
		pos++;
	}
	return (++pos);
}