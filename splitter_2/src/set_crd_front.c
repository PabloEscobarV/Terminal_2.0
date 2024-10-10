/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_crd_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:34:49 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/10/10 22:20:47 by Pablo Escob      ###   ########.fr       */
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

	if (splt->qts[cmpstrv(str + crd->front, splt->qts)])
		return (E_OK);
	i = crd->front;
	--i;
	while (i >= 0 && str[i] == SPCCH)
		--i;
	if (i >= 0)
		return (E_OK);
	crd->front += ft_strlen(
			splt->splts[cmpstrv(str + crd->front, splt->splts)]);
	front = crd->front;
	skip_spaces(str, crd);
	while (crd->front < crd->end && !ft_isspace(str[crd->front])
		&& !splt->splts[cmpstrv(str + crd->front, splt->splts)])
		++crd->front;
	return (front);
}
