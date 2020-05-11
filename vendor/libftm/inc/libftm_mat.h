/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftm_mat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:50:40 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 13:28:55 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTM_MAT_H
# define LIBFTM_MAT_H

# include <stddef.h>
# include <stdlib.h>
# include "libftm_vec.h"

typedef struct	s_ftmmat
{
	float		*m;
	struct
	{
		size_t	x;
		size_t	y;
	}			shape;
}				t_ftmmat;

t_ftmmat		*ftm_matnew(size_t y, size_t x);
void			ftm_matdestroy(t_ftmmat *mat);
t_ftmmat		*ftm_matadd(t_ftmmat *dst, t_ftmmat *other);
t_ftmmat		*ftm_matsub(t_ftmmat *dst, t_ftmmat *other);
t_ftmmat		*ftm_matscale(t_ftmmat *dst, float scalar);
t_ftmmat		*ftm_matmul(t_ftmmat *dst, t_ftmmat *other);
t_ftmvec		*ftm_matmulvec(t_ftmmat *mat, t_ftmvec *dst);
float			ftm_matat(t_ftmmat *mat, size_t y, size_t x);

#endif
