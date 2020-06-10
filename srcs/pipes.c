#include "bfs.h"

int		ft_pipe_already_exist(t_room *room_a, t_room *room_b)
{
	t_pipe *temp_pipe_a;

	temp_pipe_a = room_a->pipes;
	while (temp_pipe_a != NULL)
	{
		if (temp_pipe_a->room->name_pos_start == room_b->name_pos_start)
			return (TRUE);
		temp_pipe_a = temp_pipe_a->next;
	}
	return (FALSE);
}

void	ft_add_pipe_cut(t_af *af, t_room *room_a,
		t_room *room_b, t_pipe *ta_tb_pa_pb[4])
{
	if (ft_room_cmp(room_a, room_b))
		ft_exit(af, 11);
	if (ft_pipe_already_exist(room_a, room_b))
		ft_exit(af, 12);
	ta_tb_pa_pb[2] = (t_pipe *)malloc(sizeof(t_pipe) * 1);
	ta_tb_pa_pb[2]->room = room_b;
	ta_tb_pa_pb[2]->next = NULL;
	ta_tb_pa_pb[0] = room_a->pipes;
}

void	ft_add_pipe(t_af *af, t_room *room_a, t_room *room_b)
{
	t_pipe	*ta_tb_pa_pb[4];

	ft_add_pipe_cut(af, room_a, room_b, ta_tb_pa_pb);
	if (ta_tb_pa_pb[0] == NULL)
		room_a->pipes = ta_tb_pa_pb[2];
	else
	{
		while (ta_tb_pa_pb[0]->next != NULL)
			ta_tb_pa_pb[0] = ta_tb_pa_pb[0]->next;
		ta_tb_pa_pb[0]->next = ta_tb_pa_pb[2];
	}
	ta_tb_pa_pb[3] = (t_pipe *)malloc(sizeof(t_pipe) * 1);
	ta_tb_pa_pb[3]->room = room_a;
	ta_tb_pa_pb[3]->next = NULL;
	ta_tb_pa_pb[1] = room_b->pipes;
	if (ta_tb_pa_pb[1] == NULL)
		room_b->pipes = ta_tb_pa_pb[3];
	else
	{
		while (ta_tb_pa_pb[1]->next != NULL)
			ta_tb_pa_pb[1] = ta_tb_pa_pb[1]->next;
		ta_tb_pa_pb[1]->next = ta_tb_pa_pb[3];
	}
}

t_pipe	*ft_push_back_pipe(t_pipe *pipes, t_pipe *pipe)
{
	t_pipe *temp;

	if (pipes == NULL)
		return (pipe);
	if (pipe == NULL)
		return (pipes);
	temp = pipes;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = pipe;
	return (pipes);
}

t_pipe	*ft_pop_front_pipe(t_pipe *pipes)
{
	t_pipe *temp;

	if (pipes != NULL)
	{
		if (pipes->next == NULL)
			return (ft_free(pipes));
		temp = pipes;
		pipes = pipes->next;
		temp = ft_free(temp);
	}
	return (pipes);
}
