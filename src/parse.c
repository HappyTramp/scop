/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 11:02:00 by charles           #+#    #+#             */
/*   Updated: 2020/05/10 22:04:05 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#define SCOP_VEC_DEFAULT_SIZE 32

static int	st_parse_face(char **indexes_strs, t_ftvec *indices)
{
	size_t			i;
	size_t			len;
	unsigned int	tmp;

	len = ft_split_len(indexes_strs);
	i = -1;
	while (++i < len)
	{
		tmp = ft_atoi(indexes_strs[i]);
		if (ft_vecpush(indices, *(void**)&tmp) == NULL)
			return (-1);
	}
	return (0);
}

static int	st_parse_vertex(char **positions_strs, t_ftvec *vertices)
{
	float	tmp;

	tmp = ft_atof(positions_strs[0]);
	ft_vecpush(vertices, *((void**)&tmp));
	tmp = ft_atof(positions_strs[1]);
	ft_vecpush(vertices, *((void**)&tmp));
	tmp = ft_atof(positions_strs[2]);
	ft_vecpush(vertices, *((void**)&tmp));
	return (0);
}

static int	st_parse_line(char *line, t_ftvec *vertices, t_ftvec *indices)
{
	int		ret;
	char	**split;

	if (*line != 'v' && *line != 'f')
		return (0);
	if ((split = ft_split(line + 1, ' ')) == NULL)
		return (-1);
	ret = -1;
	if (*line == 'v' && ft_split_len(split) == 3)
		ret = st_parse_vertex(split, vertices);
	if (*line == 'f' && ft_split_len(split) >= 3)
		ret = st_parse_face(split, indices);
	ft_split_destroy(split);
	return (ret);
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
	free(line);
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
	object->vertices_len = vertices->size;
	object->indices_len = indices->size;
	ft_vecdestroy(vertices, NULL);
	ft_vecdestroy(indices, NULL);
	return (0);
}
