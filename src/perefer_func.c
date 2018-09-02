/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perefer_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:29:33 by daalexan          #+#    #+#             */
/*   Updated: 2018/08/17 12:29:34 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_mk_link(char *str, t_farm *farm)
{
	t_link	*lk;

	if (!(lk = (t_link*)malloc(sizeof(t_link))))
		return ;
	lk->curr = ft_atoi(str);
	str = ft_strchr(str, '-');
	str++;
	lk->next = ft_atoi(str);
	ft_lkpush(&farm->links, lk);
}

void	ft_check_line(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0' && str[i] != ' ')
	{
		if (str[i] < 48 || str[i] > 59)
		{
			ft_putstr("ERROR\n");
			exit(0);
		}
		i++;
	}
}

void	ft_check_neg(char *str)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (str[i++])
	{
		if (str[i] == ' ')
			nbr++;
	}
	if (nbr != 2)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
}

void	ft_valid_room(char *line)
{
	int		nbr;
	char	*str;
	
	nbr = 0;
	str = line;
	ft_check_neg(str);
	str = ft_strchr(str, ' ');
	ft_check_line(str);
	nbr = ft_atoi(str);
	if (nbr < 0 || nbr > 2147483647)
	{
		ft_putstr("ERROR\n");
		return ;
	}
	str++;
	str = ft_strchr(str, ' ');
	ft_check_line(str);
	nbr = ft_atoi(str);
	if (nbr < 0 || nbr > 2147483647)
	{
		ft_putstr("ERROR\n");
		return ;
	}
}

void	ft_check_comment(char *str)
{
	if (str[0] != '#')
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
}

void	ft_filter_lines(char *str, t_farm *farm, int i)
{
	int room;
	int link;

	link = 0;
	room = 0;
	while (str[i++])
	{
		if (str[i] == ' ')
			room++;
		else if (str[i] == '-' && str[i - 1] != ' ')
			link++;
	}
	if (link == 1)
		ft_mk_link(str, farm);
	else if (room == 2)
	{
		ft_valid_room(str);
		ft_parse_room(str, farm, NULL);
	}
	else
		ft_check_comment(str);
}

void	ft_parse_room(char *str, t_farm *farm, t_room *room)
{
	t_room	*rooms;

	if (farm)
	{
		if (!(rooms = (t_room*)malloc(sizeof(t_room))))
			return ;
		ft_write_name(rooms, str, 0);
		str = ft_strchr(str, ' ');
		rooms->pos.x = ft_atoi(str);
		str++;
		str = ft_strchr(str, ' ');
		rooms->pos.y = ft_atoi(str);
		ft_push(&farm->rooms, rooms);
	}
	else
	{
		get_next_line(0, &str);
		ft_valid_room(str);
		ft_write_name(room, str, 0);
		str = ft_strchr(str, ' ');
		room->pos.x = ft_atoi(str);
		str++;
		str = ft_strchr(str, ' ');
		room->pos.y = ft_atoi(str);
	}
}

void	ft_write_name(t_room *room, char *str, int flag)
{
	int len;
	int i;

	len = 0;
	while (str[len] != ' ')
		len++;
	if (!(room->name = (char*)malloc(sizeof(char) * (len + 1))))
		return ;
	i = 0;
	while (i < len)
	{
		room->name[i] = str[i];
		i++;
	}
	room->name[i] = '\0';
	if (flag == 1)
		ft_strdel(&str);
}

///
///	this two functions is merged into one function named ft_parse_room
///

// void	ft_add_room(char *str, t_farm *farm)
// {
// 	t_room	*room;

// 	if (!(room = (t_room*)malloc(sizeof(t_room))))
// 		return ;
// 	ft_write_name(room, str, 0);
// 	str = ft_strchr(str, ' ');
// 	room->pos.x = ft_atoi(str);
// 	str++;
// 	str = ft_strchr(str, ' ');
// 	room->pos.y = ft_atoi(str);
// 	ft_push(&farm->rooms, room);
// }

// void	ft_parse_room(char *str, t_room *room)
// {
// 	get_next_line(0, &str);
// 	ft_write_name(room, str, 1);
// 	str = ft_strchr(str, ' ');
// 	room->pos.x = ft_atoi(str);
// 	str++;
// 	str = ft_strchr(str, ' ');
// 	room->pos.y = ft_atoi(str);
// }

