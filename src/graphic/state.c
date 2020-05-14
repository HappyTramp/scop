/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:31:10 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 16:39:59 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

bool		state_init(t_state *state, t_model_data *data)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (false);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	state->window = SDL_CreateWindow(
			"scop", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (state->window == NULL)
		return (false);
	state->context = SDL_GL_CreateContext(state->window);
	if (glewInit() != GLEW_OK)
		return (false);
	SDL_GL_SetSwapInterval(1);
	GL_CALL(glEnable(GL_DEPTH_TEST));

	if (!shader_init(&state->shader)
		|| (state->scene.texture = texture_create(data->texture_filepath)) == 0)
		return (false);
	scene_init(&state->scene, data);

	state->fov = M_PI_4;
	state->running = true;
	state->polygon_mode = GL_FILL;
	SDL_GL_GetDrawableSize(state->window, &state->width, &state->height);
	GL_CALL(glViewport(0, 0, state->width, state->height));
	return (true);
}

void		state_run(t_state *state)
{
	float	rotation;

	scene_update_model(&state->scene, M_PI_4);
	scene_update_proj(&state->scene, M_PI_4, state->width, state->height);
	rotation = M_PI_4;
	while (state->running)
	{
		GL_CALL(glClearColor(0.1f, 0.1f, 0.1f, 1.0f));
		GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		GL_CALL(glUseProgram(state->shader.id));
		GL_CALL(glActiveTexture(GL_TEXTURE0));
		GL_CALL(glBindTexture(GL_TEXTURE_2D, state->scene.texture));
		shader_set_uniforms(&state->shader, &state->scene);

		GL_CALL(glBindVertexArray(state->scene.vertex_array));
		GL_CALL(glDrawElements(GL_TRIANGLES,
					state->scene.index_buf_num, GL_UNSIGNED_INT, (void*)0));

		scene_update_model(&state->scene, rotation);
		SDL_GL_SwapWindow(state->window);
		event_handle(state);
		rotation += M_PI / 250.0;
	}
}

void		state_quit(t_state *state)
{
	scene_quit(&state->scene);
	GL_CALL(glDeleteProgram(state->shader.id));
	SDL_GL_DeleteContext(state->context);
	SDL_DestroyWindow(state->window);
	SDL_Quit();
}
