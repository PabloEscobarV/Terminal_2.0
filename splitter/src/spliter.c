/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:40:07 by black             #+#    #+#             */
/*   Updated: 2024/10/04 20:11:19 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/terminalmacros.h"
#include "../hdrs/servicespltr.h"

int	cmpstrv(t_cchar* str, t_cchar **splt)
{
	while (*splt && ft_strlcmp(str, *splt))
		++splt;
	return (ft_strlen(*splt));
}

int	check_is_close_qt(t_cchar *str, t_crds *crd, t_cchar **qts)
{
	int	i;

	i = 0;
	str += crd->i;
	if (!cmpstrv(str, qts) || (crd->i && *(str - 1) == SLASH))
		return (i);
	while (str[++i] && !(str[i - 1] != SLASH && cmpstrv(str, qts)));
	if (!(*str))
		return (E_ERR);
	return (i + 1);
}

int	set_crd(t_cchar *str, t_crds *crd, t_splqt *splqt)
{
	int	i;

	while (crd->i < crd->size)
	{
		i = check_is_close_qt(str, crd, splqt->splts);
		if (i < 0)
			return (E_ERR);
		crd->i += i;
		if (cmpstrv(str + crd->i, splqt->qts))
			break ;
		++crd->i;
	}
	return (E_OK);
}

t_llist	*set_node(t_cchar *str, t_crds *crd, t_splqt *splqt)
{
	int		i;
	t_llist	*node;

	i = crd->i;
	if (set_crd(str, crd, splqt))
		return (NULL);
	node = llistnewnode(crt_crds(i, crd->i));
	++crd->i;
	return (node);
}