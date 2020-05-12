/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_mat4init_perspective.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:54:49 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 19:07:45 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat4.h"

t_ftmmat4	*ftm_mat4init_perspective(t_ftmmat4 *mat4, float fov, float aspect_ratio,
										float near, float far)
{
	t_ftmfrustum_sym frustum;

	frustum.near = near;
	frustum.far = far;
	frustum.width = 2.0 * (near / tanf(M_PI_2 - (fov / 2.0)));
	frustum.height = frustum.width / aspect_ratio;
	return (ftm_mat4init_frustum_sym(mat4, &frustum));
}
