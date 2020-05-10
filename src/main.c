/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:20:09 by charles           #+#    #+#             */
/*   Updated: 2020/05/10 22:02:36 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int main(int argc, char **argv)
{
	/* GLFWwindow	*window; */
	t_object	object;

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

	for (size_t i = 0; i < object.indices_len; i++)
		printf("%u\n", object.indices[i]);
	for (size_t i = 0; i < object.vertices_len; i++)
		printf("%f\n", object.vertices[i]);

	free(object.vertices);
	free(object.indices);
	/* if (!glfwInit()) */
	/* 	return 1; */
	/* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL); */
	/* if (window == NULL) */
	/* { */
	/* 	glfwTerminate(); */
	/* 	return 1; */
	/* } */
	/* glfwMakeContextCurrent(window); */
	/* while (!glfwWindowShouldClose(window)) */
	/* { */
	/* 	glClear(GL_COLOR_BUFFER_BIT); */
	/* 	glfwSwapBuffers(window); */
	/* 	glfwPollEvents(); */
	/* } */
	/* glfwTerminate(); */
	return 0;
}
