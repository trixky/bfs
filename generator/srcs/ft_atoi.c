/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:45:03 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/17 17:14:46 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_generator.h"

int		ft_atoi(const char *str)
{
	int			i;
	long long	moins;
	long long	nbr;

	i = 0;
	nbr = 0;
	moins = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		moins = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (moins == 1 && nbr > 2147483647)
			return (-1);
		else if (nbr < -2147483648)
			return (0);
		nbr = nbr * 10 + (str[i++] - 48);
	}
	return (nbr * moins);
}
