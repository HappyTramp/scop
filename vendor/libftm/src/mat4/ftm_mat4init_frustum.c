/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_mat4init_frustum.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:37:26 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 17:29:53 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat4.h"

t_ftmmat4	*ftm_mat4init_frustum(t_ftmmat4 *mat4, t_ftmfrustum *frustum)
{
	ftm_mat4init_fill(mat4, 0.0);

	ftm_mat4set(mat4, 0, 0, (2.0 * frustum->near) / (frustum->right - frustum->left));
	ftm_mat4set(mat4, 1, 1, (2.0 * frustum->near) / (frustum->top - frustum->bottom));
	ftm_mat4set(mat4, 2, 2, (-(frustum->far + frustum->near)) / (frustum->far - frustum->near));
	ftm_mat4set(mat4, 0, 2, (frustum->right + frustum->left) / (frustum->right - frustum->left));
	ftm_mat4set(mat4, 1, 2, (frustum->top + frustum->bottom) / (frustum->top - frustum->bottom));
	ftm_mat4set(mat4, 2, 3, (-2.0 * frustum->far * frustum->near) / (frustum->far - frustum->near));
	ftm_mat4set(mat4, 3, 2, -1.0);
	return (mat4);
}
