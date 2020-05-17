#include "lem_in.h"

int main(void)
{
	t_af	af;

	ft_init_af(&af);
	ft_read_config(&af);
	printf("%s", af.conf);
}