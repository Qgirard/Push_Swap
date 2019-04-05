/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:50:41 by qgirard           #+#    #+#             */
/*   Updated: 2019/04/05 14:22:13 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_rb_in_b(t_lcheck **tampon, t_lcheck **tmp, t_moves **actions,
		int *j)
{
	*j = *j + 1;
	*tmp = (*tmp)->next;
	if (!(makerb(tampon, actions)))
		return (0);
	return (1);
}

int		count_ra_in_a(t_lcheck **stock, t_lcheck **tmp, t_moves **actions,
		int *j)
{
	*j = *j + 1;
	*tmp = (*tmp)->next;
	if (!(makera(stock, actions)))
		return (0);
	return (1);
}

void	variables(t_lcheck **stock, t_lcheck **tmp, int *i, int *j)
{
	*tmp = (*stock);
	*i = 0;
	*j = 0;
}

int		rev_push_rotate(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	t_lcheck	*tmp;
	int			i;
	int			j;
	int			k;

	variables(tampon, &tmp, &i, &j);
	k = mediane(tampon, var);
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
			if (!count_rb_in_b(tampon, &tmp, actions, &j))
				return (-1);
		var--;
	}
	if (!make_order_in_pile(tampon, actions, j, 2))
		return (-1);
	return (i);
}

int		push_rotate(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	int			k;
	int			i;
	int			j;
	t_lcheck	*tmp;

	variables(stock, &tmp, &i, &j);
	k = mediane(stock, var);
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
			if (!count_ra_in_a(stock, &tmp, actions, &j))
				return (-1);
		var--;
	}
	if (!make_order_in_pile(stock, actions, j, 1))
		return (-1);
	return (i);
}
