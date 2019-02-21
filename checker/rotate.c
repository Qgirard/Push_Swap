/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:29:15 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/21 18:49:01 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverserotateb(t_pile **temp)
{
	t_pile	*tmp;
	t_pile	*ptr;

	if ((*temp) && (*temp)->next)
	{
		tmp = (*temp);
		while ((*temp)->next)
			(*temp) = (*temp)->next;
		ptr = (*temp)->prev;
		ptr->next = NULL;
		(*temp)->prev = NULL;
		tmp->prev = (*temp);
		(*temp)->next = tmp;
	}
}

void	reverserotatea(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*ptr;

	if ((*pile) && (*pile)->next)
	{
		tmp = (*pile);
		while ((*pile)->next)
			(*pile) = (*pile)->next;
		ptr = (*pile)->prev;
		ptr->next = NULL;
		(*pile)->prev = NULL;
		tmp->prev = (*pile);
		(*pile)->next = tmp;
	}
}

void	rotatea(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*ptr;

	tmp = (*pile);
	if ((*pile) && (*pile)->next)
	{
		(*pile) = (*pile)->next;
		ptr = (*pile);
		while (ptr->next)
			ptr = ptr->next;
		(*pile)->prev = NULL;
		tmp->prev = ptr;
		tmp->next = NULL;
		ptr->next = tmp;
	}
}

void	rotateb(t_pile **temp)
{
	t_pile	*tmp;
	t_pile	*ptr;

	tmp = (*temp);
	if ((*temp) && (*temp)->next)
	{
		(*temp) = (*temp)->next;
		ptr = (*temp);
		while (ptr->next)
			ptr = ptr->next;
		(*temp)->prev = NULL;
		tmp->prev = ptr;
		tmp->next = NULL;
		ptr->next = tmp;
	}
}
