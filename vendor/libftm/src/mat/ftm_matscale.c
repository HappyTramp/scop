/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_matscale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:56:00 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 13:07:25 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat.h"

t_ftmmat	*ftm_matscale(t_ftmmat *dst, float scalar)
{
	size_t	i;
	size_t	size;

	size = dst->shape.x * dst->shape.y;
	i = 0;
	while (i < size)
	{
		dst->m[i] *= scalar;
		i++;
	}
	return (dst);
}
