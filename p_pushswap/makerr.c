/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makerr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:11:42 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/08 15:55:19 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		makerrb(t_lcheck **tampon, t_moves **actions)
{
	t_lcheck	*tmp;
	t_lcheck	*ptr;

	if (!(stockactions(actions, 8)))
		return (0);
	if ((*tampon) && (*tampon)->next)
	{
		tmp = (*tampon);
		while ((*tampon)->next)
			(*tampon) = (*tampon)->next;
		ptr = (*tampon)->prev;
		ptr->next = NULL;
		(*tampon)->prev = NULL;
		tmp->prev = (*tampon);
		(*tampon)->next = tmp;
	}
	return (1);
}

int		makerra(t_lcheck **stock, t_moves **actions)
{
	t_lcheck	*tmp;
	t_lcheck	*ptr;

	if (!(stockactions(actions, 7)))
		return (0);
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
