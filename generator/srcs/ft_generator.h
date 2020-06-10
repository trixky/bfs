#ifndef FT_GENERATOR_H
# define FT_GENERATOR_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

typedef enum
{
	false,
	true
}	t_bool;

typedef struct	s_params
{
	int	nb_ants;
	int	nb_rooms;
	int	max_tubes;
	int	begin_tubes;
	int	exit_tubes;
	int	indic;
}				t_params;

typedef struct	s_link
{
	int				room_id;
	int				nb;
	struct s_link	*next;
}				t_link;

/*
**  ft_principal.c
*/

void			ft_principal(t_params params);
void			ft_print_links(t_params params);

/*
**  ft_list.c
*/

void			ft_free_list(t_link **list, int size);
t_link			**ft_init_list(int size);
t_link			*ft_create_link(int room_id);

/*
**  utils
*/

int				ft_atoi(const char *str);
int				ft_base_10(char *str);
int				ft_is_int(char *str);
void			ft_putnbr(int numb);
void			ft_putstr(const char *s);
void			ft_putstrendl(const char *str);
void			ft_putstrnb(const char *str, int nb);
int				ft_randnumb(int max);

#endif
