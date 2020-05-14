/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:20:09 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 19:10:40 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
** TODO
** - texture
**   - parse vt
**   - parse coord index of f
*/

int main(int argc, char **argv)
{
	t_state	state;
	t_model_data data;

	if (argc != 2 && argc != 3)
	{
		ft_putstr("Usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" OBJ_FILE [BMP_FILE]");
		return (1);
	}
	if (parse(argv[1], &data) == -1)
	{
		ft_putstr("Error: couldn't parse ");
		ft_putendl(argv[1]);
		return (1);
	}
	color_init(data.vertices, data.vertices_num);
	texture_coord_init(data.vertices, data.vertices_num);
	if (argc == 3)
		data.texture_filepath = argv[2];
	else
		data.texture_filepath = "res/brick.bmp";

	printf("size %lu\n", data.indices_num);
	for (size_t i = 0; i < data.indices_num; i++)
	{
		printf("%u, ", data.indices[i++]);
		printf("%u, ", data.indices[i++]);
		printf("%u\n", data.indices[i]);
	}

	printf("size %lu\n", data.vertices_num);
	for (size_t i = 0; i < data.vertices_num; i++)
	{
		printf("% f, ", data.vertices[i++]);
		printf("% f, ", data.vertices[i++]);
		printf("% f, ", data.vertices[i++]);
		printf("% f | ", data.vertices[i++]);
		printf("% f, ", data.vertices[i++]);
		printf("% f, ", data.vertices[i++]);
		printf("% f, ", data.vertices[i++]);
		printf("% f | ", data.vertices[i++]);
		printf("% f ", data.vertices[i++]);
		printf("% f\n", data.vertices[i]);
	}

	if (!state_init(&state, &data))
		return (1);
	state_run(&state);
	state_quit(&state);
	free(data.vertices);
	free(data.indices);
	return 0;
}
