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
	int	num;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 49 || str[i] > 59)
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
		{
			ft_valid_stend(str, 1);
			ft_parse_room(str, NULL, &farm.start);
		}
		else if (str && !ft_strncmp(str, "##end", 5))
		{
			ft_valid_stend(str, 0);
			ft_parse_room(str, NULL, &farm.end);
		}
		else
		{
			if (!ft_strncmp(str, "stop", 4))	
				break;
			ft_filter_lines(str, &farm, 0);
		}
		ft_strdel(&str);
	}
	printf("name %s x %d y %d\n", farm.start.name, farm.start.pos.x, farm.start.pos.y);
	ft_mem_free(&farm);
	system("leaks lem-in");
	return (0);
}
