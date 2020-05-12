/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_mat4get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 13:54:08 by charles           #+#    #+#             */
/*   Updated: 2020/05/12 13:54:09 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat4.h"

float		ftm_mat4get(t_ftmmat4 *mat4, size_t y, size_t x)
{
	return (mat4->m[y * 4 + x]);
}
