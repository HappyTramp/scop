/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:41:44 by charles           #+#    #+#             */
/*   Updated: 2020/05/10 21:18:15 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <unistd.h>
# include <fcntl.h>
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

/*
** parse.c
*/

int					parse(char *filepath, t_object *object);

#endif
