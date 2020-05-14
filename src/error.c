/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:43:45 by charles           #+#    #+#             */
/*   Updated: 2020/05/14 16:40:27 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	error_clear(void)
{
	while (glGetError() != GL_NO_ERROR)
		;
}

void	error_check(char *code, char *filename, int line_num)
{
	GLenum	err;
	bool	occured;

	occured = false;
	while ((err = glGetError()) != GL_NO_ERROR)
	{
		ft_putstr("[ERROR opengl] (");
		ft_putnbr(err);
		if (err == GL_INVALID_OPERATION)
		{
			ft_putchar(' ');
			ft_putstr("GL_INVALID_OPERATION");
		}
		else if (err == GL_INVALID_VALUE)
		{
			ft_putchar(' ');
			ft_putstr("GL_INVALID_VALUE");
		}
		else if (err == GL_INVALID_ENUM)
		{
			ft_putchar(' ');
			ft_putstr("GL_INVALID_ENUM");
		}
		ft_putstr(") ");
		ft_putstr(code);
		ft_putstr(" at ");
		ft_putstr(filename);
		ft_putchar(':');
		ft_putnbr(line_num);
		ft_putchar('\n');
		occured = true;
	}
	if (occured)
		exit(EXIT_FAILURE);
}
