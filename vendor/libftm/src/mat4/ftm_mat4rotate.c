/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_mat4rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:44:18 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 19:52:55 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat4.h"

/*
** Rotation axis/vector [x, y, z]
**
** 1st column:
** | cos(θ) + x^2 (1 − cos(θ))   |
** | y x (1 − cos(θ)) + z sin(θ) |
** | z x (1 − cos(θ)) − y sin(θ) |
** | 0                           |
**
** 2nd column:
** | x y (1 − cos(θ)) − z sin(θ) |
** | cos(θ) + y^2 (1 − cos(θ))   |
** | z y (1 − cos(θ)) + x sin(θ) |
** | 0                           |
**
** 3rd column:
** | x z (1 − cos(θ)) + y sin(θ) |
** | y z (1 − cos(θ)) − x sin(θ) |
** | cos(θ) + z^2 (1 − cos(θ))   |
** | 0                           |
*/

t_ftmmat4	*ftm_mat4rotate(t_ftmmat4 *mat4, float theta, t_ftmvec3 *axis)
{
	float		x;
	float		y;
	float		z;
	float		sin_t;
	float		cos_t;
	float		m_cos_t;
	t_ftmmat4	rot;

	x = axis->v[0];
	y = axis->v[1];
	z = axis->v[2];
	sin_t = sinf(theta);
	cos_t = cosf(theta);
	m_cos_t = 1.0 - cos_t;
	ftm_mat4init_eye(&rot, 1.0);
	ftm_mat4set(&rot, 0, 0, cos_t + x * x * m_cos_t);
	ftm_mat4set(&rot, 1, 0, y * x * m_cos_t + z * sin_t);
	ftm_mat4set(&rot, 2, 0, z * x * m_cos_t - y * sin_t);
	ftm_mat4set(&rot, 3, 0, 0.0);

	ftm_mat4set(&rot, 0, 1, x * y * m_cos_t - z * sin_t);
	ftm_mat4set(&rot, 1, 1, cos_t + y * y * m_cos_t);
	ftm_mat4set(&rot, 2, 1, z * y * m_cos_t + x * sin_t);
	ftm_mat4set(&rot, 3, 1, 0.0);

	ftm_mat4set(&rot, 0, 2, x * z * m_cos_t + y * sin_t);
	ftm_mat4set(&rot, 1, 2, y * z * m_cos_t - x * sin_t);
	ftm_mat4set(&rot, 2, 2, cos_t + z * z * m_cos_t);
	ftm_mat4set(&rot, 3, 2, 0.0);

	ftm_mat4mul(mat4, &rot);
	return (mat4);
}
