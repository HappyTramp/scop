/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_mat4scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:16:19 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 11:18:38 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat4.h"

t_ftmmat4	*ftm_mat4scale(t_ftmmat4 *mat4, float x, float y, float z)
{
	t_ftmmat4	scale;

	ftm_mat4init_eye(&scale, 1.0);
	ftm_mat4set(&scale, 0, 0, x);
	ftm_mat4set(&scale, 1, 1, y);
	ftm_mat4set(&scale, 2, 2, z);
	ftm_mat4mul(mat4, &scale);
	return (mat4);
}
