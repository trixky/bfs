#include "lem_in.h"

int	ft_str_to_nbr(t_af *af, char *str, int start, int end)
{
	int nbr;

	nbr = 0;
	while (start < end)
	{
		if (!ft_is_number(str[start]))
			ft_exit(af, 3);
		nbr *= 10;
		nbr += str[start] - 48;
		start++;
	}
	return (nbr);
}