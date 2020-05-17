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

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE			0
#define FALSE			1
#define BUFFER_SIZE		3

typedef struct	s_connected_room
{
	struct s_room	*room;
	struct s_room	*next;
}				t_connected_room;

typedef struct	s_room
{
	char						*name;
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
}				t_af;

/*
**	---------------------- tools-1.c
*/

void	*ft_free(void *ptr);
int		ft_strlen(char *str);
int		ft_putstr_fd(char *str, int fd);
int		ft_is_number(char c);

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

#endif
