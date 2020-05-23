/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:51:40 by mabois            #+#    #+#             */
/*   Updated: 2020/05/23 11:51:42 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_clear_buff(t_af *af)
{
	int i;

	i = -1;
	while (++i < BUFFER_SIZE + 1)
		af->buff[i] = '\0';
	return (af->buff);
}

void	ft_add_buff(t_af *af)
{
	int 	i;
	int		j;
	int 	conf_len;
	int		buff_len;
	char	*new_conf;

	i = -1;
	j = -1;
	conf_len = ft_strlen(af->conf);
	buff_len = ft_strlen(af->buff);
	new_conf = (char *)malloc(sizeof(char) * (conf_len + buff_len + 2));
	while (++i < conf_len)
		new_conf[i] = af->conf[i];
	while (++j < buff_len)
		new_conf[i + j] = af->buff[j];
	new_conf[i + j] = '\0';
	new_conf[i + j + 1] = '\0';
	ft_free(af->conf);
	af->conf = new_conf;
}

char	*ft_read_config(t_af *af)
{
	while (read(STDIN_FILENO, af->buff, BUFFER_SIZE) > 0)
	{
		ft_add_buff(af);
		ft_clear_buff(af);
	}
}
