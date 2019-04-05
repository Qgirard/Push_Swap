/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:42:54 by qgirard           #+#    #+#             */
/*   Updated: 2019/04/05 15:30:37 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		findmed(int **tab, int pivot)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (j < pivot)
	{
		if ((*tab)[j] < (*tab)[pivot])
		{
			i++;
			ft_swap(&((*tab)[i]), &((*tab)[j]));
		}
		j++;
	}
	if ((*tab)[i + 1] > (*tab)[pivot])
		ft_swap(&((*tab)[i + 1]), &((*tab)[pivot]));
	if (i >= 0)
		findmed(tab, i);
	if (i + 2 < pivot)
		findmed(tab, pivot);
	return (pivot / 2);
}

int		mediane(t_lcheck **stock, int var)
{
	int			*tab;
	int			k;
	t_lcheck	*tmp;

	tab = NULL;
	k = 0;
	tmp = (*stock);
	if (!(tab = (int *)malloc(sizeof(int) * var)))
		return (0);
	while (tmp && k < var)
	{
		tab[k] = tmp->i;
		k++;
		tmp = tmp->next;
	}
	k = tab[findmed(&tab, var - 1)];
	free(tab);
	return (k);
}
