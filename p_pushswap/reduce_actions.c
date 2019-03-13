/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:51:53 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/13 14:55:20 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reduce_swaps(t_moves **tmp)
{
	while (*tmp && ((*tmp)->sa == 1 || (*tmp)->sb == 1))
	{
		if ((*tmp)->sa == 1 && (*tmp)->next->sa == 1)
		{
			(*tmp)->sa = 0;
			(*tmp)->next->sa = 0;
			*tmp = (*tmp)->next->next;
		}
		else if ((*tmp)->sb == 1 && (*tmp)->next->sb == 1)
		{
			(*tmp)->sb = 0;
			(*tmp)->next->sb = 0;
			*tmp = (*tmp)->next->next;
		}
		else
			*tmp = (*tmp)->next;
	}
}

void	reduce_morepushes(t_moves **tmp, t_moves **ptr)
{
	int		i;

	i = 0;
	*ptr = *tmp;
	while (*tmp && (*tmp)->pa == 1)
	{
		i++;
		*tmp = (*tmp)->next;
	}
	while (*tmp && (*tmp)->pb == 1 && i > 0)
	{
		(*ptr)->pa = 0;
		(*tmp)->pb = 0;
		*ptr = (*ptr)->next;
		*tmp = (*tmp)->next;
		i--;
	}
}

void	reduce_pushes(t_moves **tmp, t_moves **ptr)
{
	int		i;

	i = 0;
	*ptr = *tmp;
	while (*tmp && (*tmp)->pb == 1)
	{
		i++;
		*tmp = (*tmp)->next;
	}
	while (*tmp && (*tmp)->pa == 1 && i > 0)
	{
		(*ptr)->pb = 0;
		(*tmp)->pa = 0;
		*ptr = (*ptr)->next;
		*tmp = (*tmp)->next;
		i--;
	}
}

int		reduce_actions(t_moves **actions)
{
	t_moves	*tmp;
	t_moves	*ptr;
	int		i;

	i = 0;
	tmp = (*actions);
	ptr = (*actions);
	while (tmp)
	{
		if (tmp && tmp->pb == 1)
			reduce_pushes(&tmp, &ptr);
		else if (tmp && tmp->pa == 1)
			reduce_morepushes(&tmp, &ptr);
		else if (tmp && (tmp->sa == 1 || tmp->sb == 1))
			reduce_swaps(&tmp);
		else if (tmp && tmp->ra == 1)
			reduce_rotatea(&tmp, &ptr);
		else if (tmp && tmp->rra == 1)
			reduce_morerotatea(&tmp, &ptr);
		else if (tmp && tmp->rb == 1)
			reduce_rotateb(&tmp, &ptr);
		else if (tmp && tmp->rrb == 1)
			reduce_morerotateb(&tmp, &ptr);
	}
	return (1);
}
