/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:58:00 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 19:05:43 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

bool	g_window_resized = false;

void		st_resize_callback(GLFWwindow *window, int width, int height)
{
	(void)window;
	g_window_resized = true;
	glViewport(0, 0, width, height);
}

GLFWwindow	*glfw_init(int width, int height)
{
	GLFWwindow	*window;

	if (!glfwInit())
		return (NULL);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(width, height, "scop", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, st_resize_callback);
	if (glewInit() != GLEW_OK)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return (NULL);
	}
	glfwSwapInterval(1);
	/* glViewport(0, 0, width, height); */
	return (window);
}
