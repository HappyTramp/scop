/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:41:44 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 16:29:38 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <GL/glew.h>
# include <SDL2/SDL.h>

# include "libft.h"
# include "libft_vec.h"
# include "libftm.h"
# include "libftm_mat4.h"
# include "libftm_vec3.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define VERTEX_COUNT 10
#define VERTEX_STRIDE (sizeof(float) * VERTEX_COUNT)

#define VERTEX_POS_OFFSET 0
#define VERTEX_COLOR_OFFSET 4
#define VERTEX_TEX_COORD_OFFSET 8

typedef struct
{
	float			*vertices;
	unsigned int	*indices;
	size_t			vertices_num;
	size_t			indices_num;
	char			*texture_filepath;
}					t_model_data;

typedef struct
{
	unsigned int	vertex_buf;
	unsigned int	index_buf;
	size_t			index_buf_num;
	unsigned int	vertex_array;
	unsigned int	texture;
	struct
	{
		t_ftmmat4	center;
		t_ftmmat4	model;
		t_ftmmat4	view;
		t_ftmmat4	proj;
	}				transform;
}					t_scene;

typedef struct
{
	unsigned int	id;
	struct
	{
		int			model;
		int			view;
		int			proj;
		int			texture;
	}				location;
}					t_shader;

typedef struct
{
	SDL_Window		*window;
	SDL_GLContext	*context;
	bool			running;
	int				width;
	int				height;
	t_scene			scene;
	t_shader		shader;
	GLenum			polygon_mode;
	float			fov;
}					t_state;

union				u_color
{
	float			data[4];
	struct
	{
		float		r;
		float		g;
		float		b;
		float		a;
	};
};

/*
** graphic/state.c
*/

bool				state_init(t_state *state, t_model_data *data);
void				state_run(t_state *state);
void				state_quit(t_state *state);

/*
** graphic/event.c
*/

void				event_handle(t_state *state);

/*
** scene.c
*/

void				scene_init(t_scene *scene, t_model_data *data);
void				scene_update_proj(t_scene *scene, float fov, int width, int height);
void				scene_update_model(t_scene *scene, float rotation_radian);
void				scene_quit(t_scene *scene);

/*
** parse.c
*/

int					parse(char *filepath, t_model_data *object);

/*
** error.c
*/

# define GL_CALL(x) error_clear(); \
                    x; \
                    error_check(#x, __FILE__, __LINE__)

void				error_clear(void);
void				error_check(char *code, char *filename, int line_num);


/*
** shader.c
*/

bool				shader_init(t_shader *shader);
void				shader_set_uniforms(t_shader *shader, t_scene *scene);

/*
** texture.c
*/

unsigned int		texture_create(char *filepath);
void				texture_coord_init(float *vertices, size_t vertices_num);

/*
** helper.c
*/

bool				helper_check_extension(char *filepath, char *extension);
void				helper_find_boundary(
		float *vertices, size_t vertices_num, t_ftmvec3 *max, t_ftmvec3 *min);

/*
** color.c
*/

void				color_init(float *vertices, size_t vertices_num);

#endif
