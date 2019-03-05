/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trinbs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:26:16 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/05 12:26:32 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sortnum(t_lcheck **stock, t_moves **actions, t_lcheck *tmp)
{
	if ((*stock)->i > (*stock)->next->i && tmp->i > (*stock)->next->i)
	{
		if (!(makera(stock, actions)))
			return (0);
	}
	else if ((*stock)->i < (*stock)->next->i && tmp->i < (*stock)->i)
	{
		if (!(makerra(stock, actions)))
			return (0);
	}
	else if ((*stock)->i < (*stock)->next->i && (tmp->i < (*stock)->next->i
	&& tmp->i > (*stock)->i))
	{
		ft_swap(&(((*stock)->i)), &((*stock)->next->i));
		if (!(makera(stock, actions)))
			return (0);
	}
	return (1);
}

int		trinbs(t_lcheck **stock, t_moves **actions)
{
	t_lcheck *tmp;

	tmp = (*stock);
	while (tmp->next)
		tmp = tmp->next;
	if ((*stock)->next)
	{
		if ((*stock)->i > (*stock)->next->i && tmp->i > (*stock)->i)
			ft_swap(&(((*stock)->i)), &((*stock)->next->i));
		else if ((*stock)->i > (*stock)->next->i && tmp->i < (*stock)->next->i)
		{
			ft_swap(&(((*stock)->i)), &((*stock)->next->i));
			if (!(makerra(stock, actions)))
				return (0);
		}
		else if (!(sortnum(stock, actions, tmp)))
			return (0);
	}
	return (1);
}
