/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:20:09 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 14:49:02 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
** TODO
** - texture
**   - parse vt
**   - parse coord index of f
**   - transition color/texture
** - cleaner code
*/

/* void	handle_event(GLFWwindow *window) */
/* { */
/* 	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) */
/* 		glfwSetWindowShouldClose(window, true); */
/* 	else if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) */
/* 	{ */
/* 		if (state->polygon_mode_last_time + 0.1 > glfwGetTime()) */
/* 			return ; */
/* 		if (state->polygon_mode == GL_FILL) */
/* 			state->polygon_mode = GL_LINE; */
/* 		else if (state->polygon_mode == GL_LINE) */
/* 			state->polygon_mode = GL_POINT; */
/* 		else if (state->polygon_mode == GL_POINT) */
/* 			state->polygon_mode = GL_FILL; */
/* 		GL_CALL(glPolygonMode(GL_FRONT_AND_BACK, state->polygon_mode)); */
/* 		state->polygon_mode_last_time = glfwGetTime(); */
/* 	} */
/* 	else if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS) */
/* 	{ */
/* 		state->fov -= M_PI / 100.0f; */
/* 		if (state->fov <= M_PI_4 / 2) */
/* 			state->fov = M_PI_4 / 2; */
/* 	} */
/* 	else if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS) */
/* 	{ */
/* 		state->fov += M_PI / 100.0f; */
/* 		if (state->fov >= M_PI - M_PI_4 / 2) */
/* 			state->fov = M_PI - M_PI_4 / 2; */
/* 	} */
/* } */

void	debugmat(t_ftmmat4 *mat)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%.2f, ", mat->m[i * 4 + j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	t_state	state;
	t_model_data data;

	if (argc != 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" [obj file]");
		return (1);
	}
	if (parse(argv[1], &data) == -1)
	{
		ft_putstr("Error: couldn't parse ");
		ft_putendl(argv[1]);
		return (1);
	}

	/* unsigned int texture = texture_new("res/brick.bmp"); */
	/* float *coords = texture_coord_create(object.vertices, object.vertices_len); */
    /*  */
	/* if (!color_merge_vertices(&object, coords)) */
	/* { */
	/* 	ft_putstr("Error: couldn't create colors"); */
	/* 	return (1); */
	/* } */

	printf("size %lu\n", data.indices_size);
	for (size_t i = 0; i < data.indices_size; i++)
	{
		printf("%u, ", data.indices[i++]);
		printf("%u, ", data.indices[i++]);
		printf("%u\n", data.indices[i]);
	}

	printf("size %lu\n", data.vertices_size);
	for (size_t i = 0; i < data.vertices_size; i++)
	{
		printf("% f, ", data.vertices[i++]);
		printf("% f, ", data.vertices[i++]);
		printf("% f, ", data.vertices[i++]);
		printf("% f\n", data.vertices[i]);
		/* printf("% f, ", object.vertices[i++]); */
		/* printf("% f, ", object.vertices[i++]); */
		/* printf("% f, ", object.vertices[i++]); */
		/* printf("% f\ttex: ", object.vertices[i]); */
		/* printf("% f", object.vertices[i++]); */
		/* printf("% f\n", object.vertices[i]); */
	}

	/* GL_CALL(glUniform1i(glGetUniformLocation(state.shader, "u_texture"), 0)); */
	/* GL_CALL(glActiveTexture(GL_TEXTURE0)); */
	/* GL_CALL(glBindTexture(GL_TEXTURE_2D, texture)); */

	if (!state_init(&state, &data))
		return (1);
	state_run(&state);
	state_quit(&state);
	free(data.vertices);
	free(data.indices);
	return 0;
}
