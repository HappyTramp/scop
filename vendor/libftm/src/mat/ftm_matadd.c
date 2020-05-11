/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_matadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:56:00 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 13:06:50 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat.h"

t_ftmmat	*ftm_matadd(t_ftmmat *dst, t_ftmmat *other)
{
	size_t	i;
	size_t	size;

	if (dst->shape.x != other->shape.x || dst->shape.y != other->shape.y)
		return (NULL);
	size = dst->shape.x * dst->shape.y;
	i = 0;
	while (i < size)
	{
		dst->m[i] += other->m[i];
		i++;
	}
	return (dst);
}
