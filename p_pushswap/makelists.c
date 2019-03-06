/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:10:35 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/06 18:01:44 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stockactions(t_moves **actions, int var)
{
	t_moves	*tmp;
	t_moves	*new;

	tmp = (*actions);
	if ((*actions) != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!(new = (t_moves *)malloc(sizeof(t_moves))))
		return (0);
	new->next = NULL;
	new->sa = (var == 1) ? 1 : 0;
	new->sb = (var == 2) ? 1 : 0;
	new->pa = (var == 3) ? 1 : 0;
	new->pb = (var == 4) ? 1 : 0;
	new->ra = (var == 5) ? 1 : 0;
	new->rb = (var == 6) ? 1 : 0;
	new->rra = (var == 7) ? 1 : 0;
	new->rrb = (var == 8) ? 1 : 0;
	if (!(*actions))
		(*actions) = new;
	else
		tmp->next = new;
	return (1);
}

int		putlists(t_lcheck **stock, char *str)
{
	t_lcheck	*tmp;
	t_lcheck	*new;

	tmp = *stock;
	if ((*stock) != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!(new = (t_lcheck *)malloc(sizeof(t_lcheck))))
		return (0);
	new->i = ft_atoi(str);
	new->next = NULL;
	if (!(*stock))
	{
		new->prev = NULL;
		*stock = new;
	}
	else
	{
		new->prev = tmp;
		tmp->next = new;
	}
	return (1);
}

int		countlist(t_lcheck **stock)
{
	int			i;
	t_lcheck	*tmp;

	i = (*stock) ? 1 : 0;
	tmp = (*stock);
	while (tmp && tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
