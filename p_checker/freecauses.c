/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freecauses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:42:39 by qgirard           #+#    #+#             */
/*   Updated: 2019/04/04 18:20:02 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		free_mlx_ptrs(t_mini *pts, int i)
{
	if (i >= 1)
		free(pts->mlx_ptr);
	if (i >= 2)
		free(pts->win_ptr);
	if (i >= 3)
		free(pts->img_ptr1);
	if (i >= 4)
		free(pts->img_ptr2);
	if (i >= 5)
		free(pts->img_ptr3);
	if (i >= 6)
		free(pts->buff1);
	if (i >= 7)
		free(pts->buff2);
	if (i >= 8)
		free(pts->buff3);
	return (0);
}

int		freeanderror(t_pile **pile, t_mini *pts, int i)
{
	t_pile *tmp;

	if (pts->visual == 1)
		free_mlx_ptrs(pts, 8);
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
