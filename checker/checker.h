/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:50:19 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 19:21:11 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libftprintf/ft_printf.h"

typedef struct	s_pilea
{
	int				i;
	struct s_pilea	*next;
}				t_pilea;

typedef struct	s_pileb
{
	int				x;
	struct s_pileb	*next;
	struct s_pileb	*prev;
}				t_pileb;

int				freeanderror(t_pilea **pile);
int				createpilea(t_pilea **pile, char *str);
int				freepilea(t_pilea **pile);
int				checker(t_pilea **pile);

#endif
