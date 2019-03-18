/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:18:59 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/15 12:44:30 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point		**f_allocate_points(int x, int y)
{
	t_point		**out;
	int			i;

	if (!(out = (t_point**)malloc(sizeof(t_point*) * (y + 1))))
		return (NULL);
	i = 0;
	while (i < y)
	{
		if (!(out[i] = (t_point*)malloc(sizeof(t_point) * x)))
			return (NULL);
		i++;
	}
	out[y] = NULL;
	return (out);
}

void		f_free_points(t_fractol *fractol)
{
	int		i;

	i = 0;
	while (MATRIX[i])
	{
		free(MATRIX[i]);
		i++;
	}
	free(MATRIX);
}
