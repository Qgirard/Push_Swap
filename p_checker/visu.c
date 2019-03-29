/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:42:27 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/29 19:22:22 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		redrawn(void *param)
{
	mlx_clear_window(PTS->mlx_ptr, PTS->win_ptr);
	return (1);
}

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
	tmp = (*pile);
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

int		visu(t_pile **pile, t_pile **temp, t_mini **pts)
{
	char	*str;
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;

	img_ptr = mlx_new_image((*pts)->mlx_ptr, 10, 1000);
	str = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	separate_visu(str);
	mlx_put_image_to_window((*pts)->mlx_ptr, (*pts)->win_ptr, img_ptr, 495, 0);
	img_ptr = mlx_new_image((*pts)->mlx_ptr, 495, 1000);
	str = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	put_pile_in_window(pile, str);
	mlx_put_image_to_window((*pts)->mlx_ptr, (*pts)->win_ptr, img_ptr, 0, 0);
	img_ptr = mlx_new_image((*pts)->mlx_ptr, 495, 1000);
	str = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	put_pile_in_window(temp, str);
	mlx_put_image_to_window((*pts)->mlx_ptr, (*pts)->win_ptr, img_ptr, 505, 0);
	usleep(200000);
	mlx_loop_hook((*pts)->mlx_ptr, redrawn, pts);
	return (1);
}
