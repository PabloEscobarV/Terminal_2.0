/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:36:48 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/30 22:28:26 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/strhandler.h"
#include "../libft/libft.h"
#include "../HashTable/hdrs/hashtable.h"
#include "../hdrs/terminalmacros.h"
#include "../varhandler/hdrs/varhandler.h"
#include <stdio.h>
#include <readline/readline.h>

void	*hash(t_cchar *key, char **hashtb)
{
	return ((void *)ft_strdup("ABC"));
}

int	main()
{
	char		*argt;
	char		*line;
	char		*tmp;
	char		**substr;
	char		**subend;
	t_hashtable	*hst;
	t_strtosub	tmpt;
	
	hst = crthashtable(64);
	tmpt.qts = ft_strdup("\"\'");
	tmpt.substr = ft_split(SUBSTR, SPLTCH);
	tmpt.subend = ft_split(SUBEND, SPLTCH);
	while (1)
	{
		line = readline("Pablo Escobar:\t");
		if (!ft_strcmp(line, "exit"))
			break ;
		printf("ENTERED LINE:\t%s\n", line);
		tmp = varhandler(line, hst);
		if ((*tmp == *line))
		{
			argt = strhandler(line, &tmpt, hst);
			printf("STRHANDLER OUTPUT:\t|%s|\n", argt);
			free(argt);
		}
		if (*tmp && (*tmp != *line))
			printf("minishell: %s: command not found...\n", tmp);
		free(line);
	}
	free(line);
	ft_free_d((void **)tmpt.subend);
	ft_free_d((void **)tmpt.substr);
	free(tmpt.qts);
	freehashtablet(hst);
	return (0);
}
