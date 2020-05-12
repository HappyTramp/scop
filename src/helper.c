/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:55:27 by charles           #+#    #+#             */
/*   Updated: 2020/05/11 14:57:29 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

bool			has_extension(char *filepath, char *extension)
{
	char	*match;

	match = ft_strstr(filepath, extension);
	return (match != NULL && ft_strlen(match) == ft_strlen(extension));
}
