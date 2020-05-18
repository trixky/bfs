#include "lem_in.h"

t_room	*ft_add_room(t_af *af, t_room *room)
{
	t_room *temp;

	if (af->rooms == NULL)
		af->rooms = room;
	else
	{
		temp = af->rooms;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = room;
	}
	return (room);
}

void	ft_show_room(t_af *af)
{
	t_room *temp;

	temp = af->rooms;
	ft_putstr_fd("\n--------- SHOW ROOMS ---------\n\n", STDOUT_FILENO);
	while (temp != NULL)
	{
		write(STDOUT_FILENO, af->conf + temp->name_pos_start, temp->name_pos_end - temp->name_pos_start);
		ft_putstr_fd("\n", STDOUT_FILENO);
		temp = temp->next;
	}
	ft_putstr_fd("\n------------------------------\n\n", STDOUT_FILENO);
}