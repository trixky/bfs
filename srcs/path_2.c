#include "bfs.h"

t_pipe	*ft_free_path(t_pipe *path)
{
	t_pipe *temp;
	t_pipe *temp_free;

	temp = path;
	while (temp != NULL)
	{
		temp_free = temp;
		temp = temp->next;
		temp_free = ft_free(temp_free);
	}
	return (NULL);
}
