/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_vecnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:44:38 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 12:49:30 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec.h"

t_ftmvec	*ftm_vecnew(size_t size)
{
	t_ftmvec	*dst;

	if ((dst = malloc(sizeof(t_ftmvec))) == NULL)
		return (NULL);
	if ((dst->v = malloc(sizeof(float) * size)) == NULL)
	{
		free(dst);
		return (NULL);
	}
	dst->size = size;
	return (dst);
}
