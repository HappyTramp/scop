/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftm_vec3.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 20:38:30 by charles           #+#    #+#             */
/*   Updated: 2020/05/09 21:12:05 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTM_VEC3_H
# define LIBFTM_VEC3_H

/*
** \brief   3 component vector [x, y, z]
*/

typedef struct
{
	float	v[3];
}			t_ftmvec3;

t_ftmvec3	*ftm_vec3add(t_ftmvec3 *dst, t_ftmvec3 *other);
t_ftmvec3	*ftm_vec3sub(t_ftmvec3 *dst, t_ftmvec3 *other);
float		ftm_vec3dot(t_ftmvec3 *a, t_ftmvec3 *b);
void		ftm_vec3cross(t_ftmvec3 *dst, t_ftmvec3 *a, t_ftmvec3 *b);
t_ftmvec3	*ftm_vec3scale(t_ftmvec3 *dst, float scalar);

#endif
