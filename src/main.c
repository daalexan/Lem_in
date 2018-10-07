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

// void	ft_valid_stend(char *str, int i)
// {
// 	if (i == 1)
// 	{
// 		if (str[7] != '\0')
// 		{
// 			printf("ERROR\n");
// 			exit(0);
// 		}
// 	}
// 	else if (i == 0)
// 	{
// 		if (str[5] != '\0')
// 		{
// 			printf("ERROR\n");
// 			exit(0);
// 		}
// 	}
// }

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
			ft_putstr("ERROR 1\n");
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
		{
			ft_strdel(&str);
			ft_putstr("ERROR 1\n");
			return (1);
		}
		else if (str && !ft_strncmp(str, "##end", 5))
		{
			ft_strdel(&str);
			ft_putstr("ERROR 2\n");
			return (1);
		}
		else
		{
			ft_strdel(&str);
			ft_putstr("ERROR COpe\n");
			return (1);
		}
	}	
	else
		return (0);
}

// int	check_validation(t_farm *farm, char *str, int *validation)
// {
// 	if (*validation == 3 && !ft_strcmp(str, ""))
// 	{
// 		ft_mkarray(farm);
// 		ft_strdel(&str);
// 		return (0);
// 	}
// 	else if (*validation != 3 && !ft_strcmp(str, ""))
// 	{
// 		ft_putstr("ERROR space\n");
// 		ft_strdel(&str);
// 		return (0);
// 	}
// 	if (*validation == 0)
// 	{
// 		if (ft_check_start(str))
// 			return (0);
// 		ft_num_ant(str, farm, validation);
// 	}
// 	else
// 		ft_begin(str, farm, validation);
// 	return (1);
// }

int main(void)
{
	char	*str;
	t_farm	farm;
	int validation;

	validation = 0;
	str = NULL;
	farm.rooms = NULL;
	ft_bzero(&farm, sizeof(t_farm));
	while (get_next_line(0, &str) > -1)
	{
		if (str[0] == '#' && str[1] != '#')
		{
			ft_strdel(&str);
			continue;
		}
		if (!check_validation(&farm, str, &validation))
			break;
		ft_strdel(&str);
	}
	//ft_free_link(&farm.links);
	//ft_mem_free(&farm);
	system("leaks lem-in");
	return (0);
}
