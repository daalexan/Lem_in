/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:24:24 by daalexan          #+#    #+#             */
/*   Updated: 2018/08/17 10:24:53 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_num_ant(char *str, t_farm *farm)
{
	int num;

	num = ft_atoi(str);
	if (num > 0)
		farm->ants = num;
	else
	{
		printf("ERROR\n");
		exit(0);
	}
}

int main(void)
{
	char	*str;
	t_farm	farm;

	farm.rooms = NULL;
	ft_bzero(&farm, sizeof(t_farm));
	while (get_next_line(0, &str) > -1)
	{
		if (!farm.ants)
			ft_num_ant(str, &farm);
		else if (str && !ft_strncmp(str, "##start", 7))
			ft_parse_room(str, &farm.start);
		else if (str && !ft_strncmp(str, "##end", 5))
			ft_parse_room(str, &farm.end);
		else
		{
			printf("TYT\n");
			ft_filter_lines(str, &farm);
		}
		if (!ft_strncmp(str, "stop", 4))
		{
			break;
		}
		
		ft_strdel(&str);
	}
	while (farm.rooms != NULL)
	{	
		printf("here\n");
		printf("LIST DAta %s, %d, %d\n", farm.rooms->room->name, farm.rooms->room->pos.x, farm.rooms->room->pos.y);
		farm.rooms = farm.rooms->next;
	}
	system("leaks lem-in");
	return (0);
}
