#include "lem_in.h"

int ft_is_room_char(char c)
{
	return (c > ' ' && c < 127);
}

int ft_is_room_line(t_af *af, int pos)
{
	int i;

	i = 0;
	while (af->conf[pos] && af->conf[pos] != ' ')
	{
		if (af->conf[pos] == '\n' || !ft_is_room_char(af->conf[pos]))
			return (FALSE);
		pos++;
	}
	pos++;
	while (af->conf[pos] && af->conf[pos] != ' ')
	{
		if (af->conf[pos] == '\n' || !ft_is_number(af->conf[pos]))
			return (FALSE);
		pos++;
	}
	pos++;
	while (af->conf[pos] && af->conf[pos] != '\n')
	{
		if (!ft_is_number(af->conf[pos]))
			return (FALSE);
		pos++;
	}
	printf("-------- ft_is_room_line\n");
	return (TRUE);
}

int		ft_parse_room_line(t_af *af, int pos)
{
	int i;

	if (af->next_is_start == TRUE)
		af->next_is_start = FALSE;
	if (af->next_is_end == TRUE)
		af->next_is_end = FALSE;
	i = 0;
	while (af->conf[pos] && af->conf[pos] != ' ')
	{
		pos++;
	}
	pos++;
	while (af->conf[pos] && af->conf[pos] != ' ')
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