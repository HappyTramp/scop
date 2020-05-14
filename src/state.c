/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:31:10 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 14:59:48 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/* static void	st_resize_callback(GLFWwindow *window, int width, int height) */
/* { */
/* 	(void)window; */
/* 	glViewport(0, 0, width, height); */
/* 	ftm_mat4init_perspective(&g_state->proj, state.fov, (float)width / (float)height, 0.1, 100.0); */
/* } */

static void	st_handle_event(t_state *state)
{
	SDL_Event	e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			state->running = false;
		else if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
				state->running = false;
			else if (e.key.keysym.sym == SDLK_p)
			{
				if (state->polygon_mode == GL_FILL)
					state->polygon_mode = GL_LINE;
				else if (state->polygon_mode == GL_LINE)
					state->polygon_mode = GL_POINT;
				else if (state->polygon_mode == GL_POINT)
					state->polygon_mode = GL_FILL;
				GL_CALL(glPolygonMode(GL_FRONT_AND_BACK, state->polygon_mode));
			}
		}
		else if (e.type == SDL_MOUSEWHEEL)
		{
			if (e.wheel.y > 0)
			{
				state->fov -= M_PI / 70.0f;
				if (state->fov <= M_PI_4 / 3)
					state->fov = M_PI_4 / 3;
			}
			else if (e.wheel.y < 0)
			{
				state->fov += M_PI / 70.0f;
				if (state->fov >= M_PI - M_PI_4 / 3)
					state->fov = M_PI - M_PI_4 / 3;
			}
			scene_update_proj(&state->scene, state->fov, state->width, state->height);
		}
	}
}

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
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
	if (state->window == NULL)
		return (false);
	state->context = SDL_GL_CreateContext(state->window);
	if (glewInit() != GLEW_OK)
		return (false);
	SDL_GL_SetSwapInterval(1);
	GL_CALL(glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	GL_CALL(glEnable(GL_DEPTH_TEST));
	GL_CALL(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));

	if (!shader_init(&state->shader))
		return (false);
	scene_init(&state->scene, data);

	state->fov = M_PI_4;
	state->running = true;
	state->polygon_mode = GL_LINE;
	state->width = WINDOW_WIDTH;
	state->height = WINDOW_HEIGHT;
	return (true);
}

void	state_run(t_state *state)
{
	float	rotation;

	rotation = M_PI_4;
	while (state->running)
	{
		GL_CALL(glClearColor(0.1f, 0.1f, 0.1f, 1.0f));
		GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		GL_CALL(glUseProgram(state->shader.id));
		shader_update_mvp(&state->shader, &state->scene);
		GL_CALL(glBindVertexArray(state->scene.vertex_array));
		GL_CALL(glDrawElements(GL_TRIANGLES, state->scene.index_buf_size, GL_UNSIGNED_INT, (void*)0));

		scene_update_model(&state->scene, rotation);
		SDL_GL_SwapWindow(state->window);
		st_handle_event(state);
		rotation += M_PI / 100.0;
	}
}

void	state_quit(t_state *state)
{
	scene_quit(&state->scene);
	GL_CALL(glDeleteProgram(state->shader.id));
	SDL_GL_DeleteContext(state->context);
	SDL_DestroyWindow(state->window);
	SDL_Quit();
}
