/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:23:40 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/09 13:53:41 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap_in_b(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	int			i;

	ft_printf("VAR = %d\n", var);
	i = countlist(stock);
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
	if (rev_push_rotate(stock, tampon, actions, var) == -1)
		return (0);
	i = countlist(stock) - i;
	push_swap_in_b(stock, tampon, actions, var - i);
	ft_printf("i = %d\n", i);
	push_swap(stock, tampon, actions, i);
	recup_in_a(stock, tampon, actions, i);
	return (1);
}

int		push_swap(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	int			i;
	t_lcheck	*tmp;
	t_lcheck	*ptr;

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
	push_swap(stock, tampon, actions, var - i);
	/*if (!(checksort(stock)))
		push_swap_in_b(stock, tampon, actions, var - i);*/
	push_swap_in_b(stock, tampon, actions, i);
	recup_in_b(stock, tampon, actions, i);
	tmp = *stock;
	ptr = *tampon;
	ft_putendl("--------------");
	while (tmp || ptr)
	{
		if (tmp)
		{
			ft_printf("%d", tmp->i);
			tmp = tmp->next;
		}
		else
			ft_printf(" ");
		ft_printf("     |     ");
		if (ptr)
		{
			ft_printf("%d\n", ptr->i);
			ptr = ptr->next;
		}
		else
			ft_printf("\n");
	}
	return (1);
}
