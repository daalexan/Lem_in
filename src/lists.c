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

void	ft_push(t_lst **head, t_room *room)
{
	t_lst	*curr;

	if (!(curr = (t_lst*)malloc(sizeof(t_lst))))
		return ;
	if ((*head) == NULL)
	{
		printf("data %s %d %d\n", room->name, room->pos.x, room->pos.y);
		curr->room = room;
		curr->next = NULL;
		(*head) = curr;
	}
	else
	{	
		while ((*head)->next != NULL)
			(*head) = (*head)->next;
		curr->room = room;
		curr->next = NULL;
		(*head)->next = curr;
	}
	printf("END\n");
}