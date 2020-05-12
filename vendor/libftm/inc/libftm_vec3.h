/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftm_vec3.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:02:29 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 11:04:08 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTM_VEC3_H
# define LIBFTM_VEC3_H

typedef struct
{
	float	v[3];
}			t_ftmvec3;

t_ftmvec3	*ftm_vec3init(t_ftmvec3 *vec3, float x, float y, float z);

#endif
