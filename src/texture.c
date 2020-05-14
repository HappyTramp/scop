/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:27:34 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 14:01:38 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/* typedef struct __attribute__((__packed__)) */
/* { */
/* 	uint8_t		signature[2]; */
/* 	uint32_t	file_size; */
/* 	uint32_t	reserved; */
/* 	uint32_t	img_data_offset; */
/* }				t_bmp_file_header; */
/*  */
/* typedef struct __attribute__((__packed__)) */
/* { */
/* 	uint32_t	header_size; */
/* 	uint32_t	width; */
/* 	uint32_t	height; */
/* 	uint16_t	color_planes; */
/* 	uint16_t	depth; */
/* 	uint32_t	compression; */
/* 	uint32_t	image_size; */
/* 	uint32_t	horizontal_res; */
/* 	uint32_t	vertical_res; */
/* 	uint32_t	color_table_len; */
/* 	uint32_t	color_count; */
/* }				t_bmp_info_header; */
/*  */
/* uint8_t			*st_read_bmp(char *filepath, size_t *width, size_t *height) */
/* { */
/* 	uint8_t				*data; */
/* 	t_bmp_file_header	file_header; */
/* 	t_bmp_info_header	info_header; */
/* 	int	fd; */
/*  */
/* 	fd = open(filepath, O_RDONLY); */
/* 	read(fd, &file_header, sizeof(t_bmp_file_header)); */
/* 	if (file_header.signature[0] != 'B' || file_header.signature[1] != 'M') */
/* 	{ */
/* 		close(fd); */
/* 		return (NULL); */
/* 	} */
/* 	read(fd, &info_header, sizeof(t_bmp_info_header)); */
/* 	if ((data = malloc(info_header.image_size)) == NULL) */
/* 	{ */
/* 		close(fd); */
/* 		return (NULL); */
/* 	} */
/* 	*width = info_header.width; */
/* 	*height = info_header.height; */
/* 	read(fd, data, info_header.image_size);  // padding */
/* 	close(fd); */
/* 	return (data); */
/* } */
/*  */
/* unsigned int	texture_new(char *filepath) */
/* { */
/* 	uint8_t			*data; */
/* 	unsigned int	texture; */
/* 	size_t			width; */
/* 	size_t			height; */
/*  */
/* 	if ((data = st_read_bmp(filepath, &width, &height)) == NULL) */
/* 		return (0); */
/* 	GL_CALL(glGenTextures(1, &texture)); */
/* 	GL_CALL(glBindTexture(GL_TEXTURE_2D, texture)); */
/* 	GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)); */
/* 	GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)); */
/* 	GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE)); */
/* 	GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE)); */
/* 	GL_CALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data)); */
/* 	free(data); */
/* 	return (texture); */
/* } */
/*  */
/* float	*texture_coord_create(float *vertices, size_t vertices_len) */
/* { */
/* 	t_ftmvec3	min; */
/* 	t_ftmvec3	max; */
/* 	float		*coords; */
/* 	size_t		i; */
/*  */
/* 	if ((coords = malloc(sizeof(float) * (vertices_len * 2))) == NULL) */
/* 		return (NULL); */
/* 	st_find_boundary(vertices, vertices_len, &min, &max); */
/* 	i = 0; */
/* 	while (i < vertices_len) */
/* 	{ */
/* 		coords[i * 2 + 0] = (vertices[i * 4 + 0] - min.x) * (1.0 / (max.x - min.x)); */
/* 		coords[i * 2 + 1] = (vertices[i * 4 + 1] - min.y) * (1.0 / (max.y - min.y)); */
/* 		i++; */
/* 	} */
/* 	return (coords); */
/* } */
