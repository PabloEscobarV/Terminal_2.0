/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:40:07 by black             #+#    #+#             */
/*   Updated: 2024/10/05 17:19:42 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/terminalmacros.h"
#include "../hdrs/servicespltr.h"
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
	str += crd->i;
	if (!cmpstrv(str, qts) || (crd->i && *(str - 1) == SLASH))
		return (i);
	while (str[++i] && !(str[i - 1] != SLASH && cmpstrv(str + i, qts)));
	return (i);
}

int	set_crd_str(t_cchar *str, t_crds *crd, t_splqt *splqt)
{
	while (crd->i < crd->size)
	{
		if (cmpstrv(str + crd->i, splqt->qts))
			return (0);
		if (cmpstrv(str + crd->i, splqt->splts))
			break ;
		++crd->i;
	}
	return (1);
}

t_llist	*set_node(t_cchar *str, t_crds *crd, t_splqt *splqt)
{
	int		i;
	int		next_crd;

	i = crd->i;
	crd->i += check_is_close_qt(str, crd, splqt->qts);
	if (crd->i == i)
		next_crd = set_crd_str(str, crd, splqt);
	crd->i += next_crd;
	return (llistnewnode(crt_crds(i, crd->i - next_crd)));
}

t_llist	*splitter(t_cchar *str, t_splqt *splqt)
{
	t_crds	crd;
	t_llist	*str_crds;

	if (!str)
		return (NULL);
	crd.i = 0;
	crd.size = ft_strlen(str);
	str_crds = NULL;
	while (crd.i < crd.size)
		llistadd_back(&str_crds, set_node(str, &crd, splqt));
	return (str_crds);
}

void	print_crd(char *str, int f, int r)
{
	ft_putchar('|');
	while (f < r)
	{
		ft_putchar(*(str + f));
		++f;
	}
	ft_putchar('|');
	ft_putchar('\n');
}

void	print_result(char *str, t_llist *str_crd)
{
	while (str_crd)
	{
		printf("front: %d\trear: %d\n", ((t_crds *)(str_crd->data))->i,
			((t_crds *)(str_crd->data))->size);
		print_crd(str, ((t_crds *)(str_crd->data))->i,
			((t_crds *)(str_crd->data))->size);
		str_crd = str_crd->next;
	}
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
		print_result(line, str_crds);
		free(line);
		llistclear(&str_crds, freecrds);
	}
	free(line);
}

// void	print_str_crds(void *data)
// {
// 	t_crds	*crd;

// 	crd = (t_crds *)data;
// 	printf("FRONT: %d\tREAR: %d\n", crd->i, crd->size);
// }

// int	set_crd_qts(t_cchar *str, t_crds *crd, t_splqt *splqt)
// {
// 	int	i;

// 	i = check_is_close_qt(str, crd, splqt->splts);
// 	if (!i)
// 		return (E_KO);
// 	crd->i += i;
// 	return (E_OK);
// }