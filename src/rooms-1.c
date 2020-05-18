#include "lem_in.h"

t_room *ft_create_and_init_room(void)
{
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room) * 1);
	room->reserved = FALSE;
	room->traveled = FALSE;
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

void	ft_show_room(t_af *af)
{
	t_room *temp_room;
	t_pipe *temp_pipe;

	temp_room = af->rooms;
	ft_putstr_fd("\n========= SHOW ROOMS =========\n\n", STDOUT_FILENO);
	while (temp_room != NULL)
	{
		ft_putstr_fd("   --- ", STDOUT_FILENO);
		write(STDOUT_FILENO, af->conf + temp_room->name_pos_start, temp_room->name_pos_end - temp_room->name_pos_start);
		if (temp_room->type == START_ROOM)
			ft_putstr_fd(" [ START ]", STDOUT_FILENO);
		else if (temp_room->type == END_ROOM)
			ft_putstr_fd(" [ END ]", STDOUT_FILENO);

		ft_putstr_fd("\n", STDOUT_FILENO);
		temp_pipe = temp_room->pipes;
		while (temp_pipe != NULL)
		{
			ft_putstr_fd("\t\t. <-> ", STDOUT_FILENO);
			write(STDOUT_FILENO, af->conf + temp_pipe->room->name_pos_start, temp_pipe->room->name_pos_end - temp_pipe->room->name_pos_start);
			ft_putstr_fd("\n", STDOUT_FILENO);
			temp_pipe = temp_pipe->next;
		}
		temp_room = temp_room->next;
	}
	ft_putstr_fd("\n==============================\n\n", STDOUT_FILENO);
}

void	ft_check_doubled_rooms(t_af *af, t_room *room)
{
	t_room *temp;

	if (af->rooms != NULL)
	{
		temp = af->rooms;
		while (temp != NULL)
		{
			if (ft_strcmp(af->conf + temp->name_pos_start, temp->name_pos_end - temp->name_pos_start,
					af->conf + room->name_pos_start, room->name_pos_end - room->name_pos_start))
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
			if (ft_strcmp(af->conf + temp->name_pos_start, temp->name_pos_end - temp->name_pos_start,
					af->conf + start, end - start))
				return (temp);
			temp = temp->next;
		}
	}
	return (NULL);
}
