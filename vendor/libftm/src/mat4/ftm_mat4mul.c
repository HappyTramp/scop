/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_mat4mul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:22:20 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 14:03:19 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat4.h"

static float	st_dot(t_ftmmat4 *a, t_ftmmat4 *b, int y, int x)
{
	return (ftm_mat4get(a, y, 0) * ftm_mat4get(b, 0, x) +
			ftm_mat4get(a, y, 1) * ftm_mat4get(b, 1, x) +
			ftm_mat4get(a, y, 2) * ftm_mat4get(b, 2, x) +
			ftm_mat4get(a, y, 3) * ftm_mat4get(b, 3, x));
}

t_ftmmat4		*ftm_mat4mul(t_ftmmat4 *dst, t_ftmmat4 *other)
{
	t_ftmmat4	tmp;
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			ftm_mat4set(&tmp, i, j, st_dot(dst, other, i, j));
	}
	i = -1;
	while (++i < 4 * 4)
		dst->m[i] = tmp.m[i];
	return (dst);
}
