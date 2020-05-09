/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_vec4scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 21:00:42 by charles           #+#    #+#             */
/*   Updated: 2020/05/09 21:15:21 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec4.h"

t_ftmvec4	*ftm_vec4scale(t_ftmvec4 *dst, float scalar)
{
	dst->v[0] *= scalar;
	dst->v[1] *= scalar;
	dst->v[2] *= scalar;
	dst->v[3] *= scalar;
	return (dst);
}
