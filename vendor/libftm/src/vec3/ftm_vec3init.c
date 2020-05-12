/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_vec3init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:19:55 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 11:20:53 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec3.h"

t_ftmvec3	*ftm_vec3init(t_ftmvec3 *vec3, float x, float y, float z)
{
	vec3->v[0] = x;
	vec3->v[1] = y;
	vec3->v[2] = z;
	return (vec3);
}
