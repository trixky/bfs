#include "ft_generator.h"

int		ft_is_int(char *str)
{
	long ret;

	if (!ft_base_10(str))
		return (false);
	ret = ft_atoi(str);
	if (ret < -2147483648 || ret > 2147483647)
		return (false);
	return (true);
}
