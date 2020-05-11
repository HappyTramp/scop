/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:58:00 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 02:16:58 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

GLFWwindow	*glfw_init(int width, int height)
{
	GLFWwindow	*window;

	if (!glfwInit())
		return (NULL);
	window = glfwCreateWindow(width, height, "scop", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(window);
	glewInit();
	return (window);
}
