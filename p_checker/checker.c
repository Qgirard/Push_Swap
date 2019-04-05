/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:02:27 by qgirard           #+#    #+#             */
/*   Updated: 2019/04/05 13:50:16 by qgirard          ###   ########.fr       */
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
	if (ft_strcmp(line, "sa") && ft_strcmp(line, "ss") && ft_strcmp(line, "sb")
	&& ft_strcmp(line, "pa") && ft_strcmp(line, "pb") && ft_strcmp(line, "ra")
	&& ft_strcmp(line, "rr") && ft_strcmp(line, "rb") && ft_strcmp(line, "rra")
	&& ft_strcmp(line, "rrr") && ft_strcmp(line, "rrb"))
		return (0);
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

int		checker(t_pile **pile, t_pile **temp, t_mini *pts)
{
	char	*line;

	line = NULL;
	pts->pilea = pile;
	pts->pileb = temp;
	while (get_next_line(0, &line) == 1)
	{
		if (pts->visual == 1)
			visu(pts);
		if (!makemoves(pile, temp, line))
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
		if (pts->visual == 1)
		{
			mlx_hook(pts->win_ptr, 2, 1L << 0, key_hook, pts);
			mlx_loop(pts->mlx_ptr);
		}
	}
	check_if_sort_is_ok(pile, temp);
	(pts->visual == 1) ? visu(pts) : 0;
	return (1);
}
