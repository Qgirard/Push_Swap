/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:27:35 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 16:13:16 by qgirard          ###   ########.fr       */
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

int		freend(t_lcheck **stock, t_temp **tampon)
{
	t_lcheck	*tmp;
	t_temp		*ptr;

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
		(*tampon)->x = 0;
		(*tampon) = (*tampon)->next;
		free(ptr);
	}
	return (1);
}
