/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:20:39 by blackrider        #+#    #+#             */
/*   Updated: 2024/10/10 23:34:16 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_H
# define SPLITTER_H

# include "../../libft/libft.h"
# include "../../strhandler/hdrs/strhandler.h"

typedef struct s_crds
{
	int	front;
	int	end;
}		t_crds;

typedef struct s_str_crd
{
	char	*splt;
	char	*str;
}			t_str_crd;

typedef struct s_splts
{
	t_cchar	**qts;
	t_cchar	**splts;
}			t_splqt;

t_llist		*splitter(t_cchar *str, t_splqt *splt);
///////////////////////////////T_SPLQT///////////////////////////////
t_splqt		*crtsplqtt(char *qts, char *splts);
void		*freesplqtt(t_splqt *splqt);
///////////////////////////////T_CRDS///////////////////////////////
t_crds		*crt_crds(int i, int size);
void		freecrds(void *crds);
///////////////////////////////T_STR_CRD///////////////////////////////
t_str_crd	*crt_str_crd_t(t_cchar *str, int size);
void		free_t_str_crd_t(void *strcrd);
#endif