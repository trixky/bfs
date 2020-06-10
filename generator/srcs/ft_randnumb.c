#include "ft_generator.h"

int	ft_randnumb(int max)
{
	int nb;

	nb = rand();
	while (nb > max)
		nb %= max;
	return (nb);
}
