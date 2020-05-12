/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_mat4set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:21:20 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 11:21:58 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat4.h"

t_ftmmat4	*ftm_mat4set(t_ftmmat4 *mat4, size_t y, size_t x, float value)
{
	mat4->m[y * 4 + x] = value;
	return (mat4);
}
