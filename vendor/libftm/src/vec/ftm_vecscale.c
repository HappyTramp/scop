/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_vecscale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:41:11 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 12:48:43 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec.h"

t_ftmvec	*ftm_vecscale(t_ftmvec *dst, float scalar)
{
	size_t	i;

	i = 0;
	while (i < dst->size)
	{
		dst->v[i] *= scalar;
		i++;
	}
	return (dst);
}
