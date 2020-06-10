#include "bfs.h"

t_room	*ft_create_and_init_room(void)
{
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room) * 1);
	room->reserved = FALSE;
	room->traveled = FALSE;
	room->ant = 0;
	room->type = SIMPLE_ROOM;
	room->dist = NOTHING;
	room->pipes = NULL;
	room->next = NULL;
	return (room);
}

t_room	*ft_add_room(t_af *af, t_room *room)
{
	t_room *temp;

	if (af->rooms == NULL)
		af->rooms = room;
	else
	{
		ft_check_doubled_rooms(af, room);
		temp = af->rooms;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = room;
	}
	return (room);
}

void	ft_check_doubled_rooms(t_af *af, t_room *room)
{
	t_room *temp;

	if (af->rooms != NULL)
	{
		temp = af->rooms;
		while (temp != NULL)
		{
			if (ft_strcmp(af->conf + temp->name_pos_start, temp->name_pos_end -
					temp->name_pos_start, af->conf + room->name_pos_start,
					room->name_pos_end - room->name_pos_start))
			{
				ft_free(room);
				ft_exit(af, 10);
			}
			temp = temp->next;
		}
	}
}

t_room	*ft_find_room(t_af *af, int start, int end)
{
	t_room *temp;

	if (af->rooms != NULL)
	{
		temp = af->rooms;
		while (temp != NULL)
		{
			if (ft_strcmp(af->conf + temp->name_pos_start,
					temp->name_pos_end - temp->name_pos_start,
					af->conf + start, end - start))
				return (temp);
			temp = temp->next;
		}
	}
	return (NULL);
}
