#include "ft_generator.h"

static void		ft_shuffle_array(int *array, int size)
{
	int i;
	int tmp;
	int j;

	i = -1;
	if (size < 1)
		return ;
	while (++i < size)
	{
		j = i + ft_randnumb(size - i);
		tmp = array[j];
		array[j] = array[i];
		array[i] = tmp;
	}
}

static void		ft_init_array(int *array, int size)
{
	int i;

	i = -1;
	while (++i < size)
		array[i] = i;
	ft_shuffle_array(array, size);
}

static void		ft_room_coordoned(int room_id, int *array_x, int *array_y)
{
	ft_putnbr(room_id);
	ft_putstr(" ");
	ft_putnbr(array_x[room_id]);
	ft_putstr(" ");
	ft_putnbr(array_y[room_id]);
	ft_putstr("\n");
}

void			ft_principal(t_params params)
{
	int array_x[params.nb_rooms + 100];
	int array_y[params.nb_rooms + 100];
	int i;

	i = 0;
	ft_init_array(array_x, params.nb_rooms + 100);
	ft_init_array(array_y, params.nb_rooms + 100);
	ft_putnbr(params.nb_ants);
	ft_putstr("\n");
	ft_putstrendl("##start");
	while (i < params.nb_rooms)
	{
		if (i + 1 == params.nb_rooms)
			ft_putstrendl("##end");
		ft_room_coordoned(i++, array_x, array_y);
	}
	ft_print_links(params);
}
