#include "lem_in.h"



int 	ft_is_room_char(char c)
{
	return (c > ' ' && c < 127);
}

int 	ft_is_room_line(t_af *af, int pos)
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
	return (TRUE);
}

int		ft_parse_room_line(t_af *af, int pos)
{
	t_room *room;

	room = ft_create_and_init_room();

	if (af->next_is_start == TRUE)
	{
		af->next_is_start = FALSE;
		room->type = START_ROOM;
	}
	else if (af->next_is_end == TRUE)
	{
		af->next_is_end = FALSE;
		room->type = END_ROOM;
	}
	room->name_pos_start = pos;
	while (af->conf[pos] && af->conf[pos] != ' ')
	{
		pos++;
	}
	room->name_pos_end = pos;
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
	ft_add_room(af, room);
	return (++pos);
}