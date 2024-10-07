/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_crd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:30:36 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/10/07 21:39:07 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/terminalmacros.h"
#include "../hdrs/splitter.h"

int	cmpstrv(t_cchar *str, t_cchar **splt)
{
	while (*splt && !ft_strlcmp(str, *splt))
		++splt;
	return (ft_strlen(*splt));
}

int	check_is_close_qt(t_cchar *str, t_crds *crd, t_cchar **qts)
{
	int	i;

	i = 0;
	str += crd->front;
	if (!cmpstrv(str, qts) || (crd->front && *(str - 1) == BKSLASH))
		return (i);
	++i;
	while (str[i] && !(str[i - 1] != BKSLASH && cmpstrv(str + i, qts)))
		++i;
	return (i);
}

int	set_crd(t_cchar *str, t_crds *crd, t_splqt *splqt)
{
	int	i;

	while (crd->front < crd->end)
	{
		i = check_is_close_qt(str, crd, splqt->qts);
		if (i)
			return (i);
		if (cmpstrv(str + crd->front, splqt->splts))
			break ;
		++crd->front;
	}
	return (E_OK);
}
