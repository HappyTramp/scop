/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_matmulvec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:56:00 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 13:18:10 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftm_mat.h"

t_ftmvec	*ftm_matmulvec(t_ftmmat *mat, t_ftmvec *dst)
{
	size_t		i;
	t_ftmmat	*tmp;

	if ((tmp = ftm_matnew(dst->size, 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < dst->size)
	{
		tmp->m[i] = dst->v[i];
		i++;
	}
	if (ftm_matmul(tmp, mat) == NULL)
		return (NULL);
	i = 0;
	while (i < dst->size)
	{
		dst->v[i] = tmp->m[i];
		i++;
	}
	return (dst);
}
