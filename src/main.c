/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:50:39 by mabois            #+#    #+#             */
/*   Updated: 2020/05/23 11:50:41 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_pascal(t_af *af)
{
	t_pipe	*temp_path;


	ft_bfs(af); // par de start jusque end (scan tout)
	ft_show_rooms(af); // affiche toutes les rooms
	temp_path = ft_find_path(af); // trouve le meilleur chemin selon le "scan de bfs"
	printf("path is valid ? %d\n", ft_path_is_valid(temp_path)); // retourne 1 si valide
	printf("len is ? %d\n\n", ft_path_len(temp_path)); // len du chemin
	ft_free_path(temp_path); // fonction pour free des path

	ft_bfs(af);						// identique ...
	temp_path = ft_find_path(af);
	printf("path is valid ? %d\n", ft_path_is_valid(temp_path));
	printf("len is ? %d\n\n", ft_path_len(temp_path));
	ft_free_path(temp_path);

	ft_bfs(af);						// identique ...
	temp_path = ft_find_path(af);
	printf("path is valid ? %d\n", ft_path_is_valid(temp_path));
	printf("len is ? %d\n\n", ft_path_len(temp_path));
	ft_free_path(temp_path);

	ft_bfs(af);						// identique ...
	temp_path = ft_find_path(af);
	printf("path is valid ? %d\n", ft_path_is_valid(temp_path));
	printf("len is ? %d\n\n", ft_path_len(temp_path));
	ft_free_path(temp_path);
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
