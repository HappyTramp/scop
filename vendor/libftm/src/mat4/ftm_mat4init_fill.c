/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_mat4init_fill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:16:59 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 12:18:01 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat4.h"

t_ftmmat4	*ftm_mat4init_fill(t_ftmmat4 *mat4, float x)
{
	size_t	i;

	i = 0;
	while (i < 4 * 4)
	{
		mat4->m[i] = x;
		i++;
	}
	return (mat4);
}
