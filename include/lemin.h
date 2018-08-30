/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:21:02 by daalexan          #+#    #+#             */
/*   Updated: 2018/08/17 10:22:14 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>		//delete

typedef struct			s_link
{
	int					curr;
	int					next;
}						t_link;

typedef	struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct			s_room
{
	char				*name;
	t_pos				pos;
}						t_room;

typedef	struct			s_lst
{
	t_room				*room;
	struct s_lst		*next;
}						t_lst;

typedef	struct			s_lstlink
{
	t_link				*link;
	struct s_lstlink	*next;
}						t_lstlink;

typedef	struct			s_farm
{
	int					ants;
	t_room				start;
	t_room				end;
	t_lst				*rooms;
	t_lstlink			*links;
}						t_farm;

void					ft_write_name(t_room *room, char *str, int flag);
void					ft_filter_lines(char *str, t_farm *farm);
void					ft_parse_room(char *str, t_farm *farm, t_room *room);
void					ft_push(t_lst **head, t_room *room);
void					ft_mem_free(t_farm	*farm);
void					ft_lkpush(t_lstlink **head, t_link *lk);

#endif
