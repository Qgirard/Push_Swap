/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:45:50 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/15 15:54:58 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		freewhenerror(t_lcheck **stock)
{
	t_lcheck	*tmp;

	while ((*stock))
	{
		tmp = (*stock);
		(*stock)->i = 0;
		(*stock) = (*stock)->next;
		free(tmp);
	}
	write(2, "Error\n", 6);
	return (1);
}

int		freend(t_lcheck **stock, t_lcheck **tampon)
{
	t_lcheck	*tmp;
	t_lcheck		*ptr;

	while ((*stock))
	{
		tmp = (*stock);
		(*stock)->i = 0;
		(*stock) = (*stock)->next;
		free(tmp);
	}
	while ((*tampon))
	{
		ptr = (*tampon);
		(*tampon)->i = 0;
		(*tampon) = (*tampon)->next;
		free(ptr);
	}
	return (1);
}
