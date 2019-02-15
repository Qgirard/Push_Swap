/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:08:06 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 16:38:58 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		*stock = new;
	else
		tmp->next = new;
	return (1);
}

int		scdelist(t_temp **tampon, t_lcheck **stock)
{
	t_temp	*tmp;
	t_temp	*new;

	tmp = *tampon;
	if (!(new = (t_temp *)malloc(sizeof(t_temp))))
		return (0);
	new->x = (*stock)->i;
	new->next = ((*tampon) != NULL) ? (*tampon) : NULL;
	new->prev = NULL;
	if (!(*tampon))
		*tampon = new;
	else
	{
		(*tampon)->prev = new;
		(*tampon) = (*tampon)->prev;
	}
	return (1);
}