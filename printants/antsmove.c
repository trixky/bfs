#include "lem_in.h"
#include "antsmove.h"

t_room  *ft_find_type_room(t_room *begin, int type)
{
    while (begin)
    {
        if (begin->type == type)
            break ;
        begin = begin->next;
    }   
    return (begin);
}

void	ft_putnbr(int n)
{
	char a;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	a = (n % 10) + '0';
	write(1, &a, 1);
}

void    *ft_free_ants(t_ant *begin, int size)
{
    t_ant *tmp;
    int i;

    i = 0;
    tmp = begin;
    while (i++ < size && tmp)
    {
        tmp = begin->next;
        free(begin);
        begin = tmp;
    }
    return (NULL);
}

t_ant   *ft_create_ant(int ant_id)
{
    t_ant *ret;

    if (!(ret = malloc(sizeof(t_ant))))
        return (NULL);
    ret->ant_id = ant_id;
    ret->room = NULL;
    ret->end = FALSE;
    return (ret);
}

t_ant   *ft_init_ants(int nb_ants, t_room *start)
{
    int i;
    t_ant *begin;
    t_ant *tmp;
    t_ant *last;

    begin = NULL;
    i = 0;
    while (++i <= nb_ants)
    {
        if (!(tmp = ft_create_ant(i)))
            return (ft_free_ants(begin, i));
        tmp->room = start;
        begin != NULL? last->next = tmp : 0;
        begin != NULL? last = tmp : 0;
        begin == NULL? last = tmp : 0;
        begin == NULL? begin = tmp : 0;
    }
    return (begin);
}
void    ft_print_move(t_af af, t_ant *ants)
{
    while (ants)
    {
        write(STDOUT_FILENO, "L", 1);
        ft_putnbr(ants->ant_id);
        write(STDOUT_FILENO, "-", 1);
        write(STDOUT_FILENO, af.conf + ants->room->name_pos_start,
        ants->room->name_pos_end - ants->room->name_pos_start);
        if (ants->next)
            write(STDOUT_FILENO, " ", 1);
        ants = ants->next;
    }
    write(STDOUT_FILENO, "\n", 1);
}

char *ft_display_ants_move(t_af af)
{
    t_ant *ants;
    t_room *start;

    start = ft_find_type_room(af.rooms, START_ROOM);
    if (!(ants = ft_init_ants(af.ant, start)))
        return (NULL);
    ft_print_move(af, ants);
    ft_free_ants(ants, af.ant);
    return (NULL);
}