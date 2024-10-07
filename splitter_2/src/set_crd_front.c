/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_crd_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:34:49 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/10/07 21:35:43 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/terminalmacros.h"
#include "../hdrs/splitter_srv.h"

static void	skip_spaces(t_cchar *str, t_crds *crd)
{
	while (crd->front < crd->end && ft_isspace(str[crd->front]))
		++crd->front;
}

int	set_crd_front(t_cchar *str, t_crds *crd, t_splqt *splt)
{
	int	i;
	int	front;

	if (cmpstrv(str + crd->front, splt->qts))
		return (E_OK);
	i = crd->front;
	if (i)
		--i;
	while (i && str[i] == SPCCH)
		--i;
	if (i)
		return (E_OK);
	++crd->front;
	front = crd->front;
	skip_spaces(str, crd);
	while (crd->front < crd->end)
	{
		if (ft_isspace(str[crd->front])
			|| cmpstrv(str + crd->front, splt->splts))
			break ;
		++crd->front;
	}
	return (front);
}
