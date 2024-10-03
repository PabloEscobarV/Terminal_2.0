/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_splqt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: black <black@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:02:06 by blackrider        #+#    #+#             */
/*   Updated: 2024/10/03 16:44:21 by black            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"
#include "../hdrs/splitter.h"
#include "../../hdrs/terminalmacros.h"

t_splqt	*crtsplqtt(char *qts, char *splts)
{
	t_splqt	*splqt;

	splqt = malloc(sizeof(t_splqt));
	if (!splqt)
		return (NULL);
	splqt->qts = (t_cchar **)ft_split(qts, SPLTCH);
	splqt->splts = (t_cchar **)ft_split(splts, SPLTCH);
	return (splqt);
}

void	*freesplqtt(t_splqt *splqt)
{
	ft_free_d((void **)(splqt->qts));
	ft_free_d((void **)splqt->splts);
	free(splqt);
	return (NULL);
}
