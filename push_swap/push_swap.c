/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:23:40 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/15 18:24:28 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap(t_lcheck **stock, t_lcheck **tampon)
{
	t_lcheck	*tmp;

	if ((*stock)->next && (*stock)->i > (*stock)->next->i)
	{
		ft_swap(&((*stock)->i), &((*stock)->next->i));
		write(1, "sa\n", 3);
	}
	tmp = (*tampon);
	write(1, "pb\n", 3);
	write(1, "pb\n", 3);
	write(1, "pb\n", 3);
	write(1, "sa\n", 3);
	write(1, "pa\n", 3);
	write(1, "pa\n", 3);
	write(1, "pa\n", 3);
	return (1);
}