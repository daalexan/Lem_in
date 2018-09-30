#include "lemin.h"

void	ft_move_graph(t_point *point, t_way *way)
{
	int		i;
	int		j;
	//t_map	*path;

	i = -1;
	while (++i != way->rmnumb)
	{
		j = -1;
		while (++j != way->rmnumb)
		{
			if (point[j].index == 0 && ft_strcmp(point[j].name, way->end_room) &&
				ft_strcmp(point[j].name, point[0].name) && way->matrix[i][j] == 1)
				point[j].index = point[i].index + 1;
		}
	}
	// if (!(path = (t_map*)malloc(sizeof(t_map) * 2)))
	// 	return ;
	// i = 0;
	// j = 0;
	// while (i != 2)
	// {
	// 	path[i].map[0] = point[0].name;
	// 	while (j != way->rmnumb)
	// 	{
	// 		path[i].map[j] 
	// 	}
	// 	path[i].map[j] 
	// }


	// int	indic;

	// i = 0;
	// indic = 1;
	// while (i != way->rmnumb)
	// {
	// 	j = 0;
	// 	while (j != way->rmnumb)
	// 	{
	// 		if (way->matrix[i][j] == 1)
	// 		{
	// 			printf("point: %d name: %s\n", point[j].index, point[j].name);
	// 			if (point[j].index == 0 && ft_strcmp(point[j].name, way->end_room))
	// 			{
	// 				point[j].index = 1;
	// 				indic = point[j].index;
	// 			}
	// 			else if (point[j].index != 0)
	// 			{
	// 				printf("here point 1\n");
	// 				i = j;
	// 				j = 0;
	// 				while (j < way->rmnumb)
	// 				{
	// 					if (way->matrix[i][j] == 1)
	// 					{
	// 						if (point[j].index == indic)
	// 							point[j].index++;
	// 					}
	// 					j++;
	// 				}
	// 				printf("i = %d, j = %d, indic = %d\n", i, j, indic);
	// 			}
	// 			if (!ft_strcmp(point[j].name, way->end_room))
	// 			{
	// 				printf("Equal to end\n");
	// 				indic = 0;
	// 			}
	// 			// if (j == way->rmnumb-1)
	// 			// {
	// 			// 	printf("We are here to start again\n");
	// 			// 	//j = 0;
	// 			// }
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
	i = 0;
	while (i != way->rmnumb)
	{
		printf("name: %s index: %d\n", point[i].name, point[i].index);
		i++;
	}
}

static void ft_find_path(t_way *way)
{
	// int i;
	// int j;
	// t_map arr[3];
	// char *map1[] = {"str", "rom1", "end"};
	// char *map2[] = {"str", "rom2", "end"};
	// char *map3[] = {"str", "rom3", "rom4", "end"};
	// arr[0].map = map1;
	// arr[1].map = map2;
	// arr[2].map = map3;

	int		i;
	int		j;
	t_point	points[way->rmnumb];

	i = 0;
	j = 0;
	ft_bzero(points, way->rmnumb);
	while (i != way->rmnumb)
		points[i++].index = 0;
	i = 0;
	while (i != way->rmnumb)
	{
		points[j++].name = way->link[i];
		i++;
	}
	i = 0;
	printf("I do it\n");
	//points[1].lock = 0;
	while (i != way->rmnumb )
		printf("%s\n", points[i++].name);
	ft_move_graph(points, way);



	// i = -1;
	// while (++i != way->rmnumb)
	// {
	// 	j = -1;
	// 	while (++j != way->rmnumb)
	// 		printf("%d", way->matrix[i][j]);
	// 	printf("\n");
	// }
	// i = 0;
	// while (i != way->rmnumb)
	// {
	// 	printf("%s\n", way->link[i]);
	// 	i++;
	// }
	//way->maps = arr;
	//ft_fill_ants(way);
}

static void	ft_fill_way(t_farm *farm, int **matrix, char **link)
{
	int		i;
	int 	j;
	t_way	way;

	while (farm->links != NULL)
	{
		i = -1; 
		j = -1;
		while (++i != farm->roomnumb)	
			if (!ft_strcmp(farm->links->link->curr, link[i]))
				break;
		while (++j != farm->roomnumb)
			if (!ft_strcmp(farm->links->link->nex, link[j]))
				break ;
		matrix[i][j] = 1;
		matrix[j][i] = 1;
		farm->links = farm->links->next;
	}
	way.rmnumb = farm->roomnumb;
	way.matrix = matrix;
	way.link = link;
	way.ant = farm->ants;
	way.end_room = farm->end.name;
	ft_find_path(&way);
}

// printf("1 %s = %s\n", farm->links->link->curr, link[i]);
// printf("2 %s = %s\n", farm->links->link->nex, link[j]);

void	ft_mkarray(t_farm *farm)
{
	int		**matrix;//[farm->roomnumb][farm->roomnumb];
	char	*link[farm->roomnumb];
	int		i;
	int 	j;

	i = -1;
	if (!(matrix = (int**)(malloc(sizeof(int*) * farm->roomnumb))))
		return ;
	while (++i != farm->roomnumb)
	{
		j = -1;
		if (!(matrix[i] = (int*)(malloc(sizeof(int) * farm->roomnumb))))
			return ;
		while (++j != farm->roomnumb)
			matrix[i][j] = 0;
	}
	i = 1;
	link[0] = farm->start.name;
	while (farm->rooms != NULL)
	{
		link[i++] = farm->rooms->room->name;
		farm->rooms = farm->rooms->next;
	}
	link[i] = farm->end.name;
	ft_fill_way(farm, matrix, link);	
}