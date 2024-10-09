/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_crd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:30:36 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/10/10 01:17:04 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/terminalmacros.h"
#include "../hdrs/splitter.h"

int	cmpstrv(t_cchar *str, t_cchar **splt)
{
	int	i;

	i = 0;
	while (splt[i] && !ft_strlcmp(str, splt[i]))
		++i;
	if (!splt[i])
		return (0);
	return (i + 1);
}

int	check_is_close_qt(t_cchar *str, t_crds *crd, t_cchar **qts)
{
	int	i;

	str += crd->front;
	i = cmpstrv(str, qts);
	if (!i || (crd->front && *(str - 1) == BKSLASH))
		return (0);
	--i;
	qts += i;
	i = ft_strlen(*qts);
	while (str[i] && !(str[i - 1] != BKSLASH && ft_strlcmp(str + i, *qts)))
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
