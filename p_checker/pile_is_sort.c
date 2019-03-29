/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_is_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:31:53 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/29 13:38:04 by qgirard          ###   ########.fr       */
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

int		check_if_sort_is_ok(t_pile **pile, t_pile **temp)
{
	if (*temp || !pile_is_sort(pile))
		write(1, "[KO]\n", 5);
	else if (!(*temp) && pile_is_sort(pile))
		write(1, "[OK]\n", 5);
	return (1);
}
