/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_mat4init_frustum_sym.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:47:45 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 17:21:06 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat4.h"

t_ftmmat4	*ftm_mat4init_frustum_sym(t_ftmmat4 *mat4, t_ftmfrustum_sym *frustum)
{
	t_ftmfrustum	f;

	f.right = frustum->width / 2;
	f.left = -f.right;
	f.top = frustum->height / 2;
	f.bottom = -f.top;
	f.near = frustum->near;
	f.far = frustum->far;
	return (ftm_mat4init_frustum(mat4, &f));
}
