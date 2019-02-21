/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:45:50 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/21 17:31:44 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		freewhenerror(t_lcheck **stock, t_lcheck **tampon, t_moves **actions)
{
	t_lcheck	*tmp;
	t_moves		*sac;

	while ((*stock))
	{
		tmp = (*stock);
		(*stock)->i = 0;
		(*stock) = (*stock)->next;
		free(tmp);
	}
	while ((*tampon))
	{
		tmp = (*tampon);
		(*tampon)->i = 0;
		(*tampon) = (*tampon)->next;
		free(tmp);
	}
	while ((*actions))
	{
		sac = (*actions);
		(*actions) = (*actions)->next;
		free(sac);
	}
	write(2, "Error\n", 6);
	return (1);
}

int		freend(t_lcheck **stock, t_lcheck **tampon, t_moves **actions)
{
	t_lcheck	*tmp;
	t_moves		*sac;

	while ((*stock))
	{
		tmp = (*stock);
		(*stock)->i = 0;
		(*stock) = (*stock)->next;
		free(tmp);
	}
	while ((*tampon))
	{
		tmp = (*tampon);
		(*tampon)->i = 0;
		(*tampon) = (*tampon)->next;
		free(tmp);
	}
	while ((*actions))
	{
		sac = (*actions);
		(*actions) = (*actions)->next;
		free(sac);
	}
	return (1);
}
