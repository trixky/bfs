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

void	ft_exit(t_af *af, int error)
{
	int	exit_code;

	// free all af components
	ft_free_rooms_and_their_paths(af);
	af->conf = ft_free(af->conf);
	exit_code = EXIT_SUCCESS;
	if (error > FALSE)
	{
		ft_putstr_fd("ERROR\n", STDERR_FILENO);
		exit_code = EXIT_FAILURE;
	}
	exit(exit_code);
}
