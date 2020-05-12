/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_mat4translate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:12:21 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 11:19:05 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat4.h"

t_ftmmat4	*ftm_mat4translate(t_ftmmat4 *mat4, float x, float y, float z)
{
	t_ftmmat4	trans;

	ftm_mat4init_eye(&trans, 1.0);
	ftm_mat4set(&trans, 0, 3, x);
	ftm_mat4set(&trans, 1, 3, y);
	ftm_mat4set(&trans, 2, 3, z);
	ftm_mat4mul(mat4, &trans);
	return (mat4);
}
