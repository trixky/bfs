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

int	ft_strcmp(char *a, int a_len, char *b, int b_len)
{
	int i;

	if (a_len != b_len)
		return (FALSE);
	i = -1;
	while (++i < a_len)
		if (a[i] != b[i])
			return (FALSE);
	return (TRUE);
}

void	ft_putnbr(int nbr)
{
	char c;

	if (nbr > 2147483647 || nbr < -2147483648)
		return ;
	if (nbr == -2147483648)
	{
		ft_putstr_fd("-2147483648", STDOUT_FILENO);
		return ;
	}
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putstr_fd("-", STDOUT_FILENO);
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		write(STDOUT_FILENO, &c, 1);
		return ;
	}
	ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(STDOUT_FILENO, &c, 1);
	return ;
}