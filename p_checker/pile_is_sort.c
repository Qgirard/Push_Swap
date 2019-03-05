/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_is_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:31:53 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/05 15:33:54 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		pile_is_sort(t_pile **pile)
{
	t_pile	*tmp;

	tmp = (*pile);
	while (tmp && tmp->next)
	{
		if (tmp->i < tmp->next->i)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
