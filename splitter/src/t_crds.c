/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_crds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:14:27 by blackrider        #+#    #+#             */
/*   Updated: 2024/10/05 16:36:09 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"
#include "../hdrs/splitter.h"

t_crds	*crt_crds(int i, int size)
{
	t_crds	*crds;

	crds = malloc(sizeof(t_crds));
	if (!crds)
		return (NULL);
	crds->i = i;
	crds->size = size;
	return (crds);
}

void	freecrds(void *crds)
{
	free(crds);
	crds = NULL;
}
