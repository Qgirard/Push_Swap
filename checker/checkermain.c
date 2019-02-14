/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkermain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:49:57 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 19:16:54 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		checknumbers(char *str, t_pilea **pile)
{
	t_pilea	*tmp;

	if ((*pile))
	{
		tmp = (*pile);
		while (tmp)
		{
			if (ft_atoi(str) == tmp->i)
				return (0);
			tmp = tmp->next;
		}
	}
	if (ft_strisnumber(str))
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
	t_pilea	*pile;

	i = 1;
	pile = NULL;
	if (argc == 1)
		return (0);
	while (argv[i])
	{
		if (!(checknumbers(argv[i], &pile)))
			return (freeanderror(&pile));
		i++;
	}
	if (!checker(&pile))
		return (freeanderror(&pile));
	freepilea(&pile);
	return (0);
}
