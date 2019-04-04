/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:42:27 by qgirard           #+#    #+#             */
/*   Updated: 2019/04/04 17:04:45 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		put_pile_in_window(t_pile **pile, char *str)
{
	t_pile	*tmp;
	int		i;
	int		j;
	int		col;
	double	k;

	i = 0;
	col = 0;
	tmp = *pile;
	while (tmp && i <= 495000)
	{
		k = 495 * ((1.0 * tmp->i) / ((*pile)->max) * 1.0);
		j = 0;
		while (j <= 50 && i <= 495000 && col == 0)
			put_good_length(str, &i, &j, k);
		while (j <= 50 && i <= 495000 && col == 1)
			put_good_length_in_blue(str, &i, &j, k);
		while (i % 495 != 0 && k != 495)
			i++;
		tmp = tmp->next;
		col = (col == 0) ? 1 : 0;
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
	if (!(pts->img_ptr1 = mlx_new_image(pts->mlx_ptr, 10, 1000)))
		return (free_mlx_ptrs(pts, 2));
	if (!(pts->img_ptr2 = mlx_new_image(pts->mlx_ptr, 495, 1000)))
		return (free_mlx_ptrs(pts, 3));
	if (!(pts->img_ptr3 = mlx_new_image(pts->mlx_ptr, 495, 1000)))
		return (free_mlx_ptrs(pts, 4));
	if (!(pts->buff1 = mlx_get_data_addr(pts->img_ptr1, &(pts->bpp), &(pts->sl),
	&(pts->endian))))
		return (free_mlx_ptrs(pts, 5));
	if (!(pts->buff2 = mlx_get_data_addr(pts->img_ptr2, &(pts->bpp), &(pts->sl),
	&(pts->endian))))
		return (free_mlx_ptrs(pts, 6));
	if (!(pts->buff3 = mlx_get_data_addr(pts->img_ptr3, &(pts->bpp), &(pts->sl),
	&(pts->endian))))
		return (free_mlx_ptrs(pts, 7));
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
