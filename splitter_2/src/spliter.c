/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:40:07 by black             #+#    #+#             */
/*   Updated: 2024/10/06 21:18:18 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/terminalmacros.h"
#include "../hdrs/splitter.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>


int	cmpstrv(t_cchar* str, t_cchar **splt)
{
	while (*splt && !ft_strlcmp(str, *splt))
		++splt;
	return (ft_strlen(*splt));
}

int	check_is_close_qt(t_cchar *str, t_crds *crd, t_cchar **qts)
{
	int	i;

	i = 0;
	str += crd->front;
	if (!cmpstrv(str, qts) || (crd->front && *(str - 1) == BKSLASH))
		return (i);
	while (str[++i] && !(str[i - 1] != BKSLASH && cmpstrv(str + i, qts)));
	return (i);
}

int		set_crd(t_cchar *str, t_crds *crd, t_splqt *splqt)
{
	int	i;

	while (crd->front < crd->end)
	{
		i = check_is_close_qt(str, crd, splqt->qts);
		if (i)
			return (i);
		if (cmpstrv(str + crd->front, splqt->splts))
			break ;
		++crd->front;
	}
	return (E_OK);
}

static void	skip_spaces(t_cchar *str, t_crds *crd)
{
	while (crd->front < crd->end && ft_isspace(str[crd->front]))
		++crd->front;
}

int	set_crd_front(t_cchar *str, t_crds *crd, t_splqt *splt)
{
	int	i;
	int	front;

	if (cmpstrv(str + crd->front, splt->qts))
		return (E_OK);
	i = crd->front;
	if (i)
		--i;
	while (i && str[i] == SPCCH)
		--i;
	if (i)
		return (E_OK);
	++crd->front;
	front = crd->front;
	skip_spaces(str, crd);
	while (crd->front < crd->end)
	{
		if (ft_isspace(str[crd->front])
			|| cmpstrv(str + crd->front, splt->splts))
			break ;
		++crd->front;
	}
	return (front);
}

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

void	printdata(void *data)
{
	t_str_crd	*strcrd;

	strcrd = (t_str_crd *)data;
	printf("front: %d\tend: %d\n|%s|\n", strcrd->front, strcrd->end, strcrd->str);
}

int	main()
{
	char	*line;
	t_splqt	splqt;
	t_llist	*str_crds;

	splqt.qts = (t_cchar **)ft_split(QTS, SPLTCH);
	splqt.splts = (t_cchar **)ft_split(SPLTS, SPLTCH);
	while (1)
	{
		line = readline("Pablo Escobar:\t");
		if (!ft_strcmp(line, "exit"))
			break ;
		printf("ENTERED LINE:\t%s\n", line);
		str_crds = splitter(line, &splqt);
		llistiter(str_crds, printdata);
		free(line);
		llistclear(&str_crds, free_t_str_crd_t);
	}
	ft_free_d((void **)splqt.qts);
	ft_free_d((void **)splqt.splts);
	free(line);
}