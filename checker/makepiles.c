/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makepiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:44:13 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 18:55:35 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		createpilea(t_pilea **pile, char *str)
{
	t_pilea	*tmp;
	t_pilea	*new;

	tmp = *pile;
	if ((*pile) != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!(new = (t_pilea *)malloc(sizeof(t_pilea))))
		return (0);
	new->i = ft_atoi(str);
	new->next = NULL;
	if (!(*pile))
		*pile = new;
	else
		tmp->next = new;
	return (1);
}
