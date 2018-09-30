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

static int	ft_exist(t_lst **head, t_room *room)
{
	t_lst	*begin;

	begin = (*head);
	if (begin == NULL)
		return (0);
	else
	{
		while (begin != NULL)
		{
			//printf("%s == %s\n", begin->room->name, room->name);
			if (!ft_strcmp(begin->room->name, room->name))
			{
			//	printf("EXIst %s == %s\n", begin->room->name, room->name);
				return (1);
			}
			begin = begin->next;
		}
		return (0);
	}
}

int	ft_push(t_lst **head, t_room *room)
{
	t_lst	*curr;
	t_lst	*begin;

	if (!ft_exist(head, room))
	{
		if (!(curr = (t_lst*)malloc(sizeof(t_lst))))
			return (0);
		if ((*head) == NULL)
		{
			curr->room = room;
			curr->next = NULL;
			(*head) = curr;
			return (1);
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
			return (1);
		}
	}
	return (0);
}

void	ft_mem_free(t_farm	*farm)
{
	t_lst		*fr;
	t_lstlink	*lnk;

	while (farm->links != NULL)
	{
		printf("before -> curr: %s nex: %s\n", farm->links->link->curr, farm->links->link->curr);
		lnk = farm->links;
		free(lnk->link->curr);
		free(lnk->link->nex);
		free(lnk);
		printf("after -> curr: %s nex: %s\n", farm->links->link->curr, farm->links->link->curr);
		farm->links = farm->links->next;
	}
	while (farm->rooms != NULL)
	{
		printf("name: %s x: %d y: %d\n", farm->rooms->room->name, farm->rooms->room->pos.x, farm->rooms->room->pos.y);
		fr = farm->rooms;
		ft_strdel(&fr->room->name);
		free(fr->room);
		free(fr);
		printf("name: %s x: %d y: %d\n", farm->rooms->room->name, farm->rooms->room->pos.x, farm->rooms->room->pos.y);
		farm->rooms = farm->rooms->next;
	}
	free(farm->start.name);
	free(farm->end.name);	
}

static int	ft_lk_exist(t_lstlink **head, t_link *lk)
{
	t_lstlink	*begin;

	begin = (*head);
	if (begin == NULL)
		return (0);
	else
	{
		//printf("test before %s == %s && %s == %s\n", begin->link->curr, lk->curr, begin->link->nex, lk->nex);
		while (begin != NULL)
		{
			//printf("test link nex %s == %s\n", begin->link->nex, lk->nex);
			if (!ft_strcmp(begin->link->curr, lk->curr) &&
				!ft_strcmp(begin->link->nex, lk->nex))
			{
			//	printf("exist %s == %s && %s == %s\n", begin->link->curr, lk->curr, begin->link->nex, lk->nex);
				return (1);
			}
			begin = begin->next;
		}
		return (0);
	}
}

void	ft_lkpush(t_lstlink **head, t_link *lk)
{
	t_lstlink	*lnk;
	t_lstlink	*begin;

	if (!ft_lk_exist(head, lk))
	{
		if (!(lnk = (t_lstlink*)malloc(sizeof(t_lstlink))))
			return ;
		if ((*head) == NULL)
		{
			lnk->link = lk;
			lnk->next = NULL;
			(*head) = lnk;
		//	printf("NULL  %s == %s && %s == %s\n", (*head)->link->curr, lk->curr, (*head)->link->nex, lk->nex);
		}
		else
		{
			//printf("data1  %s == %s && %s == %s\n", (*head)->link->curr, lk->curr, (*head)->link->nex, lk->nex);
			begin = (*head);
			while ((*head)->next != NULL)
			{
				//printf("data %s == %s && %s == %s\n", (*head)->link->curr, lk->curr, (*head)->link->nex, lk->nex);
				(*head) = (*head)->next;
			}
			lnk->link = lk;
			lnk->next = NULL;		
			(*head)->next = lnk;
			(*head) = begin;
		}
	}
}
