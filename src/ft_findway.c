#include "lemin.h"

int		ft_get_path_size(t_way *way)
{
	int j;
	int len;

	j = 0;
	len = 0;
	while (j != way->rmnumb)
	{

		if (way->matrix[way->rmnumb-1][j] == 1)
		{
			//printf("Node: %s\n", way->link[j]);
			len++;
		}
		j++;
	}
	return (len);
}

int ft_smallest(t_way *way, t_point *point, int row)
{
	int small;
	int i;
	int ind;

	i = 0;
	small = 30000;
	while (i != way->rmnumb)
	{
		if (ft_strcmp(point[i].name, point[0].name) &&
			ft_strcmp(point[i].name, way->end_room) &&
			way->matrix[row][i] == 1 && point[i].lock != 1)
		{
			if (point[i].index <= small)
			{
				small = point[i].index;
				ind = i;
			}
		}
		i++;
	}
	if (small == 30000)
		return (-1);
	return (ind);
}

void	ft_fill_path(char **map, t_way *way, t_point *point, int pnt)
{
	int i;
	int j;

	// i = 0;
	// printf("POINTS\n");
	// while (i != way->rmnumb)
	// {
	// 	printf("name[%s] index: %d\n", point[i].name, point[i].index);
	// 	i++;
	// }
	j = pnt;
	i = point[pnt].index;
	map[i+1] = way->end_room;
//	printf("map[%d] = %s\n", i+1, map[i+1]);
	while (i > 0)
	{
		//printf("point_curr: %s = point_str: %s <> point_curr: %s = point_end: %s\n", point[j].name, point[0].name, point[j].name, way->end_room);
		if (!ft_strcmp(point[j].name, point[0].name) ||
			!ft_strcmp(point[j].name, way->end_room))
		{
			//printf("map = %s | point = %s BREAK;\n", map[i], point[j].name);
			break;
		}
		map[i] = point[j].name;
		//printf("map[%d] = %s | point = %s\n", i, map[i], point[j].name);
		point[j].lock = 1;
		if ((j = ft_smallest(way, point, j)) == -1)
		{
		//	printf("Last Break\n");
			break;
		}
		i--;
	}
	//i--;
	map[0] = point[0].name;
	if (i == 0)
		way->nbr_map += 1;
}

void	ft_check_path(t_point *point, t_way *way, t_map *path, int i)
{
	int j;
	int pnt;

	j = 0;
	//printf("size path = %d\n", i);
	if (way->rmnumb == 2 || way->matrix[0][way->rmnumb-1] == 1)
	{
		//printf("Numb = 2\n");
		if (!(path[j].map = (char**)malloc(sizeof(char*) * 2)))
			return ;
		path[j].map[0] = point[0].name;
		path[j].map[1] = point[way->rmnumb-1].name;
		way->nbr_map = 1;
		j++;
	}
	while (j != i)
	{
		if ((pnt = ft_smallest(way, point, way->rmnumb-1)) == -1)
			break;
		//printf("The smallest = %d its name: %s\n", pnt, point[pnt].name);
		if (!(path[j].map = (char**)malloc(sizeof(char*) * (point[pnt].index + 2))))
			return ;
		ft_fill_path(path[j].map, way, point, pnt);
		j++;
	}
	// int j;
	// int pnt;

	// j = 0;
	// printf("size path = %d\n", i);
	// if (way->rmnumb == 2)
	// {
	// 	printf("Numb = 2\n");
	// 	if (!(path[0].map = (char**)malloc(sizeof(char*) * 2)))
	// 		return ;
	// 	path[0].map[0] = point[0].name;
	// 	path[0].map[1] = point[way->rmnumb-1].name;
	// }
	// else
	// {
	// 	while (j != i)
	// 	{
	// 		if ((pnt = ft_smallest(way, point, way->rmnumb-1)) == -1)
	// 			break;
	// 		//printf("The smallest = %d its name: %s\n", pnt, point[pnt].name);
	// 		if (!(path[j].map = (char**)malloc(sizeof(char*) * (point[pnt].index + 2))))
	// 			return ;
	// 		ft_fill_path(path[j].map, way, point, pnt);
	// 		j++;
	// 	}
	// }
}

