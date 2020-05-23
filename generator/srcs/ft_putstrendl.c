/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:47:53 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/17 17:14:40 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_generator.h"

void	ft_putstrendl(const char *str)
{
	if (!str)
		return ;
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}
