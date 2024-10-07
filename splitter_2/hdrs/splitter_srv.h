/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter_srv.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:32:40 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/10/07 22:05:28 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_SRV_H
# define SPLITTER_SRV_H

# include "splitter.h"

int	check_is_close_qt(t_cchar *str, t_crds *crd, t_cchar **qts);
int	cmpstrv(t_cchar *str, t_cchar **splt);
int	set_crd_front(t_cchar *str, t_crds *crd, t_splqt *splt);
int	set_crd(t_cchar *str, t_crds *crd, t_splqt *splqt);

#endif