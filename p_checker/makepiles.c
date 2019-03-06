/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makepiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:44:13 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/06 14:05:38 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pushinpileb(t_pile **pile, t_pile **temp)
{
	t_pile *tmp;

	tmp = (*pile);
	if ((*pile))
	{
		if ((*pile)->next)
			(*pile) = (*pile)->next;
		else
			(*pile) = NULL;
		tmp->prev = NULL;
		if ((*temp))
		{
			tmp->next = (*temp);
			(*temp)->prev = tmp;
			(*temp) = (*temp)->prev;
		}
		else
		{
			tmp->next = NULL;
			(*temp) = tmp;
		}
	}
}

void	pushinpilea(t_pile **pile, t_pile **temp)
{
	t_pile	*tmp;

	tmp = (*temp);
	if (*temp)
	{
		if ((*temp)->next)
			(*temp) = (*temp)->next;
		else
			(*temp) = NULL;
		tmp->prev = NULL;
		if ((*pile))
		{
			tmp->next = (*pile);
			(*pile)->prev = tmp;
			(*pile) = (*pile)->prev;
		}
		else
		{
			tmp->next = NULL;
			(*pile) = tmp;
		}
	}
}

int		createpilea(t_pile **pile, char *str)
{
	t_pile	*tmp;
	t_pile	*new;

	tmp = *pile;
	if ((*pile) != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!(new = (t_pile *)malloc(sizeof(t_pile))))
		return (0);
	new->i = ft_atoi(str);
	new->next = NULL;
	if (!(*pile))
	{
		new->prev = NULL;
		*pile = new;
	}
	else
	{
		new->prev = tmp;
		tmp->next = new;
	}
	return (1);
}