void	ft_set_index(t_way *way, t_point *point)
{
	// int i;
	// int j;
	// int stack[way->rmnumb];
	// short flag;
	// int stk_ptr;
	// int sum;

	// i = 0;
	// j = -1;
	// sum = 0;
	// stk_ptr = 0;
	// flag = 0;
	// while (!flag)
	// {
	// 	while (!flag)
	// 	{
	// 		++j;
	// 		if (point[j].index == 0 && ft_strcmp(point[j].name, way->end_room) &&
	// 			ft_strcmp(point[j].name, point[0].name) && way->matrix[i][j] == 1)
	// 		{
	// 			printf("Inside\n");
	// 			point[j].index = point[i].index + 1;
	// 		}
	// 		else if (way->matrix[i][j] == 1 && !ft_strcmp(point[j].name, way->end_room))
	// 		{
	// 			printf("Inside back\n");
	// 			stack[stk_ptr] = 0;
	// 			stk_ptr--;
	// 			i = stack[stk_ptr];
	// 			j = 0;
	// 		}
	// 		else if (way->matrix[i][j] == 1 && point[j].index != 0 && point[j].lock == 0)
	// 		{
	// 			printf("Inside inside\n");
	// 			point[j].lock = 1;
	// 			stack[stk_ptr] = i;
	// 			i = j;
	// 			stk_ptr++;
	// 		}
	// 		if (j + 1 == way->rmnumb)
	// 		{
	// 			printf("j = 0\n");
	// 			j = 0;
	// 			while (j != way->rmnumb)
	// 			{
	// 				if (point[j++].index != 0)
	// 					sum++; 
	// 			}
	// 			if (sum == way->rmnumb)
	// 				flag = 1;
	// 			j = -1;
	// 		}
	// 	}
	// }

	// i = 0;
	// while (i != way->rmnumb)
	// {
	// 	printf("name: %s index: %d\n", point[i].name, point[i].index);
	// 	i++;
	// }
	/*
	Old algorithm
	*/
	// 	i = -1;
	// while (++i != way->rmnumb)
	// {
	// 	j = -1;
	// 	while (++j != way->rmnumb)
	// 	{
	// 		printf("%d", way->matrix[i][j]);
	// 	}
	// 	printf("\n");
	// }
	int i;
	int j;
	int again;

	i = -1;
	again = 0;
	while (++i != way->rmnumb)
	{
		if (again == 1 && i == 0)
			again = 0;
		j = -1;
		while (++j != way->rmnumb)
		{
			if (point[j].index == 0 && ft_strcmp(point[j].name, way->end_room) &&
				ft_strcmp(point[j].name, point[0].name) && way->matrix[i][j] == 1)
			{
				if (i > 0 && point[i].index == 0)
					again = 1;
				else
					point[j].index = point[i].index + 1;
			}
		}
		if (i + 1 == way->rmnumb && again == 1)
			i = -1;
	}
	// i = 0;
	// while (i != way->rmnumb)
	// {
	// 	printf("name: %s index: %d\n", point[i].name, point[i].index);
	// 	i++;
	// }
}

void	ft_move_graph(t_point *point, t_way *way)
{
	int		i;
	//int		j;
	t_map	*path;

	ft_set_index(way, point);
	//printf("i = %d j = %d\n", i, j);
	i = ft_get_path_size(way);
	if (i > way->ant)
		i = way->ant;
	if (i == 1)
		way->nbr_map = 1;
	if (!(path = (t_map*)malloc(sizeof(t_map) * i)))
		return ;
	ft_check_path(point, way, path, i);
	//printf("name: %s name: %s\n", path[0].map[0], path[0].map[1]);
	way->maps = path;
	ft_fill_ants(way);
	// i = 0;
	// j = 0;
	// while (i != way->nbr_map)
	// {
	// 	j = 0;
	// 	while (path[i].map[j] != NULL)
	// 	{
	// 		printf("map: %s\n", path[i].map[j]);
	// 		j++;
	// 	}
	// 	i++;
	// }
	

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
	// i = 0;
	// while (i != way->rmnumb)
	// {
	// 	printf("name: %s index: %d\n", point[i].name, point[i].index);
	// 	i++;
	// }
	// printf("I;tsdf Mario\n");
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
	// printf("I do it\n");
	// //points[1].lock = 0;
	// while (i != way->rmnumb )
	// 	printf("%s\n", points[i++].name);
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
	way.nbr_map = 0;
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
