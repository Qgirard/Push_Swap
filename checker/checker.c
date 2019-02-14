/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:02:27 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 19:20:51 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		makemoves(t_pilea **pile, t_pileb **temp, char *line)
{
	if (!(ft_strcmp(line, "sa")))
	{
		ft_swap(&((*pile)->i), &((*pile)->next->i));
	}
	return (1);
}

int		checker(t_pilea **pile)
{
	t_pileb *temp;
	char	*line;

	line = NULL;
	temp = NULL;
	while (get_next_line(0, &line))
	{
		if (!makemoves(pile, &temp, line))
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
	}
	return (1);
}
