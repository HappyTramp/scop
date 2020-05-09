/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_vec3sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 20:57:33 by charles           #+#    #+#             */
/*   Updated: 2020/05/09 21:14:20 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec3.h"

t_ftmvec3	*ftm_vec3sub(t_ftmvec3 *dst, t_ftmvec3 *other)
{
	dst->v[0] -= other->v[0];
	dst->v[1] -= other->v[1];
	dst->v[2] -= other->v[2];
	return (dst);
}
