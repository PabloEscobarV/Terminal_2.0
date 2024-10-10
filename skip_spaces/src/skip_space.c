/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:24:06 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/10/10 23:34:15 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../splitter_2/hdrs/splitter.h"
#include "../../hdrs/terminalmacros.h"

static int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		++i;
	if (!str[i])
		return (E_KO);
	while (str[i])
	{
		*str = str[i];
		++str;
	}
	str += i - 1;
	while (ft_isspace(*str))
	{
		*str = '\0';
		--str;
	}
	return (E_OK);
}

static char	*cmp_strv(t_cchar *str, t_cchar **splt)
{
	while (*splt && !ft_strlcmp(str, *splt))
		++splt;
	return (*splt);
}

int	check_is_qts(t_cchar *str, int crd, t_cchar **qts)
{
	int	i;

	i = 0;
	while (i < crd && !cmp_strv(str + i, qts))
		++i;
	if (i < crd)
		return (E_TRUE);
	return (E_FALSE);
}

int	check_qts_front(t_llist *llst, t_cchar **qts)
{
	int	i;

	if (!((t_str_crd *)(llst->data))->front)
		return (E_FALSE);
	return (check_is_qts(((t_str_crd *)(llst->data))->str,
		((t_str_crd *)(llst->data))->front, qts));
}

int	check_qts(t_cchar *str, t_llist *llst, t_cchar **qts)
{
	int	i;

	if ((!llst->previous || !llst->previous->next))
		return (check_qts_front(llst, qts));
	return (check_is_qts(((t_str_crd *)(llst->data))->str,
		((t_str_crd *)(llst->data))->front, qts));
}

t_llist	*skip_space(t_llist *llst, t_cchar **qts)
{
	if (!llst)
		return (NULL);
	
}