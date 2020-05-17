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
**	error code : 1 | 2 | 3 | 4
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define	NOTHING			-1
#define FALSE			0
#define TRUE			1
#define BUFFER_SIZE		3

#define	SIMPLE_ROOM		0
#define	START_ROOM		1
#define	END_ROOM		2

typedef struct	s_connected_room
{
	struct s_room	*room;
	struct s_room	*next;
}				t_connected_room;

typedef struct	s_room
{
	char						*name;
	int							type;
	int							dist;
	int							pipes;
	struct	s_connected_room	*connected_rooms;
	struct	s_room				*next;
}				t_room;

typedef struct	s_af
{
	char			*conf;
	char			buff[BUFFER_SIZE + 1];
	struct s_room	*rooms;
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

/*
**	---------------------- reader.c
*/

char	*ft_clear_buff(t_af *af);
void	ft_add_buff(t_af *af, int buff_len);
char	*ft_read_config(t_af *af);

/*
**	---------------------- init.c
*/

void	ft_init_af(t_af *af);

/*
**	---------------------- parser.c
*/

int		ft_skip_comment(t_af *af, int pos);
int		ft_parse_ant(t_af *af, int pos);
int		ft_parse_rooms(t_af *af, int pos);
int		ft_parse_pipes(t_af *af, int pos);
void	ft_parser(t_af *af);


#endif
