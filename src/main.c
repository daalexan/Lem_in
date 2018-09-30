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

void	ft_num_ant(char *str, t_farm *farm, int *validation)
{
	int	num;
	int	i;

	if (str[0] != '#')
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] < 48 || str[i] > 57)
			{
				ft_putstr("ERROR\n");
				exit(0);
			}
			i++;
		}
		num = ft_atoi(str);
		if (num > 0)
			farm->ants = num;
		else
		{
			ft_putstr("ERROR\n");
			exit(0);
		}
		*validation = 1;
	}
}

void	ft_valid_stend(char *str, int i)
{
	if (i == 1)
	{
		if (str[7] != '\0')
		{
			printf("ERROR\n");
			exit(0);
		}
	}
	else if (i == 0)
	{
		if (str[5] != '\0')
		{
			printf("ERROR\n");
			exit(0);
		}
	}
}

void	ft_begin(char *str, t_farm *farm, int *validation)
{
	if (str[0] == '#' && str[1] == '#')
	{
		if (*validation == 1 && str && !ft_strncmp(str, "##start", 7))
		{
			ft_valid_stend(str, 1);
			ft_parse_room(str, NULL, &farm->start);
			farm->roomnumb += 1;
			*validation = 2;
		}
		else if (*validation == 2 && str && !ft_strncmp(str, "##end", 5))
		{
			ft_valid_stend(str, 0);
			ft_parse_room(str, NULL, &farm->end);
			farm->roomnumb += 1;
			*validation = 3;
		}
		else
		{
			ft_putstr("ERROR\n");
			exit(0);
		}
	}
	else
		ft_filter_lines(str, farm, validation);
}

int	ft_check_start(char *str)
{
	if (str[0] == '#' && str[1] == '#')
	{
		if (str && !ft_strncmp(str, "##start", 7))
			return (1);
		else if (str && !ft_strncmp(str, "##end", 5))
			return (1);
		else
			return (1);
	}	
	else
		return (0);
}

void	ft_show(t_farm *farm)
{
	t_lst *begin;
	t_lstlink *head;

	begin = farm->rooms;
	printf("name: %s x: %d y: %d\n", farm->start.name, farm->start.pos.x, farm->start.pos.y);
	while (begin != NULL)
	{
		printf("name: %s x: %d y: %d\n", begin->room->name, begin->room->pos.x, begin->room->pos.y);
		begin = begin->next;
	}
	printf("name: %s x: %d y: %d\n", farm->end.name, farm->end.pos.x, farm->end.pos.y);
	head = farm->links;
	while (head != NULL)
	{
		printf("curn: %s nex: %s\n", head->link->curr, head->link->nex);
		head = head->next;
	}
	printf("ROOMNUMB= %d\n", farm->roomnumb);
}

int main(void)
{
	char	*str;
	t_farm	farm;
	int validation;

	validation = 0;
	farm.rooms = NULL;
	ft_bzero(&farm, sizeof(t_farm));
	while (get_next_line(0, &str) > -1)
	{
		if (!ft_strncmp(str, "stop", 4))
		{
			ft_mkarray(&farm);
			//ft_show(&farm);
			ft_strdel(&str);
			break ;
		}
		if (validation == 0)
		{
			if (ft_check_start(str))
			{
				ft_putstr("ERROR\n");
				ft_strdel(&str);
				break ;
			}
			ft_num_ant(str, &farm, &validation);
		}
		else
			ft_begin(str, &farm, &validation);
		ft_strdel(&str);
	}
	ft_strdel(&str);
	ft_mem_free(&farm);
	return (0);
}
