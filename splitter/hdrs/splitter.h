/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: black <black@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:20:39 by blackrider        #+#    #+#             */
/*   Updated: 2024/10/03 16:45:15 by black            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_H
# define SPLITTER_H

# include "../../../libft/libft.h"
# include "../../strhandler/hdrs/strhandler.h"

typedef struct	s_crds
{
	int	i;
	int	size;
	int	strsize;
}				t_crds;

typedef struct	s_splts
{
	t_cchar	**qts;
	t_cchar	**splts;
}				t_splqt;

t_llist	*spliter(t_cchar *str, t_splqt *splt);
///////////////////////////////T_SPLQT///////////////////////////////
t_splqt	*crtsplqtt(char *qts, char *rdr, char *spln, char *splts);
void	*freesplqtt(t_splqt *splqt);

#endif