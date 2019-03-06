/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:28:58 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/06 18:02:29 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pushb(t_lcheck **stock, t_lcheck **tampon, t_moves **actions)
{
	t_lcheck *tmp;

	tmp = (*stock);
	if (!(stockactions(actions, 4)))
		return (0);
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
	if (!(stockactions(actions, 3)))
		return (0);
	if ((*tampon)->next)
		(*tampon) = (*tampon)->next;
	else
		(*tampon) = NULL;
	tmp->prev = NULL;
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

int		makerb(t_lcheck **tampon, t_moves **actions)
{
	t_lcheck	*tmp;
	t_lcheck	*ptr;

	tmp = (*tampon);
	if (!(stockactions(actions, 6)))
		return (0);
	if ((*tampon)->next)
	{
		(*tampon) = (*tampon)->next;
		ptr = (*tampon);
		while (ptr->next)
			ptr = ptr->next;
		(*tampon)->prev = NULL;
		tmp->prev = ptr;
		tmp->next = NULL;
		ptr->next = tmp;
	}
	return (1);
}

int		makera(t_lcheck **stock, t_moves **actions)
{
	t_lcheck	*tmp;
	t_lcheck	*ptr;

	tmp = (*stock);
	if (!(stockactions(actions, 5)))
		return (0);
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

int		ft_swap_stock(t_lcheck **stock, t_moves **actions, char c)
{
	ft_swap(&(((*stock)->i)), &((*stock)->next->i));
	if (c == 'a')
	{
		if (!(stockactions(actions, 1)))
			return (0);
	}
	else if (c == 'b')
	{
		if (!(stockactions(actions, 2)))
			return (0);
	}
	return (1);
}
