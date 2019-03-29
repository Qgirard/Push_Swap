/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkermain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:49:57 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/29 19:04:04 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		checknumbers(char *str, t_pile **pile)
{
	t_pile	*tmp;

	if ((*pile))
	{
		tmp = (*pile);
		while (tmp)
		{
			if (ft_atol(str) == tmp->i)
				return (0);
			if (!tmp->prev && tmp)
				(*pile)->max = tmp->i;
			if (tmp->prev && (*pile)->max < tmp->i)
				(*pile)->max = tmp->i;
			tmp = tmp->next;
		}
	}
	if (ft_strisint(str) && (ft_atol(str) >= -2147483648
	|| ft_atol(str) <= 2147483647))
	{
		if (!createpilea(pile, str))
			return (0);
	}
	else
		return (0);
	return (1);
}

int		initialize_visu(int *visual, int *i, t_mini **pts)
{
	if (!(*pts = (t_mini *)malloc(sizeof(t_mini))))
		return (0);
	*visual = 1;
	*i = *i + 1;
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		visual;
	t_pile	*pile;
	t_mini	*pts;

	i = 1;
	visual = 0;
	pts = NULL;
	pile = NULL;
	if (argc == 1)
		return (0);
	if (!ft_strcmp("-v", argv[1]))
		if (!initialize_visu(&visual, &i, &pts))
			return (freeanderror(&pile, &pts, 1));
	while (argv[i])
	{
		if (!(checknumbers(argv[i], &pile)))
			return (freeanderror(&pile, &pts, 1));
		i++;
	}
	put_the_max(&pile);
	if (!checker(&pile, &pts, visual))
		return (freeanderror(&pile, &pts, 1));
	freeanderror(&pile, &pts, 0);
	return (0);
}
