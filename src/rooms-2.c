#include "lem_in.h"

int	ft_room_cmp(t_room *room_a, t_room *room_b)
{
	return (room_a != NULL && room_b != NULL &&
			room_a->name_pos_start == room_b->name_pos_start);
}

void	ft_clear_rooms(t_af *af)
{
	t_room	*temp_room;

	temp_room = af->rooms;
	while (temp_room != NULL)
	{
		temp_room->traveled = FALSE;
		temp_room = temp_room->next;
	}
}