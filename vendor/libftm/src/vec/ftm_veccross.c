/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_veccross.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 21:20:41 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 12:43:33 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec.h"

/*
** s1 = a2 * b - a * b2
** s2 = a * b1 - a1 * b
** s = a1 * b2 - a2 * b1
*/

t_ftmvec	*ftm_veccross(t_ftmvec *a, t_ftmvec *b)
{
	t_ftmvec	*dst;

	if (a->size != 3 || b->size != 3)
		return (NULL);
	if ((dst = ftm_vecnew(3)) == NULL)
		return (NULL);
	dst->v[0] = a->v[1] * b->v[2] - a->v[2] * b->v[1];
	dst->v[1] = a->v[2] * b->v[0] - a->v[0] * b->v[2];
	dst->v[2] = a->v[0] * b->v[1] - a->v[1] * b->v[0];
	return (dst);
}
