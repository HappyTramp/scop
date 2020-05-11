/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_matat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 13:11:34 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 13:27:17 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat.h"

float		ftm_matat(t_ftmmat *mat, size_t y, size_t x)
{
	return (mat->m[y * mat->shape.x + x]);
}
