/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_mat4rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:44:18 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 14:05:18 by charles          ###   ########.fr       */
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
	t_ftmmat4	rot;

	x = axis->v[0];
	y = axis->v[1];
	z = axis->v[2];
	sin_t = sin(theta);
	cos_t = cos(theta);
	ftm_mat4init_fill(&rot, 0.0);
	ftm_mat4set(&rot, 0, 0, cos_t + x * x * (1 - cos_t));
	ftm_mat4set(&rot, 1, 0, y * x * (1 - cos_t) + z * sin_t);
	ftm_mat4set(&rot, 2, 0, z * x * (1 - cos_t) + y * sin_t);
	ftm_mat4set(&rot, 3, 0, 0.0);

	ftm_mat4set(&rot, 0, 1, x * y * (1 - cos_t) - z * sin_t);
	ftm_mat4set(&rot, 1, 1, cos_t + y * y * (1 - cos_t));
	ftm_mat4set(&rot, 2, 1, z * y * (1 - cos_t) + x * sin_t);
	ftm_mat4set(&rot, 3, 1, 0);

	ftm_mat4set(&rot, 0, 2, x * z * (1 - cos_t) + y * sin_t);
	ftm_mat4set(&rot, 1, 2, y * z * (1 - cos_t) - x * sin_t);
	ftm_mat4set(&rot, 2, 2, cos_t + z * z * (1 - cos_t));
	ftm_mat4set(&rot, 3, 2, 0);

	ftm_mat4set(&rot, 3, 3, 1.0);
	ftm_mat4mul(mat4, &rot);
	return (mat4);
}
