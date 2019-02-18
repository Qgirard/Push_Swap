/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:02:27 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/18 19:47:49 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		makereverse(t_pile **pile, t_pile **temp, char *line)
{
	if (!(ft_strcmp(line, "rra")) || !(ft_strcmp(line, "rrr")))
		reverserotatea(pile);
	if (!(ft_strcmp(line, "rrb")) || !(ft_strcmp(line, "rrr")))
		reverserotateb(temp);
	return (1);
}

int		makerotate(t_pile **pile, t_pile **temp, char *line)
{
	if (!(ft_strcmp(line, "ra")) || !(ft_strcmp(line, "rr")))
		rotatea(pile);
	if (!(ft_strcmp(line, "rb")) || !(ft_strcmp(line, "rr")))
		rotateb(temp);
	else
		makereverse(pile, temp, line);
	return (1);
}

int		makepush(t_pile **pile, t_pile **temp, char *line)
{
	if (!(ft_strcmp(line, "pa")))
		pushinpilea(pile, temp);
	else if (!(ft_strcmp(line, "pb")))
		pushinpileb(pile, temp);
	else
		makerotate(pile, temp, line);
	return (1);
}

int		makemoves(t_pile **pile, t_pile **temp, char *line)
{
	if (!(ft_strcmp(line, "sa")) || !(ft_strcmp(line, "ss")))
	{
		if ((*pile)->next)
			ft_swap(&((*pile)->i), &((*pile)->next->i));
	}
	if (!(ft_strcmp(line, "sb")) || !(ft_strcmp(line, "ss")))
	{
		if ((*pile)->next)
			ft_swap(&((*temp)->i), &((*temp)->next->i));
	}
	else
	{
		if (!makepush(pile, temp, line))
			return (freepileb(temp));
	}
	return (1);
}

int		checker(t_pile **pile)
{
	t_pile *temp;
	char	*line;

	line = NULL;
	temp = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (!makemoves(pile, &temp, line))
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
	}
	if (temp)
		write(1, "[KO]\n", 5);
	return (1);
}
