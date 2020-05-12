/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftm_mat4.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:04:59 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 17:21:34 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTM_MAT4_H
# define LIBFTM_MAT4_H

# include <stddef.h>
# include <math.h>
# include "libftm_vec3.h"

typedef struct
{
	float	m[4 * 4];
}			t_ftmmat4;

/*
** http://www.songho.ca/opengl/gl_projectionmatrix.html
*/

typedef struct
{
	float	near;
	float	far;
	float	left;
	float	right;
	float	top;
	float	bottom;
}			t_ftmfrustum;

typedef struct
{
	float	near;
	float	far;
	float	width;
	float	height;
}			t_ftmfrustum_sym;

t_ftmmat4	*ftm_mat4init_eye(t_ftmmat4 *mat4, float x);
t_ftmmat4	*ftm_mat4init_fill(t_ftmmat4 *mat4, float x);
t_ftmmat4	*ftm_mat4init_frustum(t_ftmmat4 *mat4, t_ftmfrustum *frustum);
t_ftmmat4	*ftm_mat4init_frustum_sym(t_ftmmat4 *mat4, t_ftmfrustum_sym *frustum);
t_ftmmat4	*ftm_mat4init_perspective(t_ftmmat4 *mat4, float fov, float aspect_ratio, float near, float far);
t_ftmmat4	*ftm_mat4translate(t_ftmmat4 *mat4, float x, float y, float z);
t_ftmmat4	*ftm_mat4rotate(t_ftmmat4 *mat4, float radian, t_ftmvec3 *axis);
t_ftmmat4	*ftm_mat4scale(t_ftmmat4 *mat4, float x, float y, float z);
t_ftmmat4	*ftm_mat4mul(t_ftmmat4 *dst, t_ftmmat4 *other);
t_ftmmat4	*ftm_mat4set(t_ftmmat4 *mat4, size_t y, size_t x, float value);
float		ftm_mat4get(t_ftmmat4 *mat4, size_t y, size_t x);


#endif
