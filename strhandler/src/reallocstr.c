/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:25:22 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/30 21:52:21 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../../E_Codes/e_codes.h"

char	*reallocstr(char *args, int size)
{
	char	*tmp;

	tmp = malloc(size * sizeof(char));
	if (!tmp)
	{
		ft_perror(STR_MALLOC_ERROR);
		exit(-1);
	}
	ft_strcpy(tmp, args);
	free(args);
	return (tmp);
}

void	setnewparam(t_arg *argt)
{
	argt->size += (argt->size + 1) * 2;
	argt->arg = reallocstr(argt->arg, argt->size);
}
