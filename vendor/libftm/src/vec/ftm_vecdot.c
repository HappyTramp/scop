/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_vecdot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 21:06:09 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 12:48:12 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec.h"

float		ftm_vecdot(t_ftmvec *a, t_ftmvec *b)
{
	size_t	i;
	float	total;

	if (a->size != b->size)
		return (0.0);
	total = 0.0;
	i = 0;
	while (i < a->size)
	{
		total += a->v[i] * b->v[i];
		i++;
	}
	return (total);
}
