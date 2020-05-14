/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:25:52 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 18:49:43 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	st_handle_keydown(t_state *state, SDL_Keycode sym)
{
	if (sym == SDLK_ESCAPE)
		state->running = false;
	else if (sym == SDLK_p)
	{
		if (state->polygon_mode == GL_FILL)
			state->polygon_mode = GL_LINE;
		else if (state->polygon_mode == GL_LINE)
			state->polygon_mode = GL_POINT;
		else if (state->polygon_mode == GL_POINT)
			state->polygon_mode = GL_FILL;
		GL_CALL(glPolygonMode(GL_FRONT_AND_BACK, state->polygon_mode));
	}
	else if (sym == SDLK_t)
	{
		state->transition = true;
	}
}

static void	st_handle_mousewheel(t_state *state, int y)
{
	if (y > 0)
	{
		state->fov -= M_PI / 70.0f;
		if (state->fov <= M_PI_4 / 3)
			state->fov = M_PI_4 / 3;
	}
	else if (y < 0)
	{
		state->fov += M_PI / 70.0f;
		if (state->fov >= M_PI - M_PI_4 / 3)
			state->fov = M_PI - M_PI_4 / 3;
	}
	scene_update_proj(&state->scene, state->fov, state->width, state->height);
}

void		event_handle(t_state *state)
{
	SDL_Event	e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			state->running = false;
		else if (e.type == SDL_KEYDOWN)
			st_handle_keydown(state, e.key.keysym.sym);
		else if (e.type == SDL_MOUSEWHEEL)
			st_handle_mousewheel(state, e.wheel.y);
		else if (e.type == SDL_WINDOWEVENT)
		{
			if (e.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				SDL_GL_GetDrawableSize(
						state->window, &state->width, &state->height);
				scene_update_proj(&state->scene, state->fov,
						state->width, state->height);
				glViewport(0, 0, state->width, state->height);
			}
		}
	}
}
