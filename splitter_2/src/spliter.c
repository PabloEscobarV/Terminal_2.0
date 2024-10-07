/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:40:07 by black             #+#    #+#             */
/*   Updated: 2024/10/07 21:40:18 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/terminalmacros.h"
#include "../hdrs/splitter_srv.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>

t_llist	*set_node(t_cchar *str, t_crds *crd, t_splqt *splqt)
{
	int			i;
	int			qts_crd;
	t_llist		*node;
	t_str_crd	*strcrd;

	node = NULL;
	i = crd->front;
	qts_crd = set_crd(str, crd, splqt);
	if (!i)
		i = set_crd_front(str, crd, splqt);
	if (i < crd->front)
	{
		strcrd = crt_str_crd_t(str, i, crd->front);
		if (strcrd)
			node = llistnewnode(strcrd);
	}
	if (!qts_crd)
		return (node);
	strcrd = crt_str_crd_t(str, crd->front + 1, crd->front + qts_crd);
	if (strcrd)
		llistadd_back(&node, llistnewnode(strcrd));
	crd->front += qts_crd;
	return (node);
}

t_llist	*splitter(t_cchar *str, t_splqt *splqt)
{
	t_crds	crd;
	t_llist	*str_crds;
	t_llist	*tmp;

	if (!str)
		return (NULL);
	crd.front = 0;
	crd.end = ft_strlen(str);
	str_crds = NULL;
	while (crd.front < crd.end)
	{
		tmp = set_node(str, &crd, splqt);
		llist_concatenate(&str_crds, tmp);
		++crd.front;
	}
	return (str_crds);
}

// void	printdata(void *data)
// {
// 	t_str_crd	*strcrd;

// 	strcrd = (t_str_crd *)data;
// 	printf("front: %d\tend: %d\n|%s|\n", strcrd->front,
// 		strcrd->end, strcrd->str);
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
// 		llistiter(str_crds, printdata);
// 		free(line);
// 		llistclear(&str_crds, free_t_str_crd_t);
// 	}
// 	ft_free_d((void **)splqt.qts);
// 	ft_free_d((void **)splqt.splts);
// 	free(line);
// }