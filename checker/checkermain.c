/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkermain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:49:57 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/18 15:01:10 by qgirard          ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int		i;
	t_pile	*pile;

	i = 1;
	pile = NULL;
	if (argc == 1)
		return (0);
	while (argv[i])
	{
		if (!(checknumbers(argv[i], &pile)))
			return (freeanderror(&pile, 1));
		i++;
	}
	if (!checker(&pile))
		return (freeanderror(&pile, 1));
	while (pile)
	{
		ft_printf("%d\n", pile->i);
		pile = pile->next;
	}
	freeanderror(&pile, 0);
	return (0);
}
