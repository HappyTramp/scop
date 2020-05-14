/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 11:53:53 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 16:42:21 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	color_init(float *vertices, size_t vertices_num)
{
	size_t			i;
	float			step;
	union u_color	color;

	step = 0.8 / (float)(vertices_num / VERTEX_COUNT);
	i = 0;
	color.r = 0.1;
	color.g = 0.1;
	color.b = 0.1;
	color.a = 1.0;
	while (i < vertices_num)
	{
		color.r += step;
		color.g += step;
		color.b += step;
		ft_memcpy(&vertices[i + VERTEX_COLOR_OFFSET],
				color.data, 4 * sizeof(float));
		i += VERTEX_COUNT;
	}
}
