/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:20:09 by charles           #+#    #+#             */
/*   Updated: 2020/05/09 11:08:59 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int main(int argc, char **argv)
{
	/* GLFWwindow	*window; */
	float		*buffer;

	if (argc != 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" [obj file]");
		return (1);
	}
	if ((buffer = parse(argv[1])) == NULL)
		return 1;

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
