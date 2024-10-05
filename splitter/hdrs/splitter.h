/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:20:39 by blackrider        #+#    #+#             */
/*   Updated: 2024/10/05 16:37:22 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_H
# define SPLITTER_H

# include "../../libft/libft.h"
# include "../../strhandler/hdrs/strhandler.h"

typedef struct	s_crds
{
	int	i;
	int	size;
}				t_crds;

typedef struct	s_splts
{
	t_cchar	**qts;
	t_cchar	**splts;
}				t_splqt;

t_llist	*splitter(t_cchar *str, t_splqt *splt);
///////////////////////////////T_SPLQT///////////////////////////////
t_splqt	*crtsplqtt(char *qts, char *splts);
void	*freesplqtt(t_splqt *splqt);

t_crds	*crt_crds(int i, int size);
void	freecrds(void *crds);

#endif