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

/*
**	part of initialization parsing, reading.
*/

typedef struct			s_link
{
	char				*curr;
	char				*nex;
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
	int					roomnumb;
	t_room				start;
	t_room				end;
	t_lst				*rooms;
	t_lstlink			*links;
}						t_farm;

/*
** part of solving
*/

typedef struct			s_point
{
	char				*name;
	int					index;
	short				lock;
}						t_point;

typedef struct			s_map
{
	char				**map;
}						t_map;

typedef	struct			s_way
{
	int					ant;
	int					rmnumb;
	int					**matrix;
	char				**link;
	t_map				*maps;
	char				*end_room;
	int					nbr_map;
}						t_way;

typedef	struct			s_ant
{
	int					end;
	int					name;
	int 				cur_room;
	char				**map;
}						t_ant;

void					ft_write_name(t_room *room, char *str, int flag);
void					ft_filter_lines(char *str, t_farm *farm, int *valid);
void					ft_parse_room(char *str, t_farm *farm, t_room *room);
int						ft_push(t_lst **head, t_room *room);
void					ft_mem_free(t_farm	*farm);
void					ft_lkpush(t_lstlink **head, t_link *lk);

void					ft_check_comment(char *str);
void					ft_check_neg(char *str);
void					ft_check_line(char *str);
void					ft_valid_room(char *line);
void					ft_eddfunc(char *str, int *room, int *link);

void					ft_mkarray(t_farm *farm);

void					ft_fill_ants(t_way *way);

#endif
