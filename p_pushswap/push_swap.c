/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:23:40 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/06 18:09:33 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap_in_b(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	int		i;

	i = countlist(stock);
	if (var <= 3)
	{
		if (countlist(stock) <= 3)
		{
			if (!tri2_3nbs(stock, tampon, actions, 'b'))
				return (0);
		}
		else if (!(tri_pile_b(tampon, actions, var)))
			return (0);
		return (1);
	}
	if (rev_push_rotate(stock, tampon, actions, var) == -1)
		return (0);
	i = countlist(stock) - i;
	push_swap_in_b(stock, tampon, actions, i);
	if (!(checksort(tampon)))
		push_swap_in_b(stock, tampon, actions, i);
	push_swap(stock, tampon, actions, i);
	return (1);
}

int		push_swap(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	int			i;

	i = countlist(tampon);
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
	if (push_rotate(stock, tampon, actions, var) == -1)
		return (0);
	i = countlist(tampon) - i;
	ft_printf("I = %d\n", i);
	push_swap(stock, tampon, actions, i);
	if (!(checksort(stock)))
		push_swap(stock, tampon, actions, i);
	push_swap_in_b(stock, tampon, actions, i);
	//recup_in_b(stock, tampon, actions, var);
	return (1);
}
