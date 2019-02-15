/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:44:13 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/15 18:48:32 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisint(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	if ((ft_strlen(str) >= 10 && str[0] != '-') || (ft_strlen(str) >= 11
	&& str[0] == '-'))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
