/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 20:48:30 by charles           #+#    #+#             */
/*   Updated: 2020/05/09 21:11:12 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTM_VEC4_H
# define LIBFTM_VEC4_H

/*
** \brief   4 component vector [x, y, z, w]
*/

typedef struct
{
	float	v[4];
}			t_ftmvec4;

t_ftmvec4	*ftm_vec4add(t_ftmvec4 *dst, t_ftmvec4 *other);
t_ftmvec4	*ftm_vec4sub(t_ftmvec4 *dst, t_ftmvec4 *other);
float		ftm_vec4dot(t_ftmvec4 *a, t_ftmvec4 *b);
t_ftmvec4	*ftm_vec4scale(t_ftmvec4 *dst, float scalar);

#endif
