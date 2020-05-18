#include "lem_in.h"

int main(void)
{
	t_af	af;

	ft_init_af(&af);
	ft_read_config(&af);
	ft_putstr_fd(af.conf, STDOUT_FILENO);
	ft_putstr_fd("\n\n", STDOUT_FILENO);
	ft_parser(&af);
	ft_show_room(&af);
}