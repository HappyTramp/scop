/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_mat4init_eye.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:10:44 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 12:17:21 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat4.h"

t_ftmmat4	*ftm_mat4init_eye(t_ftmmat4 *mat4, float x)
{
	ftm_mat4init_fill(mat4, 0.0);
	ftm_mat4set(mat4, 0, 0, x);
	ftm_mat4set(mat4, 1, 1, x);
	ftm_mat4set(mat4, 2, 2, x);
	ftm_mat4set(mat4, 3, 3, x);
	return (mat4);
}
