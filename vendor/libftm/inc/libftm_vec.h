/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftm_vec.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 13:27:54 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 13:28:27 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTM_VEC_H
# define LIBFTM_VEC_H

# include <stdlib.h>
# include <stddef.h>

/*
** \brief    component vector [x, y, z]
*/

typedef struct	s_ftmvec
{
	float		*v;
	size_t		size;
}				t_ftmvec;

t_ftmvec		*ftm_vecnew(size_t size);
void			ftm_vecdestroy(t_ftmvec *vec);
t_ftmvec		*ftm_vecadd(t_ftmvec *dst, t_ftmvec *other);
t_ftmvec		*ftm_vecsub(t_ftmvec *dst, t_ftmvec *other);
float			ftm_vecdot(t_ftmvec *a, t_ftmvec *b);
t_ftmvec		*ftm_veccross(t_ftmvec *a, t_ftmvec *b);
t_ftmvec		*ftm_vecscale(t_ftmvec *dst, float scalar);

#endif
