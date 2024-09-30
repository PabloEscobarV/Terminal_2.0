/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subvar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:19:35 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/30 21:54:50 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../hdrs/strhandlerserv.h"
#include "../../libft/libft.h"
#include "../../HashTable/hdrs/hashtable.h"

char	*subvar(t_arg *strt, t_hashtable *hst)
{
	int	size;

	if (checkvarfront(strt->arg[strt->x]))
		return (NULL);
	size = strt->x;
	while (strt->arg[size] && !checkvarend(strt->arg[size]))
		++size;
	size -= strt->x;
	if (!size)
		return (NULL);
	return ((char *)getvar(strt, size, hst));
}
