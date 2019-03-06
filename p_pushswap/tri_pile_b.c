/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_pile_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:55:17 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/06 17:31:02 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_bnums(t_lcheck **tampon, t_moves **actions)
{
	if ((*tampon)->i < (*tampon)->next->i
	&& (*tampon)->next->next->i > (*tampon)->next->i)
		if (!ft_swap_stock(tampon, actions, 'b'))
			return (0);
	if ((*tampon)->i > (*tampon)->next->i
	&& (*tampon)->next->next->i > (*tampon)->i)
	{
		if (!(makerb(tampon, actions)))
			return (0);
		if (!ft_swap_stock(tampon, actions, 'b'))
			return (0);
		if (!(makerrb(tampon, actions)))
			return (0);
		if (!ft_swap_stock(tampon, actions, 'b'))
			return (0);
	}
	return (1);
}

int		tri_pile_bbis(t_lcheck **tampon, t_moves **actions)
{
	if ((*tampon)->i < (*tampon)->next->i
	&& (*tampon)->next->next->i > (*tampon)->i
	&& (*tampon)->next->next->i < (*tampon)->next->i)
	{
		if (!ft_swap_stock(tampon, actions, 'b'))
			return (0);
		if (!(makerb(tampon, actions)))
			return (0);
		if (!ft_swap_stock(tampon, actions, 'b'))
			return (0);
		if (!(makerrb(tampon, actions)))
			return (0);
	}
	else if (!(sort_bnums(tampon, actions)))
		return (0);
	return (1);
}

int		tri_pile_b(t_lcheck **tampon, t_moves **actions, int var)
{
	if ((*tampon)->next && var == 2 && (*tampon)->i < (*tampon)->next->i)
		if (!ft_swap_stock(tampon, actions, 'b'))
			return (0);
	if ((*tampon)->next && var == 3)
	{
		if ((*tampon)->i < (*tampon)->next->i
		&& (*tampon)->next->next->i < (*tampon)->i)
			if (!ft_swap_stock(tampon, actions, 'b'))
				return (0);
		if ((*tampon)->i > (*tampon)->next->i
		&& (*tampon)->next->next->i < (*tampon)->i
		&& (*tampon)->next->next->i > (*tampon)->next->i)
		{
			if (!(makerb(tampon, actions)))
				return (0);
			if (!ft_swap_stock(tampon, actions, 'b'))
				return (0);
			if (!(makerrb(tampon, actions)))
				return (0);
		}
		else if (!(tri_pile_bbis(tampon, actions)))
			return (0);
	}
	return (1);
}
