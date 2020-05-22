#include "lem_in.h"

void	ft_show_rooms_to_go(t_af *af, t_pipe *rooms_to_go)
{
	t_pipe	*temp;

	temp = rooms_to_go;
	while (temp != NULL)
	{
		ft_show_room(af, temp->room);
		temp = temp->next;
	}
}

void	ft_bfs(t_af *af)
{
	t_pipe *rooms_to_go;
	t_room *temp_room;

	rooms_to_go = (t_pipe *)malloc(sizeof(t_pipe) * 1);
	rooms_to_go->room = af->room_start;
	rooms_to_go->next = NULL;
	ft_clear_rooms(af);
	while (rooms_to_go != NULL)
	{
		// ft_show_rooms_to_go(af, rooms_to_go);
		temp_room = rooms_to_go->room;
		rooms_to_go = ft_pop_front_pipe(rooms_to_go);
		rooms_to_go = ft_add_rooms_to_go(af, temp_room, rooms_to_go);
	}
}
