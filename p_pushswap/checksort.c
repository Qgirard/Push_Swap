/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:15:04 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/05 14:28:53 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checksort(t_lcheck **stock)
{
	t_lcheck *tmp;

	tmp = (*stock);
	while (tmp && tmp->next)
	{
		if (tmp->i < tmp->next->i)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
