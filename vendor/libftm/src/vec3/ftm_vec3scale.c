/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_vec3scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 21:00:32 by charles           #+#    #+#             */
/*   Updated: 2020/05/09 21:14:10 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec3.h"

t_ftmvec3	*ftm_vec3scale(t_ftmvec3 *dst, float scalar)
{
	dst->v[0] *= scalar;
	dst->v[1] *= scalar;
	dst->v[2] *= scalar;
	return (dst);
}
