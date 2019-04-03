/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:42:27 by qgirard           #+#    #+#             */
/*   Updated: 2019/04/03 19:17:36 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		put_good_length(char *str, int *i, int *j, int k)
{
	int		l;

	l = 0;
	while (l <= k)
	{
		((unsigned int *)str)[*i] = 32896;
		*i = *i + 1;
		l++;
	}
	while (*i % 495 != 0 && k != 495)
		*i = *i + 1;
	*j = *j + 1;
	return (1);
}

int		put_pile_in_window(t_pile **pile, char *str)
{
	t_pile	*tmp;
	int		i;
	int		j;
	double	k;

	i = 0;
	tmp = *pile;
	while (tmp && i <= 495000)
	{
		k = 495 * ((1.0 * tmp->i) / ((*pile)->max) * 1.0);
		j = 0;
		while (j <= 50 && i <= 495000)
			put_good_length(str, &i, &j, k);
		while (i % 495 != 0 && k != 495)
			i++;
		tmp = tmp->next;
	}
	return (1);
}

int		separate_visu(char *str)
{
	int		i;

	i = 0;
	while (i <= 10000)
	{
		((unsigned int *)str)[i] = 16777215;
		i++;
	}
	return (1);
}

int		key_hook(int key, t_mini *pts)
{
	mlx_clear_window(pts->mlx_ptr, pts->win_ptr);
	if (key == 36)
		checker(pts->pilea, pts->pileb, pts);
	return (1);
}

int		visu(t_mini *pts)
{
	separate_visu(pts->buff1);
	mlx_put_image_to_window(pts->mlx_ptr, pts->win_ptr, pts->img_ptr1, 495, 0);
	put_pile_in_window(pts->pilea, pts->buff2);
	mlx_put_image_to_window(pts->mlx_ptr, pts->win_ptr, pts->img_ptr2, 0, 0);
	put_pile_in_window(pts->pileb, pts->buff3);
	mlx_put_image_to_window(pts->mlx_ptr, pts->win_ptr, pts->img_ptr3, 505, 0);
	return (1);
}
