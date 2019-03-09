/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_when_pile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:35:52 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/09 13:10:09 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		other_sorts(t_lcheck **stock, t_moves **actions)
{
	if ((*stock)->i > (*stock)->next->i
	&& (*stock)->next->next->i < (*stock)->next->i)
	{
		if (!ft_swap_stock(stock, actions, 'a'))
			return (0);
		if (!(makera(stock, actions)))
			return (0);
		if (!ft_swap_stock(stock, actions, 'a'))
			return (0);
		if (!(makerra(stock, actions)))
			return (0);
		if (!ft_swap_stock(stock, actions, 'a'))
			return (0);
	}
	return (1);
}

int		sort_when_pile_a(t_lcheck **stock, t_moves **actions)
{
	if ((*stock)->i < (*stock)->next->i && (*stock)->next->next->i > (*stock)->i
	&& (*stock)->next->next->i < (*stock)->next->i)
	{
		if (!(makera(stock, actions)))
			return (0);
		if (!ft_swap_stock(stock, actions, 'a'))
			return (0);
		if (!(makerra(stock, actions)))
			return (0);
	}
	if ((*stock)->i > (*stock)->next->i && (*stock)->next->next->i < (*stock)->i
	&& (*stock)->next->next->i > (*stock)->next->i)
	{
		if (!ft_swap_stock(stock, actions, 'a'))
			return (0);
		if (!(makera(stock, actions)))
			return (0);
		if (!ft_swap_stock(stock, actions, 'a'))
			return (0);
		if (!(makerra(stock, actions)))
			return (0);
	}
	else if (!(other_sorts(stock, actions)))
		return (0);
	return (1);
}

int		tri_when_pile_a(t_lcheck **stock, t_moves **actions, int var)
{
	if ((*stock)->next && var == 2 && (*stock)->i > (*stock)->next->i)
		if (!ft_swap_stock(stock, actions, 'a'))
			return (0);
	if ((*stock)->next && var == 3)
	{
		if ((*stock)->i > (*stock)->next->i
		&& (*stock)->next->next->i > (*stock)->i)
			if (!ft_swap_stock(stock, actions, 'a'))
				return (0);
		if ((*stock)->i < (*stock)->next->i
		&& (*stock)->next->next->i < (*stock)->i)
		{
			if (!(makera(stock, actions)))
				return (0);
			if (!ft_swap_stock(stock, actions, 'a'))
				return (0);
			if (!(makerra(stock, actions)))
				return (0);
			if (!ft_swap_stock(stock, actions, 'a'))
				return (0);
		}
		else if (!sort_when_pile_a(stock, actions))
			return (0);
	}
	return (1);
}
