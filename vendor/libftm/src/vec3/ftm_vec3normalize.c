/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_vec3normalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 18:05:22 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 18:06:04 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec3.h"

t_ftmvec3	*ftm_vec3normalize(t_ftmvec3 *vec3)
{
	float	norm;

	norm = ftm_vec3norm(vec3);
	vec3->x /= norm;
	vec3->y /= norm;
	vec3->z /= norm;
	return (vec3);
}
