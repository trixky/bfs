#include "lem_in.h"

int		ft_room_cmp(t_room *room_a, t_room *room_b)
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
	af->room_start->traveled = TRUE;
}

int		ft_find_best_dist(t_room *room)
{
	int		best_dist;
	int		temp_dist;
	t_pipe	*temp;

	best_dist = room->dist;
	temp = room->pipes;
	while (temp != NULL)
	{
		temp_dist = temp->room->dist;
		if (temp->room->reserved == FALSE && temp_dist != NOTHING && (temp_dist < best_dist || temp_dist == NOTHING))
			best_dist = temp_dist;
		temp = temp->next;
	}
	return (best_dist);
}

void	ft_give_best_dist(t_room *room)
{
	int		temp_dist;
	t_pipe	*temp;

	temp = room->pipes;
	while (temp != NULL)
	{
		temp_dist = temp->room->dist;
		if (temp->room->reserved == FALSE && temp_dist > room->dist)
			temp->room->dist = room->dist;
		temp = temp->next;
	}
}

t_pipe	*ft_add_rooms_to_go(t_af *af, t_room *room, t_pipe *pipes)
{
	t_pipe	*temp;
	t_pipe	*new_pipe;

	temp = room->pipes;
	while (temp != NULL)
	{
		if (temp->room->traveled == FALSE && temp->room->reserved == FALSE && temp->room->type != END_ROOM && temp->room->type != START_ROOM)
		{
			new_pipe = (t_pipe *)malloc(sizeof(t_pipe) * 1);
			temp->room->dist = room->dist + 1;
			temp->room->traveled = TRUE;
			new_pipe->room = temp->room;
			new_pipe->next = NULL;
			pipes = ft_push_back_pipe(pipes, new_pipe);
		}
		temp = temp->next;
	}
	return (pipes);
}
