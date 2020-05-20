#include "lem_in.h"

void	ft_show_room(t_af *af, t_room *temp_room)
{
	t_pipe *temp_pipe;

	// ft_putstr_fd("\n========= SHOW ROOM =========\n\n", STDOUT_FILENO);
	// ft_putstr_fd("   --- [", STDOUT_FILENO);
	// ft_putnbr(temp_room->dist);
	// ft_putstr_fd("] ", STDOUT_FILENO);
	ft_putstr_fd("           ", STDOUT_FILENO);
	write(STDOUT_FILENO, af->conf + temp_room->name_pos_start, temp_room->name_pos_end - temp_room->name_pos_start);
	ft_putstr_fd("\n", STDOUT_FILENO);
	// if (temp_room->type == START_ROOM)
	// 	ft_putstr_fd(" [ START ]", STDOUT_FILENO);
	// else if (temp_room->type == END_ROOM)
	// 	ft_putstr_fd(" [ END ]", STDOUT_FILENO);
	// ft_putstr_fd("\n", STDOUT_FILENO);
	// temp_pipe = temp_room->pipes;
	// while (temp_pipe != NULL)
	// {
	// 	ft_putstr_fd("\t\t. <-> ", STDOUT_FILENO);
	// 	write(STDOUT_FILENO, af->conf + temp_pipe->room->name_pos_start, temp_pipe->room->name_pos_end - temp_pipe->room->name_pos_start);
	// 	ft_putstr_fd("\n", STDOUT_FILENO);
	// 	temp_pipe = temp_pipe->next;
	// }
	// ft_putstr_fd("\n==============================\n\n", STDOUT_FILENO);
}