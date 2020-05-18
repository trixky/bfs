#include "lem_in.h"

int	ft_room_cmp(t_room *room_a, t_room *room_b)
{
	return (room_a != NULL && room_b != NULL &&
			room_a->name_pos_start == room_b->name_pos_start);
}