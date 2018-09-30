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

static int		ft_check_link(t_farm *farm, t_link *lk)
{
	t_lst	*begin;
	int		show;

	show = 0;
	begin = farm->rooms;
	if (!ft_strcmp(farm->start.name, lk->curr))
		show++;
	if (!ft_strcmp(farm->end.name, lk->nex))
		show++;
	while (begin != NULL)
	{
		// printf("%s = %s\n", begin->room->name, lk->curr);
		// printf("%s = %s\n", begin->room->name, lk->nex);
		if (!ft_strcmp(begin->room->name, lk->curr))
			show++;
		if (!ft_strcmp(begin->room->name, lk->nex))
			show++;
		begin = begin->next;
	}
	return ((show == 2) ? (1) : (0));
}

char	*ft_parse_link(char *str, int c)
{
	char	*arr;
	int		i;

	i = 0;
	if (!(arr = (char*)malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)	
			break;
		arr[i] = str[i];
		i++;
	}
	return (arr);
}

void	ft_mk_link(char *str, t_farm *farm)
{
	t_link	*lk;
	char	*arr;
	int		i;

	i = 0;
	if (!(arr = (char*)malloc(sizeof(char) * ft_strlen(str))))
		return ;
	if (!(lk = (t_link*)malloc(sizeof(t_link))))
		return ;
	lk->curr = ft_parse_link(str, '-');
	while (*str != '-' && *str)
			str++;
	str++;
	while (*str)
		arr[i++] = *str++;
	arr[i] = '\0';
	lk->nex = arr;

	if (ft_check_link(farm, lk))
		ft_lkpush(&farm->links, lk);
	else
	{
		ft_putstr("ERROR WITH LINK\n");
		exit(0);
	}
}

void	ft_filter_lines(char *str, t_farm *farm, int *valid)
{
	int room;
	int link;
	
	link = 0;
	room = 0;
	ft_eddfunc(str, &room, &link);
	if (link == 1 && *valid == 3)
		ft_mk_link(str, farm);
	else if (link == 1 && *valid != 3)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
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
		ft_write_name(rooms, str, 1);
		str = ft_strchr(str, ' ');
		rooms->pos.x = ft_atoi(str);
		str++;
		str = ft_strchr(str, ' ');
		rooms->pos.y = ft_atoi(str);
		if (ft_push(&farm->rooms, rooms))
			farm->roomnumb += 1;
		free(room);
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
	if (flag == 0)
		(void)flag;//ft_strdel(&str);
}

///
///	this two functions is merged into one function named ft_parse_room
///

// void	ft_add_room(char *str, t_farm *farm)
// {
// 
// // 	t_room	*room;
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

