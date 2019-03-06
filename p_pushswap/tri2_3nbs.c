/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri2_3nbs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:46:50 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/06 15:34:03 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_in_b(t_lcheck **tampon, t_moves **actions, t_lcheck *tmp)
{
	if ((*tampon)->i < (*tampon)->next->i && (tmp->i < (*tampon)->next->i
	&& tmp->i > (*tampon)->i))
	{
		if (!(makerb(tampon, actions)))
			return (0);
	}
	else if ((*tampon)->i > (*tampon)->next->i && (tmp->i > (*tampon)->next->i
	&& tmp->i < (*tampon)->i))
	{
		if (!ft_swap_stock(tampon, actions, 'b'))
			return (0);
		if (!(makerb(tampon, actions)))
			return (0);
	}
	else if ((*tampon)->i < (*tampon)->next->i && tmp->i > (*tampon)->next->i)
	{
		if (!ft_swap_stock(tampon, actions, 'b'))
			return (0);
		if (!(makerrb(tampon, actions)))
			return (0);
	}
	return (1);
}

int		tri_in_b(t_lcheck **tampon, t_moves **actions)
{
	t_lcheck	*tmp;

	tmp = (*tampon);
	while (tmp->next)
		tmp = tmp->next;
	if (((*tampon)->i < (*tampon)->next->i && (*tampon)->i > tmp->i)
	|| ((*tampon)->i < (*tampon)->next->i && (*tampon)->next->i == tmp->i))
	{
		if (!ft_swap_stock(tampon, actions, 'b'))
			return (0);
	}
	else if ((*tampon)->i > (*tampon)->next->i && tmp->i > (*tampon)->i)
	{
		if (!(makerrb(tampon, actions)))
			return (0);
	}
	else if (!(sort_in_b(tampon, actions, tmp)))
		return (0);
	return (1);
}

int		sortnum(t_lcheck **stock, t_moves **actions, t_lcheck *tmp)
{
	if ((*stock)->i > (*stock)->next->i && (tmp->i > (*stock)->next->i
	&& tmp->i < (*stock)->i))
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
		if (!ft_swap_stock(stock, actions, 'a'))
			return (0);
		if (!(makera(stock, actions)))
			return (0);
	}
	return (1);
}

int		tri2_3nbs(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		char c)
{
	t_lcheck *tmp;

	tmp = (*stock);
	while (tmp->next)
		tmp = tmp->next;
	if ((*stock)->next && c == 'a')
	{
		if (((*stock)->i > (*stock)->next->i && tmp->i > (*stock)->i)
		|| ((*stock)->i > (*stock)->next->i && tmp->i == (*stock)->next->i))
			if (!ft_swap_stock(stock, actions, 'a'))
				return (0);
		if ((*stock)->i > (*stock)->next->i && tmp->i < (*stock)->next->i)
		{
			if (!ft_swap_stock(stock, actions, 'a'))
				return (0);
			if (!(makerra(stock, actions)))
				return (0);
		}
		else if (!(sortnum(stock, actions, tmp)))
			return (0);
	}
	else if ((*stock)->next && c == 'b')
		if (!(tri_in_b(tampon, actions)))
			return (0);
	return (1);
}
