/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:40:07 by black             #+#    #+#             */
/*   Updated: 2024/10/10 23:34:03 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/terminalmacros.h"
#include "../hdrs/splitter_srv.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>

static char	*set_splt(t_cchar *str, t_splqt *splt)
{
	int		i;

	if (!(*str))
		return (NULL);
	i = cmpstrv(str, splt->qts);
	if (splt->qts[i])
		return (ft_strdup(splt->qts[i]));
	i = cmpstrv(str, splt->splts);
	return (ft_strdup(splt->splts[i]));
}

t_llist	*set_node_data(t_cchar *str, int i, t_crds *crd, t_splqt *splqt)
{
	int			spl_i;
	t_str_crd	*strcrd;
	t_llist		*node;

	node = NULL;
	if (i < crd->front)
	{
		spl_i = cmpstrv(str + i, splqt->splts);
		strcrd = crt_str_crd_t(str + i + ft_strlen(splqt->splts[spl_i]),
			crd->front - i);
		if (strcrd)
		{
			if (!splqt->splts[spl_i])
				i = crd->front;
			strcrd->splt = set_splt(str + i, splqt);
			node = llistnewnode(strcrd);
		}
	}
	return (node);
}

t_llist	*set_node_str(t_cchar *str, int i, t_crds *crd, t_splqt* splqt)
{
	t_str_crd	*strcrd;
	t_llist		*node;

	node = NULL;
	if (i)
	{
		strcrd = crt_str_crd_t(str + crd->front + 1, crd->front + i - 1);
		if (strcrd)
		{
			strcrd->splt = set_splt(str + crd->front, splqt);
			node = llistnewnode(strcrd);
		}
	}
	return (node);
}

t_llist	*set_node(t_cchar *str, t_crds *crd, t_splqt *splqt)
{
	int			i;
	int			qts_crd;
	t_llist		*node;

	i = crd->front;
	qts_crd = set_crd(str, crd, splqt);
	if (!i)
		i = set_crd_front(str, crd, splqt);
	node = set_node_data(str, i, crd, splqt);
	llistadd_back(&node, set_node_str(str, qts_crd, crd, splqt));
	crd->front += qts_crd;
	return (node);
}

t_llist	*splitter(t_cchar *str, t_splqt *splqt)
{
	int		i;
	t_crds	crd;
	t_llist	*str_crds;

	if (!str)
		return (NULL);
	crd.front = 0;
	crd.end = ft_strlen(str);
	str_crds = NULL;
	while (crd.front < crd.end)
	{
		llist_concatenate(&str_crds, set_node(str, &crd, splqt));
		i = ft_strlen(splqt->splts[cmpstrv(str + crd.front, splqt->splts)]);
		if (!i)
			i = ft_strlen(splqt->qts[cmpstrv(str + crd.front, splqt->qts)]);
		crd.front += i;
	}
	return (str_crds);
}

// void	printllist(void *data)
// {
// 	printf("splt: |%s|\t|%s|\n", ((t_str_crd *)(data))->splt,
// 		((t_str_crd *)(data))->str);
// }

// int	main()
// {
// 	char	*line;
// 	t_splqt	splqt;
// 	t_llist	*str_crds;

// 	splqt.qts = (t_cchar **)ft_split(QTS, SPLTCH);
// 	splqt.splts = (t_cchar **)ft_split(SPLTS, SPLTCH);
// 	while (1)
// 	{
// 		line = readline("Pablo Escobar:\t");
// 		if (!ft_strcmp(line, "exit"))
// 			break ;
// 		printf("ENTERED LINE:\t%s\n", line);
// 		str_crds = splitter(line, &splqt);
// 		llistiter(str_crds, printllist);
// 		free(line);
// 		llistclear(&str_crds, free_t_str_crd_t);
// 	}
// 	ft_free_d((void **)splqt.qts);
// 	ft_free_d((void **)splqt.splts);
// 	free(line);
// }