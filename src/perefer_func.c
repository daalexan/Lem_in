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
	(void)str;
	(void)farm;
}

void	ft_add_room(char *str, t_farm *farm)
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return ;
	ft_write_name(room, str);
	str = ft_strchr(str, ' ');
	room->pos.x = ft_atoi(str);
	str++;
	str = ft_strchr(str, ' ');
	room->pos.y = ft_atoi(str);
	printf("before push\n");
	ft_push(&farm->rooms, room);
	printf("DONE\n");
	//free(room);
	//ft_strdel(&str);
}

void	ft_filter_lines(char *str, t_farm *farm)
{
	int room;
	int link;
	int i;

	i = 0;
	link = 0;
	room = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			room++;
		else if (str[i] == '-')
			link++;
		i++;
	}
	if (link == 1)
		ft_mk_link(str, farm);
	else if (room == 2)
		ft_add_room(str, farm);
}

void	ft_parse_room(char *str, t_room *room)
{
	get_next_line(0, &str);
	ft_write_name(room, str);
	str = ft_strchr(str, ' ');
	room->pos.x = ft_atoi(str);
	str++;
	str = ft_strchr(str, ' ');
	room->pos.y = ft_atoi(str);
}

void	ft_write_name(t_room *room, char *str)
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
}
