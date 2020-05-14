/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 09:35:54 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 14:02:56 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#define SHADER_VERTEX_FILEPATH   "shader/vertex.glsl"
#define SHADER_FRAGMENT_FILEPATH "shader/fragment.glsl"

static unsigned int	st_compile(char *filepath, unsigned int type)
{
	t_ftmem			file;
	unsigned int	id;
	int				result;
	int				len;
	char			*msg;

	if (ft_getfile(open(filepath, O_RDONLY), &file) == -1)
		return (0);
	GL_CALL(id = glCreateShader(type));
	GL_CALL(glShaderSource(id, 1, (const char**)&file.data, (int*)&file.size));
	free(file.data);
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

static bool	st_get_uniform_location(unsigned int shader_id, int	*location, char *name)
{
	GL_CALL(*location = glGetUniformLocation(shader_id, name));
	return (*location != -1);
}

bool	shader_init(t_shader *shader)
{
	unsigned int	shader_vertex;
	unsigned int	shader_fragment;

	if ((shader_vertex = st_compile(SHADER_VERTEX_FILEPATH, GL_VERTEX_SHADER)) == 0
		|| (shader_fragment = st_compile(SHADER_FRAGMENT_FILEPATH, GL_FRAGMENT_SHADER)) == 0)
		return (false);
	GL_CALL(shader->id = glCreateProgram());
	GL_CALL(glAttachShader(shader->id, shader_vertex));
	GL_CALL(glAttachShader(shader->id, shader_fragment));
	GL_CALL(glLinkProgram(shader->id));
	GL_CALL(glValidateProgram(shader->id));
	GL_CALL(glDeleteShader(shader_vertex));
	GL_CALL(glDeleteShader(shader_fragment));
	if (!st_get_uniform_location(shader->id, &shader->location.model, "u_model")
		|| !st_get_uniform_location(shader->id, &shader->location.view, "u_view")
		|| !st_get_uniform_location(shader->id, &shader->location.proj, "u_proj"))
		return (false);
	return (true);
}

void	shader_update_mvp(t_shader *shader, t_scene *scene)
{
	GL_CALL(glUniformMatrix4fv(shader->location.model, 1, GL_TRUE, scene->transform.model.m));
	GL_CALL(glUniformMatrix4fv(shader->location.view, 1, GL_TRUE, scene->transform.view.m));
	GL_CALL(glUniformMatrix4fv(shader->location.proj, 1, GL_TRUE, scene->transform.proj.m));
}
