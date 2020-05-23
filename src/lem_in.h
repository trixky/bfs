/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 11:50:32 by mabois            #+#    #+#             */
/*   Updated: 2020/05/23 14:32:35 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
**	read
**	write
**	malloc
**	free
**	perror
**	strerror
**	exit
*/

/*
**	error code : 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define NOTHING		-1
# define FALSE			0
# define TRUE			1
# define BUFFER_SIZE	400

# define SIMPLE_ROOM	0
# define START_ROOM		1
# define END_ROOM		2

typedef struct	s_pipe
{
	struct s_room	*room;
	struct s_pipe	*next;
}				t_pipe;

typedef struct	s_path
{
	t_pipe			*path;
	int				length;
	int				nb_ants;
	struct s_path	*last;
	struct s_path	*next;
}				t_path;

typedef struct	s_ant
{
	int				ant_id;
	struct s_room	*room;
	int				end;
	struct s_ant	*next;
	struct s_ant	*next_moved;
	t_pipe			*next_path;
}				t_ant;

typedef struct	s_room
{
	int							reserved;
	int							traveled;
	int							name_pos_start;
	int							name_pos_end;
	int							ant;
	t_ant						*ptrant;
	int							type;
	int							dist;
	struct s_pipe				*pipes;
	struct s_room				*next;
}				t_room;

typedef struct	s_af
{
	char			*conf;
	char			buff[BUFFER_SIZE + 1];
	struct s_room	*rooms;
	struct s_room	*room_start;
	struct s_room	*room_end;
	int				start_pipe;
	int				end_pipe;
	int				ant;
	int				next_is_start;
	int				next_is_end;
	int				path_start_end_finded;
}				t_af;

/*
**	---------------------- tools_1.c
*/

void			*ft_free(void *ptr);
int				ft_strlen(char *str);
int				ft_putstr_fd(char *str, int fd);
int				ft_is_number(char c);
void			ft_exit(t_af *af, int error);

/*
**	---------------------- tools_2.c
*/

int				ft_str_to_nbr(t_af *af, char *str, int start, int end);
int				ft_strcmp(char *a, int a_len, char *b, int b_len);
void			ft_putnbr(int nbr);
void			ft_free_rooms_and_their_paths(t_af *af);

/*
**	---------------------- tools_parser_1.c
*/

int				ft_skip_comment(t_af *af, int pos);
int				ft_parse_start_command_line(t_af *af, int pos);
int				ft_parse_end_command_line(t_af *af, int pos);
int				ft_parse_unknown_command_line(t_af *af, int pos);
int				ft_evaluate_commande(t_af *af, int pos);

/*
**	---------------------- tools_parser_2.c
*/
int				ft_is_room_char(char c);
int				ft_is_room_line_cut(t_af *af, int *pos, int *start);
int				ft_is_room_line(t_af *af, int pos);
t_room			*ft_parse_room_line_cut(t_af *af);
int				ft_parse_room_line(t_af *af, int pos);

/*
**	---------------------- tools_parser_3.c
*/

int				ft_is_pipe_line(t_af *af, int pos);
int				ft_parse_pipe_line(t_af *af, int pos);

/*
**	---------------------- reader.c
*/

char			*ft_clear_buff(t_af *af);
void			ft_add_buff(t_af *af);
char			*ft_read_config(t_af *af);

/*
**	---------------------- init.c
*/

void			ft_init_af(t_af *af);

/*
**	---------------------- parser.c
*/

int				ft_parse_ant(t_af *af, int pos);
int				ft_parse_rooms(t_af *af, int pos);
int				ft_parse_pipes(t_af *af, int pos);
void			ft_parser(t_af *af);

/*
**	---------------------- rooms_1.c
*/

t_room			*ft_create_and_init_room(void);
t_room			*ft_add_room(t_af *af, t_room *room);
void			ft_check_doubled_rooms(t_af *af, t_room *room);
t_room			*ft_find_room(t_af *af, int start, int end);

/*
**	---------------------- rooms_2.c
*/

int				ft_room_cmp(t_room *room_a, t_room *room_b);
void			ft_clear_rooms(t_af *af);
int				ft_find_best_dist(t_room *room);
void			ft_give_best_dist(t_room *room);
t_pipe			*ft_add_rooms_to_go(t_room *room, t_pipe *pipes);

/*
**	---------------------- rooms_3.c
*/

void			ft_show_room(t_af *af, t_room *temp_room);
void			ft_show_rooms_cut(t_af *af, t_room *temp_room);
void			ft_show_rooms(t_af *af);

/*
**	---------------------- pipes_1.c
*/

int				ft_pipe_already_exist(t_room *room_a, t_room *room_b);
void			ft_add_pipe_cut(t_af *af, t_room *room_a,
				t_room *room_b, t_pipe *ta_tb_pa_pb[4]);
void			ft_add_pipe(t_af *af, t_room *room_a, t_room *room_b);
t_pipe			*ft_push_back_pipe(t_pipe *pipes, t_pipe *pipe);
t_pipe			*ft_pop_front_pipe(t_pipe *pipes);

/*
**	---------------------- bfs.c
*/

void			ft_show_rooms_to_go(t_af *af, t_pipe *rooms_to_go);
void			ft_bfs(t_af *af);

/*
**	---------------------- path_1.c
*/

t_pipe			*ft_find_best_room(t_af *af, t_room *room);
t_room			*ft_find_last_room_path(t_pipe *path);
int				ft_path_len(t_pipe *path);
int				ft_path_is_valid(t_pipe *path);
t_pipe			*ft_find_path(t_af *af);

/*
**	---------------------- path_2.c
*/

t_pipe			*ft_free_path(t_pipe *path);

/*
**	---------------------- print_ant.c
*/

void			*ft_ants(t_af *af);
char			*ft_display_ants_move(t_af *af, t_path *paths);
void			ft_print_move(t_af af, t_ant *ants);
void			ft_moving_ants(t_af af, t_ant *ants, t_path *paths);
int				ft_check_ants(t_af af, t_ant *ants);
void			ft_direct_ants(t_ant *ants, t_path *paths);

#endif
