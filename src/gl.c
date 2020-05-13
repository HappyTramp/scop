/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:31:10 by charles           #+#    #+#             */
/*   Updated: 2020/05/13 16:44:20 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		gl_state_init(t_gl_state *state, t_object *object)
{
	if ((state->shader = shader_new()) == 0)
		return (-1);
	GL_CALL(state->view_location = glGetUniformLocation(state->shader, "u_view"));
	if (state->view_location == -1)
		return (-1);
	GL_CALL(state->model_location = glGetUniformLocation(state->shader, "u_model"));
	if (state->model_location == -1)
		return (-1);
	GL_CALL(state->proj_location = glGetUniformLocation(state->shader, "u_proj"));
	if (state->proj_location == -1)
		return (-1);

	GL_CALL(glGenVertexArrays(1, &state->vertex_array));
	GL_CALL(glGenBuffers(1, &state->vertex_buf));
	GL_CALL(glGenBuffers(1, &state->index_buf));

	GL_CALL(glBindVertexArray(state->vertex_array));

	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, state->vertex_buf));
	GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 10 * object->vertices_len,
				object->vertices, GL_STATIC_DRAW));

	GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, state->index_buf));
	GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 3 * object->indices_len,
				object->indices, GL_STATIC_DRAW));

	GL_CALL(glEnableVertexAttribArray(0));
	GL_CALL(glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 10, (void*)0));
	GL_CALL(glEnableVertexAttribArray(1));
	GL_CALL(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 10, (void*)(4 * sizeof(float))));
	GL_CALL(glEnableVertexAttribArray(2));
	GL_CALL(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 10, (void*)(8 * sizeof(float))));

	state->polygon_mode = GL_FILL;
	state->polygon_mode_last_time = glfwGetTime();
	state->fov = M_PI_4;
	return (0);
}

void	gl_state_quit(t_gl_state *state, t_object *object)
{
	GL_CALL(glDeleteVertexArrays(1, &state->vertex_array));
	GL_CALL(glDeleteBuffers(1, &state->vertex_buf));
	GL_CALL(glDeleteBuffers(1, &state->index_buf));
	GL_CALL(glDeleteProgram(state->shader));
	free(object->vertices);
	free(object->indices);
}

void	gl_state_set_mvp(t_gl_state *state, t_ftmmat4 *model, t_ftmmat4 *view, t_ftmmat4 *proj)
{
	if (model != NULL)
	{
		GL_CALL(glUniformMatrix4fv(state->model_location, 1, GL_TRUE, model->m));
	}
	if (view != NULL)
	{
		GL_CALL(glUniformMatrix4fv(state->view_location, 1, GL_TRUE, view->m));
	}
	if (proj != NULL)
	{
		GL_CALL(glUniformMatrix4fv(state->proj_location, 1, GL_TRUE, proj->m));
	}
}
