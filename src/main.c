/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:20:09 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 10:49:17 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int main(int argc, char **argv)
{
	GLFWwindow	*window;
	t_object	object;
	t_gl_state	state;

	if (argc != 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" [obj file]");
		return (1);
	}
	if (parse(argv[1], &object) == -1)
	{
		ft_putstr("Error: couldn't parse ");
		ft_putendl(argv[1]);
		return (1);
	}

	/* for (size_t i = 0; i < object.indices_len; i++) */
	/* 	printf("%u\n", object.indices[i]); */
	/* for (size_t i = 0; i < object.vertices_len; i++) */
	/* 	printf("%f\n", object.vertices[i]); */
	/* printf("%lu\n", object.indices_len); */

	if ((window = glfw_init(400, 400)) == NULL
		|| gl_state_init(&state, &object) == -1)
		return (1);
	while (!glfwWindowShouldClose(window))
	{
		GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
		GL_CALL(glUseProgram(state.shader));
		GL_CALL(glBindVertexArray(state.vertex_array));
		GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, state.index_buf));
		GL_CALL(glDrawElements(GL_TRIANGLES, object.vertices_len, GL_UNSIGNED_INT, (const void*)0));
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	gl_state_quit(&state, &object);
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
