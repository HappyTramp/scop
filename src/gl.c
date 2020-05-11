/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:31:10 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 10:42:42 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		gl_state_init(t_gl_state *state, t_object *object)
{
	if ((state->shader = shader_new()) == 0)
		return (-1);
	GL_CALL(glGenBuffers(1, &state->vertex_buf));
	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, state->vertex_buf));
	GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * object->vertices_len,
				object->vertices, GL_STATIC_DRAW));

	GL_CALL(glGenBuffers(1, &state->index_buf));
	GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, state->index_buf));
	GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * object->indices_len,
				object->indices, GL_STATIC_DRAW));

	GL_CALL(glGenVertexArrays(1, &state->vertex_array));
	GL_CALL(glBindVertexArray(state->vertex_array));
	GL_CALL(glEnableVertexAttribArray(0));
	GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (const void*)0));
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
