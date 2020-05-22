#include "lem_in.h"

void	ft_show_room(t_af *af, t_room *temp_room)
{
	t_pipe *temp_pipe;

	if (temp_room != NULL)
	{
		ft_putstr_fd("           ", STDOUT_FILENO);
		write(STDOUT_FILENO, af->conf + temp_room->name_pos_start,
		temp_room->name_pos_end - temp_room->name_pos_start);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}
