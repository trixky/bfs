#ifndef LEM_IN_H
#define LEM_IN_H


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

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define	NOTHING			-1
#define FALSE			0
#define TRUE			1
#define BUFFER_SIZE		400

#define	SIMPLE_ROOM		0
#define	START_ROOM		1
#define	END_ROOM		2

typedef struct	s_pipe
{
	struct s_room	*room;
	struct s_pipe	*next;
}				t_pipe;

typedef struct	s_room
{
	int							reserved;
	int							traveled;
	int							name_pos_start;
	int							name_pos_end;
	int							type;
	int							dist;
	struct	s_pipe				*pipes;
	struct	s_room				*next;
}				t_room;

typedef struct	s_af
{
	char			*conf;
	char			buff[BUFFER_SIZE + 1];
	struct s_room	*rooms;
	struct s_room	*room_start;
	struct s_room	*room_end;
	int				ant;
	int				next_is_start;
	int				next_is_end;
}				t_af;

/*
**	---------------------- tools-1.c
*/

void	*ft_free(void *ptr);
int		ft_strlen(char *str);
int		ft_putstr_fd(char *str, int fd);
int		ft_is_number(char c);
void	ft_exit(t_af *af, int error);

/*
**	---------------------- tools-2.c
*/

int	ft_str_to_nbr(t_af *af, char *str, int start, int end);
int	ft_strcmp(char *a, int a_len, char *b, int b_len);
void	ft_putnbr(int nbr);

/*
**	---------------------- tools-parser-1.c
*/

int		ft_skip_comment(t_af *af, int pos);
int		ft_parse_start_command_line(t_af *af, int pos);
int		ft_parse_end_command_line(t_af *af, int pos);
int		ft_parse_unknown_command_line(t_af *af, int pos);
int		ft_evaluate_commande(t_af *af, int pos);

/*
**	---------------------- tools-parser-2.c
*/
int		ft_is_room_char(char c);
int		ft_is_room_line(t_af *af, int pos);
int		ft_parse_room_line(t_af *af, int pos);

/*
**	---------------------- tools-parser-3.c
*/

int 	ft_is_pipe_line(t_af *af, int pos);
int		ft_parse_pipe_line(t_af *af, int pos);

/*
**	---------------------- reader.c
*/

char	*ft_clear_buff(t_af *af);
void	ft_add_buff(t_af *af);
char	*ft_read_config(t_af *af);

/*
**	---------------------- init.c
*/

void	ft_init_af(t_af *af);

/*
**	---------------------- parser.c
*/

int		ft_parse_ant(t_af *af, int pos);
int		ft_parse_rooms(t_af *af, int pos);
int		ft_parse_pipes(t_af *af, int pos);
void	ft_parser(t_af *af);

/*
**	---------------------- rooms-1.c
*/

t_room	*ft_create_and_init_room(void);
t_room	*ft_add_room(t_af *af, t_room *room);
void	ft_show_rooms(t_af *af);
void	ft_check_doubled_rooms(t_af *af, t_room *room);
t_room	*ft_find_room(t_af *af, int start, int end);

/*
**	---------------------- rooms-2.c
*/

int		ft_room_cmp(t_room *room_a, t_room *room_b);
void	ft_clear_rooms(t_af *af);
int		ft_find_best_dist(t_room *room);
void	ft_give_best_dist(t_room *room);
t_pipe	*ft_add_rooms_to_go(t_af *af, t_room *room, t_pipe *pipes);

/*
**	---------------------- rooms-3.c
*/

void	ft_show_room(t_af *af, t_room *temp_room);

/*
**	---------------------- pipes-1.c
*/

int		ft_pipe_already_exist(t_af *af, t_room *room_a, t_room *room_b);
void	ft_add_pipe(t_af *af, t_room *room_a, t_room *room_b);
t_pipe	*ft_push_back_pipe(t_pipe *pipes, t_pipe *pipe);
t_pipe	*ft_pop_front_pipe(t_pipe *pipes);

/*
**	---------------------- bfs.c
*/

void	ft_show_rooms_to_go(t_af *af, t_pipe *rooms_to_go);
void	ft_bfs(t_af *af);

#endif
