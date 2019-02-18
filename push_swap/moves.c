/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:28:58 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/18 17:43:56 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushb(t_lcheck **stock, t_lcheck **tampon)
{
	t_lcheck *tmp;

	tmp = (*stock);
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
}

void	makera(t_lcheck **stock)
{
	t_lcheck	*tmp;
	t_lcheck	*ptr;

	tmp = (*stock);
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
}

void	makerra(t_lcheck **stock)
{
	t_lcheck	*tmp;
	t_lcheck	*ptr;

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
}
