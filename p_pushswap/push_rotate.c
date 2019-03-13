/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:50:41 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/13 12:39:51 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rev_push_rotate(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	t_lcheck	*tmp;
	int			i;
	int			k;

	tmp = (*tampon);
	i = 0;
	k = mediane(tampon);
	while (tmp && var > 0)
	{
		if (tmp->i > k)
		{
			i++;
			tmp = tmp->next;
			if (!(pusha(stock, tampon, actions)))
				return (-1);
		}
		else if (tmp->i <= k)
		{
			tmp = tmp->next;
			if (!(makerb(tampon, actions)))
				return (-1);
		}
		var--;
	}
	return (i);
}

int		push_rotate(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	int			k;
	int			i;
	t_lcheck	*tmp;

	tmp = (*stock);
	i = 0;
	k = mediane(stock);
	while (tmp && var > 0)
	{
		if (tmp->i < k)
		{
			i++;
			tmp = tmp->next;
			if (!(pushb(stock, tampon, actions)))
				return (-1);
		}
		else if (tmp->i >= k)
		{
			tmp = tmp->next;
			if (!(makera(stock, actions)))
				return (-1);
		}
		var--;
	}
	return (i);
}
