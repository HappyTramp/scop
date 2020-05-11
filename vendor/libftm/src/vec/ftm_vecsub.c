/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_vecsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:39:42 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 12:49:58 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec.h"

t_ftmvec	*ftm_vecsub(t_ftmvec *dst, t_ftmvec *other)
{
	size_t	i;

	if (dst->size != other->size)
		return (NULL);
	i = 0;
	while (i < dst->size)
	{
		dst->v[i] -= other->v[i];
		i++;
	}
	return (dst);
}
