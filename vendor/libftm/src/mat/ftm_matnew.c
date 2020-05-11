/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_matnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:56:00 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 13:13:27 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat.h"

t_ftmmat	*ftm_matnew(size_t y, size_t x)
{
	t_ftmmat	*mat;

	if ((mat = malloc(sizeof(t_ftmmat))) == NULL)
		return (NULL);
	if ((mat->m = malloc(sizeof(float) * x * y)) == NULL)
	{
		free(mat);
		return (NULL);
	}
	mat->shape.y = y;
	mat->shape.x = x;
	return (mat);
}
