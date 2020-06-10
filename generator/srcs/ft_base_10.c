#include "ft_generator.h"

int		ft_base_10(char *str)
{
	int i;

	i = str[0] == '-' ? 0 : -1;
	while (str[++i])
		if (str[i] < 48 || str[i] > 57)
			return (0);
	return (1);
}
