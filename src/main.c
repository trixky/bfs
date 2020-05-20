#include "lem_in.h"

void	ft_pascal(t_af *af)
{
	// ft_show_rooms(&af);
	t_pipe	*temp_path;

	ft_bfs(af); // par de start jusque end (recherche)
	temp_path = ft_find_path(af);
	printf("path is valid ? %d\n", ft_path_is_valid(temp_path));
	printf("len is ? %d\n\n", ft_path_len(temp_path));

	ft_bfs(af);
	temp_path = ft_find_path(af);
	printf("path is valid ? %d\n", ft_path_is_valid(temp_path));
	printf("len is ? %d\n\n", ft_path_len(temp_path));

	ft_bfs(af);
	temp_path = ft_find_path(af);
	printf("path is valid ? %d\n", ft_path_is_valid(temp_path));
	printf("len is ? %d\n\n", ft_path_len(temp_path));
}

int main(void)
{
	t_af	af;

	ft_init_af(&af);
	ft_read_config(&af);
	ft_putstr_fd(af.conf, STDOUT_FILENO);
	ft_putstr_fd("\n\n", STDOUT_FILENO);
	ft_parser(&af);
	
	ft_pascal(&af);
	ft_exit(&af, FALSE);
}