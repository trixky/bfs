#include "ft_generator.h"

void	ft_putstrendl(const char *str)
{
	if (!str)
		return ;
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}
