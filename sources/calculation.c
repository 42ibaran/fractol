/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:05:05 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/19 16:40:09 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		f_set_color(t_fractol *fractol, int i, int j, double z)
{
	if (COLOR_ALG == 'i')
	{
		MATRIX[i][j].color = 0x000000 - COLOR_REF * (MATRIX[i][j].iter);
		IMG_STR[(i * IMAGE_X + j) * 4 + 0] =
			(char)(MATRIX[i][j].color % 256 % 256);
		IMG_STR[(i * IMAGE_X + j) * 4 + 1] =
			(char)(MATRIX[i][j].color / 256 % 256);
		IMG_STR[(i * IMAGE_X + j) * 4 + 2] =
			(char)(MATRIX[i][j].color / 256 / 256);
		IMG_STR[(i * IMAGE_X + j) * 4 + 3] = 0;
	}
	else
	{
		MATRIX[i][j].color = 0x000000 - COLOR_REF *
			(int)((double)MATRIX[i][j].iter + sqrt(z));
		IMG_STR[(i * IMAGE_X + j) * 4 + 0] =
			(char)(MATRIX[i][j].color % 256 % 256);
		IMG_STR[(i * IMAGE_X + j) * 4 + 1] =
			(char)(MATRIX[i][j].color / 256 % 256);
		IMG_STR[(i * IMAGE_X + j) * 4 + 2] =
			(char)(MATRIX[i][j].color / 256 / 256);
		IMG_STR[(i * IMAGE_X + j) * 4 + 3] = 0;
	}
}

int			f_mandelbrot(t_fractol *fractol, int i, int j)
{
	double		x;
	double		y;
	double		x_temp;
	int			iter;

	iter = 0;
	x = pow(MATRIX[i][j].x, 2) - pow(MATRIX[i][j].y, 2) + MATRIX[i][j].x;
	y = 2 * MATRIX[i][j].x * MATRIX[i][j].y + MATRIX[i][j].y;
	MATRIX[i][j].iter = iter;
	f_set_color(fractol, i, j, pow(x, 2) + pow(y, 2));
	while (iter < ITER_RANGE)
	{
		x_temp = pow(x, 2) - pow(y, 2) + MATRIX[i][j].x;
		y = 2 * x * y + MATRIX[i][j].y;
		x = x_temp;
		if (pow(x, 2) + pow(y, 2) > 4.0)
		{
			MATRIX[i][j].iter = iter;
			f_set_color(fractol, i, j, pow(x, 2) + pow(y, 2));
			return (iter);
		}
		iter++;
	}
	return (iter);
}

int			f_julia(t_fractol *fractol, int i, int j)
{
	double		x;
	double		y;
	double		x_temp;
	int			iter;

	iter = 0;
	x = pow(MATRIX[i][j].x, 2) - pow(MATRIX[i][j].y, 2) + CR;
	y = 2 * MATRIX[i][j].x * MATRIX[i][j].y + CI;
	MATRIX[i][j].iter = iter;
	f_set_color(fractol, i, j, pow(x, 2) + pow(y, 2));
	while (iter < ITER_RANGE)
	{
		x_temp = pow(x, 2) - pow(y, 2) + CR;
		y = 2 * x * y + CI;
		x = x_temp;
		if (pow(x, 2) + pow(y, 2) > 4.0)
		{
			MATRIX[i][j].iter = iter;
			f_set_color(fractol, i, j, pow(x, 2) + pow(y, 2));
			return (iter);
		}
		iter++;
	}
	return (iter);
}

int			f_burning_ship(t_fractol *fractol, int i, int j)
{
	double		x;
	double		y;
	double		x_temp;
	int			iter;

	iter = 0;
	x = pow(MATRIX[i][j].x, 2) - pow(MATRIX[i][j].y, 2) + MATRIX[i][j].x;
	y = fabs(2 * MATRIX[i][j].x * MATRIX[i][j].y) + MATRIX[i][j].y;
	MATRIX[i][j].iter = iter;
	f_set_color(fractol, i, j, pow(x, 2) + pow(y, 2));
	while (iter < ITER_RANGE)
	{
		x_temp = fabs(pow(x, 2) - pow(y, 2) + MATRIX[i][j].x);
		y = fabs(2 * x * y) + MATRIX[i][j].y;
		x = x_temp;
		if (pow(x, 2) + pow(y, 2) > 4.0)
		{
			MATRIX[i][j].iter = iter;
			f_set_color(fractol, i, j, pow(x, 2) + pow(y, 2));
			return (iter);
		}
		iter++;
	}
	return (iter);
}
