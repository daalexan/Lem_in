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
	t_lst	*begin;

	if (!(curr = (t_lst*)malloc(sizeof(t_lst))))
		return ;
	if ((*head) == NULL)
	{
		curr->room = room;
		curr->next = NULL;
		(*head) = curr;
	}
	else
	{
		begin = (*head);
		while ((*head)->next != NULL)
			(*head) = (*head)->next;
		curr->room = room;
		curr->next = NULL;
		(*head)->next = curr;
		(*head) = begin;
	}
}

void	ft_mem_free(t_farm	*farm)
{
	t_lst		*fr;
	t_lstlink	*lnk;

	while (farm->links != NULL)
	{	
		lnk = farm->links;
		free(lnk->link);
		free(lnk);
		farm->links = farm->links->next;
	}
	while (farm->rooms != NULL)
	{	
		fr = farm->rooms;
		ft_strdel(&fr->room->name);
		free(fr->room);
		free(fr);
		farm->rooms = farm->rooms->next;
	}
}

void	ft_lkpush(t_lstlink **head, t_link *lk)
{
	t_lstlink	*lnk;
	t_lstlink	*begin;

	if (!(lnk = (t_lstlink*)malloc(sizeof(t_lstlink))))
		return ;
	if ((*head) == NULL)
	{
		lnk->link = lk;
		lnk->next = NULL;
		(*head) = lnk;
	}
	else
	{
		begin = (*head);
		while ((*head)->next != NULL)
			(*head) = (*head)->next;
		lnk->link = lk;
		lnk->next = NULL;
		(*head)->next = lnk;
		(*head) = begin;
	}
}
