/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 10:48:15 by charles           #+#    #+#             */
/*   Updated: 2020/05/13 12:52:43 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	st_find_boundary(float *vertices, size_t vertices_len, t_ftmvec3 *min, t_ftmvec3 *max)
{
	size_t	i;

	ftm_vec3init(min, INFINITY, INFINITY, INFINITY);
	ftm_vec3init(max, -INFINITY, -INFINITY, -INFINITY);
	i = 0;
	while (i < vertices_len * 4)
	{
		if (vertices[i] > max->x)
			max->x = vertices[i];
		if (vertices[i] < min->x)
			min->x = vertices[i];
		i++;
		if (vertices[i] > max->y)
			max->y = vertices[i];
		if (vertices[i] < min->y)
			min->y = vertices[i];
		i++;
		if (vertices[i] > max->z)
			max->z = vertices[i];
		if (vertices[i] < min->z)
			min->z = vertices[i];
		i += 2;
	}
}

void	center_mat4_init_translate(t_ftmmat4 *dst, float *vertices, size_t vertices_len)
{
	t_ftmvec3	min;
	t_ftmvec3	max;

	st_find_boundary(vertices, vertices_len, &min, &max);
	ftm_mat4init_eye(dst, 1.0);
	ftm_mat4translate(dst, -(max.x + min.x) / 2.0f,
							-(max.y + min.y) / 2.0f,
							-(max.z + min.z) / 2.0f);
}
