/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:23:40 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/15 17:16:53 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap_in_b(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	int			i;

	if (var <= 3)
	{
		if (countlist(tampon) <= 3)
		{
			if (!tri2_3nbs(stock, tampon, actions, 'b'))
				return (0);
		}
		else if (!(tri_pile_b(tampon, actions, var)))
			return (0);
		return (1);
	}
	i = rev_push_rotate(stock, tampon, actions, var);
	if (i == -1)
		return (0);
	if (!push_swap_in_b(stock, tampon, actions, var - i))
		return (0);
	if (!push_swap(stock, tampon, actions, i))
		return (0);
	recup_in_a(stock, tampon, actions, i);
	return (1);
}

int		push_swap(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	int			i;

	if (var <= 3)
	{
		if (countlist(stock) <= 3)
		{
			if (!tri2_3nbs(stock, tampon, actions, 'a'))
				return (0);
		}
		else if (!(tri_when_pile_a(stock, actions, var)))
			return (0);
		return (1);
	}
	i = push_rotate(stock, tampon, actions, var);
	if (i == -1)
		return (0);
	if (!push_swap(stock, tampon, actions, var - i))
		return (0);
	if (!push_swap_in_b(stock, tampon, actions, i))
		return (0);
	recup_in_b(stock, tampon, actions, i);
	return (1);
}
