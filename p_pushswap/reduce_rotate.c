/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:36:02 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/13 16:24:19 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reduce_morerotateb(t_moves **tmp, t_moves **ptr)
{
	int		i;

	i = 0;
	*ptr = *tmp;
	while (*tmp && (*tmp)->rrb == 1)
	{
		i++;
		*tmp = (*tmp)->next;
	}
	while (*tmp && (*tmp)->rb == 1 && i > 0)
	{
		(*ptr)->rrb = 0;
		(*tmp)->rb = 0;
		*ptr = (*ptr)->next;
		*tmp = (*tmp)->next;
		i--;
	}
}

void	reduce_rotateb(t_moves **tmp, t_moves **ptr)
{
	int		i;

	i = 0;
	*ptr = *tmp;
	while (*tmp && (*tmp)->rb == 1)
	{
		i++;
		*tmp = (*tmp)->next;
	}
	while (*tmp && (*tmp)->rrb == 1 && i > 0)
	{
		(*ptr)->rb = 0;
		(*tmp)->rrb = 0;
		*ptr = (*ptr)->next;
		*tmp = (*tmp)->next;
		i--;
	}
}

void	reduce_morerotatea(t_moves **tmp, t_moves **ptr)
{
	int		i;

	i = 0;
	*ptr = *tmp;
	while (*tmp && (*tmp)->rra == 1)
	{
		i++;
		*tmp = (*tmp)->next;
	}
	while (*tmp && (*tmp)->ra == 1 && i > 0)
	{
		(*ptr)->rra = 0;
		(*tmp)->ra = 0;
		*ptr = (*ptr)->next;
		*tmp = (*tmp)->next;
		i--;
	}
}

void	reduce_rotatea(t_moves **tmp, t_moves **ptr)
{
	int		i;

	i = 0;
	*ptr = *tmp;
	while (*tmp && (*tmp)->ra == 1)
	{
		i++;
		*tmp = (*tmp)->next;
	}
	while (*tmp && (*tmp)->rra == 1 && i > 0)
	{
		(*ptr)->ra = 0;
		(*tmp)->rra = 0;
		*ptr = (*ptr)->next;
		*tmp = (*tmp)->next;
		i--;
	}
}
