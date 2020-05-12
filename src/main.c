/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:20:09 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 14:10:09 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int main(int argc, char **argv)
{
	GLFWwindow	*window;
	t_object	object;
	t_gl_state	state;

	/* if (argc != 2) */
	/* { */
	/* 	ft_putstr("Usage: "); */
	/* 	ft_putstr(argv[0]); */
	/* 	ft_putendl(" [obj file]"); */
	/* 	return (1); */
	/* } */
	/* if (parse(argv[1], &object) == -1) */
	/* { */
	/* 	ft_putstr("Error: couldn't parse "); */
	/* 	ft_putendl(argv[1]); */
	/* 	return (1); */
	/* } */

	float positions[] = {
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};
	unsigned int index[] = {
		0, 1, 3,
		1, 2, 3
	};

	object.vertices = malloc(sizeof(positions));
	ft_memcpy(object.vertices, positions, sizeof(positions));
	object.indices = malloc(sizeof(index));
	ft_memcpy(object.indices, index, sizeof(index));
	object.vertices_len = 12;
	object.indices_len = 6;
	/* for (size_t i = 0; i < object.indices_len; i++) */
	/* 	printf("%u\n", object.indices[i]); */
	/* for (size_t i = 0; i < object.vertices_len; i++) */
	/* 	printf("%f\n", object.vertices[i]); */
	/* printf("%lu\n", object.indices_len); */

	t_ftmmat4	trans;
	t_ftmvec3	vec;

	ftm_mat4init_eye(&trans, 1.0);
	/* ftm_mat4translate(&trans, 0.5, 0.5, 0.0); */

	ftm_mat4rotate(&trans, ftm_radian(45.0), ftm_vec3init(&vec, 0.0, 0.0, 1.0));

	/* ftm_mat4scale(&trans, 0.5, 0.5, 0.5); */

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%f, ", trans.m[i * 4 + j]);
		}
		printf("\n");
	}

	if ((window = glfw_init(400, 400)) == NULL
		|| gl_state_init(&state, &object) == -1)
		return (1);

	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	GL_CALL(glBindVertexArray(0));

	GL_CALL(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));

	GL_CALL(glUseProgram(state.shader));
	gl_state_set_mvp(&state, &trans);

	while (!glfwWindowShouldClose(window))
	{
		GL_CALL(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
		GL_CALL(glClear(GL_COLOR_BUFFER_BIT));

		GL_CALL(glUseProgram(state.shader));
		ftm_mat4rotate(&trans, ftm_radian(1.0), ftm_vec3init(&vec, 0.0, 0.0, 1.0));
		gl_state_set_mvp(&state, &trans);

		GL_CALL(glBindVertexArray(state.vertex_array));
		GL_CALL(glDrawElements(GL_TRIANGLES, object.indices_len, GL_UNSIGNED_INT, (void*)0));

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	gl_state_quit(&state, &object);
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
