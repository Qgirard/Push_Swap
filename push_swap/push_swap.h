/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:22:16 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/15 15:57:49 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libftprintf/ft_printf.h"

typedef struct	s_lcheck
{
	int				i;
	struct s_lcheck	*next;
	struct s_lcheck *prev;
}				t_lcheck;

int				putlists(t_lcheck **stock, char *str);
int				freewhenerror(t_lcheck **stock);
int				push_swap(t_lcheck **stock, t_lcheck **tampon);
int				freend(t_lcheck **stock, t_lcheck **tampon);

#endif