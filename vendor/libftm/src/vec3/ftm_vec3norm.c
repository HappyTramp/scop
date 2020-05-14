/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_vec3norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 18:04:25 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 18:05:14 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_vec3.h"

float		ftm_vec3norm(t_ftmvec3 *vec3)
{
	return (sqrt(vec3->x * vec3->x + vec3->y * vec3->y + vec3->z * vec3->z));
}
