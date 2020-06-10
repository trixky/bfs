#include "ft_generator.h"

void	ft_putstrnb(const char *str, int nb)
{
	ft_putstr(str);
	ft_putstr(" : ");
	ft_putnbr(nb);
	ft_putstr("\n");
}
