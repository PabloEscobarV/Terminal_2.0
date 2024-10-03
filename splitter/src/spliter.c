/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:40:07 by black             #+#    #+#             */
/*   Updated: 2024/10/03 19:48:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"

int	is_split(t_cchar* str, t_cchar *splt)
{
	while (*splt && ft_strlcmp(str, *splt))
		++splt;
	return (ft_strlen(*splt));
}

int	check_is_close_qt(t_cchar *str, t_cchar **qts)
{
	while (*str && !is_split(str, qts))
		++str;
}

t_llist	*set_node(t_cchar *str, t_splqt *splqt)
{
	t_cchar	*tmp;
	int		splt_size;

	tmp = str;
	while (*tmp)
	{
		splt_size = is_split(str, splqt->splts);
		if ()
	}
}