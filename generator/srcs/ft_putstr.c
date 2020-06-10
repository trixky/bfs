#include "ft_generator.h"

void	ft_putstr(const char *s)
{
	if (s == NULL)
		return ;
	while (*s)
		write(1, s++, 1);
}
