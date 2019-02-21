/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:23:40 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/21 19:40:20 by qgirard          ###   ########.fr       */
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

int		push_rotate(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	int			k;
	int			i;
	t_lcheck	*tmp;

	tmp = (*stock);
	i = 0;
	k = mediane(stock);
	while (tmp && i < var)
	{
		if (tmp->i < k)
		{
			tmp = tmp->next;
			if (!(pushb(stock, tampon, actions)))
				return (0);
		}
		else if (tmp->i >= k)
		{
			tmp = tmp->next;
			if (!(makera(stock, actions)))
				return (0);
		}
		i++;
	}
	return (1);
}

int		push_swap(t_lcheck **stock, t_lcheck **tampon, t_moves **actions,
		int var)
{
	t_lcheck	*tmp;
	t_lcheck	*ptr;
	int			i;

	i = countlist(tampon);
	ft_putendl("YIPIKAI");
	ft_printf("%d\n", var);
	if (countlist(stock) <= 3)
	{
		if (!(trinbs(stock, actions)))
			return (0);
		return (1);
	}
	else
	{
		if (!(push_rotate(stock, tampon, actions, var)))
			return (0);
		push_swap(stock, tampon, actions, countlist(tampon) - i);
	}
	tmp = (*stock);
	ptr = (*tampon);
	ft_putendl("-----------------------");
	while (tmp || ptr)
	{
		if (tmp)
		{
			ft_printf("%d", tmp->i);
			tmp = tmp->next;
		}
		else
			ft_printf(" ");
		ft_printf(" | ");
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
