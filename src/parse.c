/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 11:02:00 by charles           #+#    #+#             */
/*   Updated: 2020/05/09 12:07:36 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#define SCOP_VEC_DEFAULT_SIZE 32

static int	st_parse_line(char *line, t_ftvec *vertices, t_ftvec *indices)
{
	unsigned int	tmp;
	float			tmpf;

	if (*line == 'v')
	{
		tmpf = ft_strtof(line, &line);
		ft_vecpush(indices, *((void**)&tmp));
		tmpf = ft_strtof(line, &line);
		ft_vecpush(indices, *((void**)&tmp));
		tmpf = ft_strtof(line, &line);
		ft_vecpush(indices, *((void**)&tmp));
	}
	if (*line == 'f')
	{
		tmp = ft_strtol(line, &line, 10);
		ft_vecpush(indices, *((void**)&tmp));
		tmp = ft_strtol(line, &line, 10);
		ft_vecpush(indices, *((void**)&tmp));
		tmp = ft_strtol(line, &line, 10);
		ft_vecpush(indices, *((void**)&tmp));
	}


	return (0);
}

static int	st_parse_file(int fd, t_ftvec *vertices, t_ftvec *indices)
{
	char	*line;
	int		ret;

	while ((ret = ft_getline(fd, &line)) == FT_LINE)
	{
		ret = st_parse_line(line, vertices, indices);
		free(line);
		if (ret == -1)
			break ;
	}
	if (ret == FT_ERROR)
		return (-1);
	if (*line != '\0')
	{
		free(line);
		return (-1);
	}
	return (0);
}

int			parse(char *filepath, t_object *object)
{
	int		fd;
	t_ftvec	*vertices;
	t_ftvec	*indices;

	if ((fd = open(filepath, O_RDONLY)) == -1)
		return (-1);
	if ((vertices = ft_vecnew(SCOP_VEC_DEFAULT_SIZE)) == NULL)
		return (-1);
	if ((indices = ft_vecnew(SCOP_VEC_DEFAULT_SIZE)) == NULL)
		return (-1);
	st_parse_file(fd, vertices, indices);
	object->vertices = (float*)ft_vectobuf32(vertices);
	object->indices = (unsigned int*)ft_vectobuf32(indices);
	return (0);
}
