/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 10:54:50 by daalexan          #+#    #+#             */
/*   Updated: 2018/08/20 10:54:52 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_push(t_lst **head, char *name, t_pos pos)
{
	t_room	*room;
	t_lst	*curr;

	if (!(curr = (t_lst*)malloc(sizeof(t_lst))))
 		return ;
 	if (!(room = (t_room*)malloc(sizeof(t_room))))
 		return ;
	if ((*head) == NULL)
	{
		room->name = name;
		room->pos = pos;
		(*head)->room = room;
		(*head)->next = NULL;
 	}
 	else
 	{
 		while ((*head)->next != NULL)
 			(*head) = (*head)->next;
 		room->name = name;
		room->pos = pos;
		curr->room = room;
 		curr->next = NULL;
 		(*head)->next = curr;
 	}
}