/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crt_str_crt_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:11:24 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/10/10 23:31:11 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../hdrs/splitter_srv.h"
#include "../../hdrs/terminalmacros.h"

t_str_crd	*crt_str_crd_t(t_cchar *str, int front, int rear)
{
	t_str_crd	*str_crd_t;

	str_crd_t = malloc(sizeof(t_str_crd));
	str_crd_t->front = front;
	str_crd_t->end = rear;
	str_crd_t->str = ft_strldup(str + front, rear - front);
	str_crd_t->splt = NULL;
	return (str_crd_t);
}

void	free_t_str_crd_t(void *data)
{
	t_str_crd	*strcrd;

	strcrd = (t_str_crd *)data;
	free(strcrd->str);
	free(strcrd);
}
