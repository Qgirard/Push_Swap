/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:35:46 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/21 15:31:33 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printmoreactions(t_moves *tmp)
{
	if (tmp->sa)
		write(1, "sa\n", 3);
	else if (tmp->sb)
		write(1, "sb\n", 3);
	else if (tmp->pa)
		write(1, "pa\n", 3);
	else if (tmp->pb)
		write(1, "pb\n", 3);
	else if (tmp->ra)
		write(1, "ra\n", 3);
	else if (tmp->rb)
		write(1, "rb\n", 3);
	else if (tmp->rra)
		write(1, "rra\n", 4);
	else if (tmp->rrb)
		write(1, "rrb\n", 4);
}

void	printactions(t_moves **actions)
{
	t_moves *tmp;

	reduce_actions(actions);
	tmp = (*actions);
	while (tmp)
	{
		if (tmp->next && ((tmp->sa && tmp->next->sb)
		|| (tmp->sb && tmp->next->sa)))
			reduce_double_actions(&tmp, 1);
		else if (tmp->next && ((tmp->ra && tmp->next->rb)
		|| (tmp->rb && tmp->next->ra)))
			reduce_double_actions(&tmp, 2);
		else if (tmp->next && ((tmp->rra && tmp->next->rrb)
		|| (tmp->rrb && tmp->next->rra)))
			reduce_double_actions(&tmp, 3);
		printmoreactions(tmp);
		tmp = tmp->next;
	}
}
