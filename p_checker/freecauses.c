/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freecauses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:42:39 by qgirard           #+#    #+#             */
/*   Updated: 2019/04/03 18:12:48 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		freeanderror(t_pile **pile, int i)
{
	t_pile *tmp;

	while ((*pile))
	{
		tmp = (*pile);
		(*pile)->i = 0;
		(*pile) = (*pile)->next;
		free(tmp);
	}
	if (i == 1)
		write(2, "Error\n", 6);
	return (i);
}

int		freepileb(t_pile **temp)
{
	t_pile *tmp;

	while ((*temp))
	{
		tmp = (*temp);
		(*temp)->i = 0;
		(*temp) = (*temp)->next;
		free(tmp);
	}
	return (0);
}
