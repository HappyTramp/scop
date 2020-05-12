/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:27:34 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 16:19:56 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

uint8_t			*st_read_bmp(char *filepath, size_t *width, size_t *height)
{
	t_ftmem	file;

	if (ft_getfile(open(filepath, O_RDONLY), &file) == -1)
		return (NULL);
	*width = 0;
	*height = 0;
	return (file.data);
}

unsigned int	texture_new(char *filepath)
{
	uint8_t			*data;
	unsigned int	texture;
	size_t			width;
	size_t			height;

	if ((data = st_read_bmp(filepath, &width, &height)) == NULL)
		return (0);
	GL_CALL(glGenTextures(1, &texture));
	GL_CALL(glBindTexture(GL_TEXTURE_2D, texture));
	GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GL_CALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data));
	free(data);
	return (texture);
}
