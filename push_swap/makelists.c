/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:10:35 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/15 15:57:44 by qgirard          ###   ########.fr       */
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
	{
		new->prev = NULL;
		*stock = new;
	}
	else
	{
		new->prev = tmp;
		tmp->next = new;
	}
	return (1);
}
