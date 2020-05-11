/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:41:44 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 02:10:09 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include "libft.h"
# include "libft_vec.h"

typedef struct
{
	float			*vertices;
	unsigned int	*indices;
	size_t			vertices_len;
	size_t			indices_len;
}					t_object;

typedef struct
{
	unsigned int	vertex_buf;
	unsigned int	index_buf;
}					t_gl_state;

/*
** parse.c
*/

int					parse(char *filepath, t_object *object);

/*
** gl.c
*/

int	gl_state_init(t_gl_state *state, t_object *object);

/*
** error.c
*/

# define GL_CALL(x) error_clear(); \
                    x; \
                    error_check(#x, __FILE__, __LINE__)

void				error_clear(void);
void				error_check(char *code, char *filename, int line_num);

/*
** glfw.c
*/

GLFWwindow			*glfw_init(int width, int height);

#endif
