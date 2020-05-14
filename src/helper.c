/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:55:27 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 16:42:13 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

bool			helper_check_extension(char *filepath, char *extension)
{
	char	*match;

	match = ft_strstr(filepath, extension);
	return (match != NULL && ft_strlen(match) == ft_strlen(extension));
}

void			helper_find_boundary(
		float *vertices,
		size_t vertices_num,
		t_ftmvec3 *max,
		t_ftmvec3 *min)
{
	size_t	i;

	ftm_vec3init(min, INFINITY, INFINITY, INFINITY);
	ftm_vec3init(max, -INFINITY, -INFINITY, -INFINITY);
	i = 0;
	while (i < vertices_num)
	{
		if (vertices[i + 0] > max->x)
			max->x = vertices[i + 0];
		if (vertices[i + 0] < min->x)
			min->x = vertices[i + 0];
		if (vertices[i + 1] > max->y)
			max->y = vertices[i + 1];
		if (vertices[i + 1] < min->y)
			min->y = vertices[i + 1];
		if (vertices[i + 2] > max->z)
			max->z = vertices[i + 2];
		if (vertices[i + 2] < min->z)
			min->z = vertices[i + 2];
		i += VERTEX_COUNT;
	}
}
