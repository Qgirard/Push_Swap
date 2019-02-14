/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freecauses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:42:39 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 19:01:43 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		freeanderror(t_pilea **pile)
{
	t_pilea *tmp;

	while ((*pile))
	{
		tmp = (*pile);
		(*pile)->i = 0;
		(*pile) = (*pile)->next;
		free(tmp);
	}
	write(2, "Error\n", 6);
	return (1);
}

int		freepilea(t_pilea **pile)
{
	t_pilea	*tmp;

	while ((*pile))
	{
		tmp = (*pile);
		(*pile)->i = 0;
		(*pile) = (*pile)->next;
		free(tmp);
	}
	return (1);
}
