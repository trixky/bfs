#include "bfs.h"

int		ft_check_ants(t_af af, t_ant *ants)
{
	while (ants)
	{
		if (ants->room != af.room_end)
			return (FALSE);
		ants = ants->next;
	}
	return (TRUE);
}
