#include "lem_in.h"

void	ft_init_af(t_af *af)
{
	ft_clear_buff(af);
	af->conf = NULL;
	af->rooms = NULL;
	af->ant = NOTHING;
	af->next_is_start = NOTHING;
	af->next_is_end = NOTHING;
	af->room_start = NULL;
	af->room_end = NULL;
	af->path_start_end_finded = FALSE;
}
