#ifndef ANTSMOVE_H
# define ANTSMOVE_H

# include "lem_in.h"

typedef struct  s_ant
{
    int ant_id;
    t_room *room;
    int end;
    struct s_ant *next;
}               t_ant;

#endif