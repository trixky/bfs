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

int	main(void)
{
	t_af	af;

	ft_init_af(&af);
	ft_read_config(&af);
	ft_putstr_fd(af.conf, STDOUT_FILENO);
	ft_putstr_fd("\n\n", STDOUT_FILENO);
	ft_parser(&af);
	ft_ants(&af);
	ft_exit(&af, FALSE);
}
