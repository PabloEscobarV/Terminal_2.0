/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crt_str_crt_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:11:24 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/10/06 21:05:07 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../../hdrs/terminalmacros.h"

static void	skip_cpaces(t_cchar *str, int *front, int *rear)
{
	while ((*front < *rear) && *(str + *front) == SPCCH)
		++(*front);
	--(*rear);
	while ((*front < *rear) && *(str + *rear) == SPCCH)
		--(*rear);
}

t_str_crd	*crt_str_crd_t(t_cchar *str, int front, int rear)
{
	int			f;
	int			r;
	t_str_crd	*str_crd_t;

	f = front;
	r = rear;
	skip_cpaces(str, &f, &r);
	if (f > r || (f == r && str[f] == SPCCH))
		return (NULL);
	str_crd_t = malloc(sizeof(t_str_crd));
	str_crd_t->front = front;
	str_crd_t->end = rear;
	str_crd_t->str = ft_strldup(str + f, r - f + 1);
	return (str_crd_t);
}

void	free_t_str_crd_t(void *data)
{
	t_str_crd	*strcrd;

	strcrd = (t_str_crd *)data;
	free(strcrd->str);
	free(strcrd);
}