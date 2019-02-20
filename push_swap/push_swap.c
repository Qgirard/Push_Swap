/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:23:40 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/20 14:45:42 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	threenbs(t_lcheck **stock)
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
			makerra(stock);
		}
		else if ((*stock)->i > (*stock)->next->i && tmp->i > (*stock)->next->i)
			makera(stock);
		else if ((*stock)->i < (*stock)->next->i && tmp->i < (*stock)->i)
			makerra(stock);
		else if ((*stock)->i < (*stock)->next->i && (tmp->i < (*stock)->next->i
		&& tmp->i > (*stock)->i))
		{
			ft_swap(&(((*stock)->i)), &((*stock)->next->i));
			makera(stock);
		}
	}
}

int		push_swap(t_lcheck **stock, t_lcheck **tampon)
{
	t_lcheck	*tmp;
	t_lcheck	*ptr;

	tmp = (*stock);
	ptr = (*stock);
	mediane(stock);
	while (tmp->next)
		tmp = tmp->next;
	while (ptr && ptr->i != tmp->i)
	{
		if (ptr->i < tmp->i)
		{
			ptr = ptr->next;
			pushb(stock, tampon);
		}
		else if (ptr->i > tmp->i)
		{
			ptr = ptr->next;
			makera(stock);
		}
	}
	if (countlist(stock) > 3)
		push_swap(stock, tampon);
	if (countlist(stock) <= 3)
	{
		threenbs(stock);
		return (1);
	}
	return (1);
}
