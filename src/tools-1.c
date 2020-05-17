#include "lem_in.h"

void	*ft_free(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	return (ptr);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str != NULL)
		while (str[i])
			i++;
	return (i);
}

int		ft_putstr_fd(char *str, int fd)
{
	int len;

	len = ft_strlen(str);
	write(fd, str, len);
	return (len);
}

int		ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}
