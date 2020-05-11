/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:31:10 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 02:17:16 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	gl_state_init(t_gl_state *state, t_object *object)
{
	GL_CALL(glGenBuffers(1, &state->vertex_buf));
	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, state->vertex_buf));
	GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * object->vertices_len,
				object->vertices, GL_STATIC_DRAW));

	GL_CALL(glGenBuffers(1, &state->index_buf));
	GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, state->index_buf));
	GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * object->indices_len,
				object->indices, GL_STATIC_DRAW));
	return (0);
}
