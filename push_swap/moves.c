/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:28:58 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/21 19:00:40 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pushb(t_lcheck **stock, t_lcheck **tampon, t_moves **actions)
{
	t_lcheck *tmp;

	tmp = (*stock);
	if (!(stockactions(actions)))
		return (0);
	(*actions)->pb = 1;
	if ((*stock)->next)
		(*stock) = (*stock)->next;
	else
		(*stock) = NULL;
	tmp->prev = NULL;
	if ((*tampon))
	{
		tmp->next = (*tampon);
		(*tampon)->prev = tmp;
		(*tampon) = (*tampon)->prev;
	}
	else
	{
		tmp->next = NULL;
		(*tampon) = tmp;
	}
	return (1);
}

int		pusha(t_lcheck **stock, t_lcheck **tampon, t_moves **actions)
{
	t_lcheck	*tmp;

	tmp = (*tampon);
	if (!(stockactions(actions)))
		return (0);
	(*actions)->pa = 1;
	if ((*tampon)->next)
		(*tampon) = (*tampon)->next;
	else
		(*tampon) = NULL;
	tmp->prev = NULL;
	tmp->next = (*stock);
	if ((*stock))
	{
		tmp->next = (*stock);
		(*stock)->prev = tmp;
		(*stock) = (*stock)->prev;
	}
	else
	{
		tmp->next = NULL;
		(*stock) = tmp;
	}
	return (1);
}

int		makera(t_lcheck **stock, t_moves **actions)
{
	t_lcheck	*tmp;
	t_lcheck	*ptr;

	tmp = (*stock);
	if (!(stockactions(actions)))
		return (0);
	(*actions)->ra = 1;
	if ((*stock)->next)
	{
		(*stock) = (*stock)->next;
		ptr = (*stock);
		while (ptr->next)
			ptr = ptr->next;
		(*stock)->prev = NULL;
		tmp->prev = ptr;
		tmp->next = NULL;
		ptr->next = tmp;
	}
	return (1);
}

int		makerra(t_lcheck **stock, t_moves **actions)
{
	t_lcheck	*tmp;
	t_lcheck	*ptr;

	if (!(stockactions(actions)))
		return (0);
	(*actions)->rra = 1;
	if ((*stock)->next)
	{
		tmp = (*stock);
		while ((*stock)->next)
			(*stock) = (*stock)->next;
		ptr = (*stock)->prev;
		ptr->next = NULL;
		(*stock)->prev = NULL;
		tmp->prev = (*stock);
		(*stock)->next = tmp;
	}
	return (1);
}
