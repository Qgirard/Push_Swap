/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:50:19 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/15 18:22:31 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libftprintf/ft_printf.h"

typedef struct	s_pile
{
	int				i;
	struct s_pile	*next;
	struct s_pile	*prev;
}				t_pile;

int				freeanderror(t_pile **pile, int i);
int				createpilea(t_pile **pile, char *str);
int				checker(t_pile **pile);
int				freepileb(t_pile **temp);
void			pushinpilea(t_pile **pile, t_pile **temp);
void			pushinpileb(t_pile **pile, t_pile **temp);
void			rotatea(t_pile **pile);
void			rotateb(t_pile **temp);
void			reverserotatea(t_pile **pile);
void			reverserotateb(t_pile **temp);

#endif
