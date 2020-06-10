#include "ft_generator.h"

/*
** av[1] = Number of Ants
** av[2] = Number of Rooms
** av[3] = Number of nb of max tubes / room
** av[4] = Number of tubes for the entry
** av[5] = Number of tubes for the exit
*/

static void		ft_print_arg(char *av[])
{
	ft_putstrnb("Number of Ant", ft_atoi(av[1]));
	ft_putstrnb("Number of Room", ft_atoi(av[2]));
	ft_putstrnb("Number of max tube / room", ft_atoi(av[3]));
	ft_putstrnb("Number of tubes for entry", ft_atoi(av[4]));
	ft_putstrnb("Number of tubes for exit", ft_atoi(av[5]));
}

static t_bool	ft_error_arg(void)
{
	ft_putstrendl("Wrong number of argument.\n\
./Generator Nb_ants Nb_rooms Nb_max_tubes/room Nb_entry_tubes Nb_exit_tubes ");
	return (false);
}

static t_bool	ft_error_arg_value(char **av)
{
	ft_putstrendl("Error in input value");
	ft_print_arg(av);
	return (false);
}

static t_params	ft_init_param(char *av[])
{
	t_params params;

	params.nb_ants = -1;
	if (!ft_is_int(av[1]) ||
		!ft_is_int(av[2]) ||
		!ft_is_int(av[3]) ||
		!ft_is_int(av[4]) ||
		!ft_is_int(av[5]))
		return (params);
	params.nb_ants = ft_atoi(av[1]);
	params.nb_rooms = ft_atoi(av[2]);
	params.max_tubes = ft_atoi(av[3]);
	params.begin_tubes = ft_atoi(av[4]);
	params.exit_tubes = ft_atoi(av[5]);
	if (params.nb_rooms <= params.max_tubes ||
	params.nb_rooms <= params.exit_tubes ||
	params.nb_rooms <= params.begin_tubes ||
	params.nb_ants < 1 ||
	params.nb_rooms < 2 ||
	params.max_tubes < 1 ||
	params.exit_tubes < 1 ||
	params.begin_tubes < 1)
		params.nb_ants = 0;
	return (params);
}

int				main(int ac, char *av[])
{
	t_params params;

	(void)av;
	if (ac != 6)
		return (ft_error_arg());
	srand(time(NULL));
	params = ft_init_param(av);
	if (!params.nb_ants)
		return (ft_error_arg_value(av));
	else if (params.nb_ants == -1)
		return (ft_error_arg_value(av));
	ft_principal(params);
	return (0);
}
