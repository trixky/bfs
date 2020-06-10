#include "ft_generator.h"

void	ft_putnbr(int numb)
{
	char c;

	if (numb < 0 && numb != -2147483648)
	{
		numb = -numb;
		c = '-';
		write(1, &c, 1);
	}
	if (numb > 9)
		ft_putnbr(numb / 10);
	c = numb % 10 + 48;
	if (numb == -2147483648)
		write(1, "-2147483648", 11);
	else
		write(1, &c, 1);
}
