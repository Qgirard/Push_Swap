/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:23:40 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 16:32:59 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap(t_lcheck **stock, t_temp **tampon)
{
	t_lcheck	*tmp;

	if ((*stock)->next && (*stock)->i > (*stock)->next->i)
	{
		ft_swap(&((*stock)->i), &((*stock)->next->i));
		write(1, "sa\n", 3);
	}
	while ((*stock)->next && (*stock)->i < (*stock)->next->i)
	{
		tmp = (*stock);
		scdelist(tampon, stock);
		(*stock) = (*stock)->next;
		free(tmp);
		write(1, "pb\n", 3);
	}
	return (1);
}
