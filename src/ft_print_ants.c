#include "lemin.h"

int		ft_busy(int *busy, t_way *way, char *room)
{
	int i;

	i = 0;
	//printf("rooom = %s\n", room);
	while (i != way->rmnumb)
	{
		if (!strcmp(room, way->link[i]))
		{
			if (busy[i] == 1)
				return (0);
			else
			{
				busy[i] = 1;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	ft_print(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
}

void	ft_clear_busy(int *busy, int size)
{
	int i;

	i = 0;
	while (i != size)
	{
		busy[i] = 0;
		i++;
	}
}

void	ft_move_ant(t_ant *ants, t_way *way, int *busy, int *end)
{
	int i;

	i = 0;
	while (i != way->ant)
	{
		if (ants[i].end != 1)
		{
			if (!ft_strcmp(ants[i].map[ants[i].cur_room+1], way->end_room))
			{
				ants[i].cur_room++;
				ft_print(ants[i].name, ants[i].map[ants[i].cur_room]);
				ants[i].end = 1;
				(*end)++;
			}
			else if (ft_busy(busy, way, ants[i].map[ants[i].cur_room+1]))
			{
				ants[i].cur_room++;
				ft_print(ants[i].name, ants[i].map[ants[i].cur_room]);
			}
			ft_putchar(' ');
		}
		i++;
	}
}

void	ft_room_loop(t_ant *ants, t_way *way)
{
	int	end;
	int	busy[way->rmnumb];

	end = 0;
	while (end != way->ant)
	{
		ft_move_ant(ants, way, busy, &end);
		ft_clear_busy(busy, way->rmnumb);
		ft_putchar('\n');
	}
}

void	ft_fill_ants(t_way *way)
{
	t_ant	*ants;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(ants = (t_ant*)malloc(sizeof(t_ant) * way->ant)))
		return ;
	while (i < way->ant)
	{
		if (j == way->nbr_map)
			j = 0;
		ants[i].map = way->maps[j].map;
		ants[i].name = i + 1;
		ants[i].cur_room = 0;
		ants[i].end = 0;
		j++;
		i++;
	}
	// i = 0;
	// while (i < way->ant)
	// {
	// 	j = 0;
	// 	printf("ants data: name: %d curr: %d\n", ants[i].name, ants[i].cur_room);
	// 	while(ants[i].map[j] != NULL)
	// 	{
	// 		printf("%s ", ants[i].map[j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	ft_room_loop(ants, way);
}