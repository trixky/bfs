/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 11:59:35 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/17 12:01:59 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GENERATOR_H
# define FT_GENERATOR_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_params
{
	int	nb_ants;
	int	nb_rooms;
	int	max_tubes;
	int	begin_tubes;
	int	exit_tubes;

}				t_params;

typedef struct	s_link
{
	int				room_id;
	int				nb;
	struct s_link	*next;
}				t_link;

/*
**  ft_principal.c
*/

void			ft_principal(t_params params);
void			ft_print_links(t_params params);

/*
**  ft_list.c
*/

void			ft_free_list(t_link **list, int size);
t_link			**ft_init_list(int size);
t_link			*ft_create_link(int room_id);

#endif
