/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 12:28:57 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 14:52:00 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#define VERTEX_STRIDE sizeof(float) * 4

void	st_transform_center_init(t_ftmmat4 *dst, float *vertices, size_t vertices_size)
{
	size_t		i;
	t_ftmvec3	min;
	t_ftmvec3	max;

	ftm_vec3init(&min, INFINITY, INFINITY, INFINITY);
	ftm_vec3init(&max, -INFINITY, -INFINITY, -INFINITY);
	i = 0;
	while (i < vertices_size)
	{
		if (vertices[i + 0] > max.x)
			max.x = vertices[i + 0];
		if (vertices[i + 0] < min.x)
			min.x = vertices[i + 0];
		if (vertices[i + 1] > max.y)
			max.y = vertices[i + 1];
		if (vertices[i + 1] < min.y)
			min.y = vertices[i + 1];
		if (vertices[i + 2] > max.z)
			max.z = vertices[i + 2];
		if (vertices[i + 2] < min.z)
			min.z = vertices[i + 2];
		i += VERTEX_STRIDE / sizeof(float);
	}
	ftm_mat4init_eye(dst, 1.0);
	ftm_mat4translate(dst, -(max.x + min.x) / 2.0f,
			-(max.y + min.y) / 2.0f, -(max.z + min.z) / 2.0f);
}

void	scene_init(t_scene *scene, t_model_data *data)
{
	GL_CALL(glGenVertexArrays(1, &scene->vertex_array));
	GL_CALL(glGenBuffers(1, &scene->vertex_buf));
	GL_CALL(glGenBuffers(1, &scene->index_buf));

	GL_CALL(glBindVertexArray(scene->vertex_array));

	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, scene->vertex_buf));
	GL_CALL(glBufferData(GL_ARRAY_BUFFER, data->vertices_size * sizeof(float), data->vertices, GL_STATIC_DRAW));

	GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scene->index_buf));
	GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->indices_size * sizeof(unsigned int), data->indices, GL_STATIC_DRAW));
	scene->index_buf_size = data->indices_size;

	GL_CALL(glEnableVertexAttribArray(0));
	GL_CALL(glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, VERTEX_STRIDE, (void*)0));
	/* GL_CALL(glEnableVertexAttribArray(1)); */
	/* GL_CALL(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, VERTEX_STRIDE, (void*)(4 * sizeof(float)))); */
	/* GL_CALL(glEnableVertexAttribArray(2)); */
	/* GL_CALL(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, VERTEX_STRIDE, (void*)(8 * sizeof(float)))); */

	ftm_mat4init_eye(&scene->transform.view, 1.0);
	st_transform_center_init(&scene->transform.center, data->vertices, data->vertices_size);
	debugmat(&scene->transform.center);
	scene_update_model(scene, M_PI_4);
	scene_update_proj(scene, M_PI_4, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void	scene_update_proj(t_scene *scene, float fov, int width, int height)
{
	ftm_mat4init_eye(&scene->transform.proj, 1.0);
	ftm_mat4init_perspective(&scene->transform.proj, fov, (float)width / (float)height, 0.1, 100.0);
}

void	scene_update_model(t_scene *scene, float rotation_radian)
{
	t_ftmvec3	axis;

	ftm_mat4init_eye(&scene->transform.model, 1.0);
	ftm_mat4translate(&scene->transform.model, 0.0, 0.0, -10.0);
	ftm_mat4rotate(&scene->transform.model, rotation_radian, ftm_vec3init(&axis, 0.0, 1.0, 0.0));
	ftm_mat4mul(&scene->transform.model, &scene->transform.center);
}

void	scene_quit(t_scene *scene)
{
	GL_CALL(glDeleteVertexArrays(1, &scene->vertex_array));
	GL_CALL(glDeleteBuffers(1, &scene->vertex_buf));
	GL_CALL(glDeleteBuffers(1, &scene->index_buf));
}
