/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_good_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:04:35 by qgirard           #+#    #+#             */
/*   Updated: 2019/04/04 17:04:38 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		put_good_length_in_blue(char *str, int *i, int *j, int k)
{
	int		l;

	l = 0;
	while (l < k)
	{
		((unsigned int *)str)[*i] = 128;
		*i = *i + 1;
		l++;
	}
	while (*i % 495 != 0 && k != 495)
		*i = *i + 1;
	*j = *j + 1;
	return (1);
}

int		put_good_length(char *str, int *i, int *j, int k)
{
	int		l;

	l = 0;
	while (l < k)
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
