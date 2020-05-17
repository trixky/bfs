#include "lem_in.h"

char	*ft_clear_buff(t_af *af)
{
	int i;

	i = -1;
	while (++i < BUFFER_SIZE + 1)
		af->buff[i] = '\0';
	return (af->buff);
}

void	ft_add_buff(t_af *af, int buff_len)
{
	int 	i;
	int		j;
	int 	conf_len;
	char	*new_conf;

	i = -1;
	j = -1;
	conf_len = ft_strlen(af->conf);
	new_conf = (char *)malloc(sizeof(char) * (buff_len + conf_len + 1));

	while (++i < conf_len)
		new_conf[i] = af->conf[i];
	while (++j < buff_len)
		new_conf[i + j] = af->buff[j];
	new_conf[i + j] = '\0';
	ft_free(af->conf);
	af->conf = new_conf;
}

char	*ft_read_config(t_af *af)
{
	int ret;

	while ((ret = read(STDIN_FILENO, af->buff, BUFFER_SIZE)) > 0)
	{
		ft_add_buff(af, ret);
		ft_clear_buff(af);
	}
}