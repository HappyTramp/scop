/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 12:28:57 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 18:48:00 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	st_transform_center_init(t_ftmmat4 *dst, float *vertices, size_t vertices_num)
{
	t_ftmvec3	min;
	t_ftmvec3	max;

	helper_find_boundary(vertices, vertices_num, &min, &max);
	ftm_mat4init_eye(dst, 1.0);
	ftm_mat4translate(dst, -(max.x + min.x) / 2.0f,
			-(max.y + min.y) / 2.0f, -(max.z + min.z) / 2.0f);
}

void		scene_init(t_scene *scene, t_model_data *data)
{
	GL_CALL(glGenVertexArrays(1, &scene->vertex_array));
	GL_CALL(glGenBuffers(1, &scene->vertex_buf));
	GL_CALL(glGenBuffers(1, &scene->index_buf));

	GL_CALL(glBindVertexArray(scene->vertex_array));

	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, scene->vertex_buf));
	GL_CALL(glBufferData(GL_ARRAY_BUFFER, data->vertices_num * sizeof(float),
				data->vertices, GL_STATIC_DRAW));

	GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scene->index_buf));
	GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->indices_num * sizeof(unsigned int),
				data->indices, GL_STATIC_DRAW));
	scene->index_buf_num = data->indices_num;

	GL_CALL(glEnableVertexAttribArray(0));
	GL_CALL(glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, VERTEX_STRIDE, (void*)0));
	GL_CALL(glEnableVertexAttribArray(1));
	GL_CALL(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, VERTEX_STRIDE, (void*)(4 * sizeof(float))));
	GL_CALL(glEnableVertexAttribArray(2));
	GL_CALL(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, VERTEX_STRIDE, (void*)(8 * sizeof(float))));

	ftm_mat4init_eye(&scene->transform.view, 1.0);
	st_transform_center_init(&scene->transform.center, data->vertices, data->vertices_num);
	scene->color_ratio = 1.0;
}

void		scene_update_proj(t_scene *scene, float fov, int width, int height)
{
	ftm_mat4init_eye(&scene->transform.proj, 1.0);
	ftm_mat4init_perspective(&scene->transform.proj, fov, (float)width / (float)height, 0.1, 100.0);
}

void		scene_update_model(t_scene *scene, float rotation_radian)
{
	t_ftmvec3	axis;

	ftm_mat4init_eye(&scene->transform.model, 1.0);
	ftm_mat4translate(&scene->transform.model, 0.0, 0.0, -10.0);
	ftm_mat4rotate(&scene->transform.model, rotation_radian, ftm_vec3init(&axis, 0.0, 1.0, 0.0));
	ftm_mat4mul(&scene->transform.model, &scene->transform.center);
}

void		scene_quit(t_scene *scene)
{
	GL_CALL(glDeleteVertexArrays(1, &scene->vertex_array));
	GL_CALL(glDeleteBuffers(1, &scene->vertex_buf));
	GL_CALL(glDeleteBuffers(1, &scene->index_buf));
}
