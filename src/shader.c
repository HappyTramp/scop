/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 09:35:54 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 10:54:14 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#define SHADER_VERTEX_FILEPATH   "shader/vertex.glsl"
#define SHADER_FRAGMENT_FILEPATH "shader/fragment.glsl"

static unsigned int	st_compile(char *filepath, unsigned int type)
{
	char			*src;
	unsigned int	id;
	int				result;
	int				len;
	char			*msg;

	if ((src = ft_getfile(open(filepath, O_RDONLY))) == NULL)
		return (0);
	GL_CALL(id = glCreateShader(type));
	GL_CALL(glShaderSource(id, 1, (const char**)&src, NULL));
	free(src);
	GL_CALL(glCompileShader(id));
	GL_CALL(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if (result == GL_FALSE)
	{
		GL_CALL(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len));
		if ((msg = malloc(sizeof(char) * (len + 1))) == NULL)
			return (0);
		GL_CALL(glGetShaderInfoLog(id, len, &len, msg));
		ft_putendl(msg);
		free(msg);
		GL_CALL(glDeleteShader(id));
		return (0);
	}
	return (id);
}

unsigned int	shader_new(void)
{
	unsigned int	shader_vertex;
	unsigned int	shader_fragment;
	unsigned int	program;

	if ((shader_vertex = st_compile(SHADER_VERTEX_FILEPATH, GL_VERTEX_SHADER)) == 0
		|| (shader_fragment = st_compile(SHADER_FRAGMENT_FILEPATH, GL_FRAGMENT_SHADER)) == 0)
		return (0);
	GL_CALL(program = glCreateProgram());
	GL_CALL(glAttachShader(program, shader_vertex));
	GL_CALL(glAttachShader(program, shader_fragment));
	GL_CALL(glLinkProgram(program));
	GL_CALL(glValidateProgram(program));
	GL_CALL(glDeleteShader(shader_vertex));
	GL_CALL(glDeleteShader(shader_fragment));
	return (program);
}
