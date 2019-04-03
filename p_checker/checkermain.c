/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkermain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:49:57 by qgirard           #+#    #+#             */
/*   Updated: 2019/04/03 19:06:31 by qgirard          ###   ########.fr       */
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

int		initialize_visu(int *i, t_mini *pts)
{
	pts->visual = 1;
	*i = *i + 1;
	pts->mlx_ptr = mlx_init();
	pts->win_ptr = mlx_new_window(pts->mlx_ptr, 1000, 1000, "visu");
	pts->img_ptr1 = mlx_new_image(pts->mlx_ptr, 10, 1000);
	pts->img_ptr2 = mlx_new_image(pts->mlx_ptr, 495, 1000);
	pts->img_ptr3 = mlx_new_image(pts->mlx_ptr, 495, 1000);
	pts->buff1 = mlx_get_data_addr(pts->img_ptr1, &(pts->bpp), &(pts->sl),
	&(pts->endian));
	pts->buff2 = mlx_get_data_addr(pts->img_ptr2, &(pts->bpp), &(pts->sl),
	&(pts->endian));
	pts->buff3 = mlx_get_data_addr(pts->img_ptr3, &(pts->bpp), &(pts->sl),
	&(pts->endian));
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	t_pile	*temp;
	t_pile	*pile;
	t_mini	pts;

	i = 1;
	pts.visual = 0;
	pile = NULL;
	temp = NULL;
	if (argc == 1)
		return (0);
	if (!ft_strcmp("-v", argv[1]))
		if (!initialize_visu(&i, &pts))
			return (freeanderror(&pile, 1));
	while (argv[i])
	{
		if (!(checknumbers(argv[i], &pile)))
			return (freeanderror(&pile, 1));
		i++;
	}
	put_the_max(&pile);
	if (!checker(&pile, &temp, &pts))
		return (freeanderror(&pile, 1));
	freeanderror(&pile, 0);
	return (0);
}
