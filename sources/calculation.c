/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:05:05 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/18 17:42:41 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			f_mandelbrot(t_fractol *fractol, int i, int j)
{
	double		x;
	double		y;
	double		x_temp;
	int			iter;

	iter = 0;
	x = pow(MATRIX[i][j].x, 2) - pow(MATRIX[i][j].y, 2) + MATRIX[i][j].x;
	y = 2 * MATRIX[i][j].x * MATRIX[i][j].y + MATRIX[i][j].y;
	IMG_STR[(i * IMAGE_X + j) * 4 + 0] = 0;
	IMG_STR[(i * IMAGE_X + j) * 4 + 1] = 0;
	IMG_STR[(i * IMAGE_X + j) * 4 + 2] = 0;
	IMG_STR[(i * IMAGE_X + j) * 4 + 3] = 0;
	while (iter < ITER_RANGE)
	{
		x_temp = pow(x, 2) - pow(y, 2) + MATRIX[i][j].x;
		y = 2 * x * y + MATRIX[i][j].y;
		x = x_temp;
		if (pow(x, 2) + pow(y, 2) > 4.0)
		{
			MATRIX[i][j].color = 0x000000 - iter * (COLOR_REF);
			IMG_STR[(i * IMAGE_X + j) * 4 + 0] = (char)(MATRIX[i][j].color % 256 % 256);
			IMG_STR[(i * IMAGE_X + j) * 4 + 1] = (char)(MATRIX[i][j].color / 256 % 256);
			IMG_STR[(i * IMAGE_X + j) * 4 + 2] = (char)(MATRIX[i][j].color / 256 / 256);
			IMG_STR[(i * IMAGE_X + j) * 4 + 3] = 0;
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
	IMG_STR[(i * IMAGE_X + j) * 4 + 0] = 0;
	IMG_STR[(i * IMAGE_X + j) * 4 + 1] = 0;
	IMG_STR[(i * IMAGE_X + j) * 4 + 2] = 0;
	IMG_STR[(i * IMAGE_X + j) * 4 + 3] = 0;
	while (iter < ITER_RANGE)
	{
		x_temp = pow(x, 2) - pow(y, 2) + CR;
		y = 2 * x * y + CI;
		x = x_temp;
		if (pow(x, 2) + pow(y, 2) > 4.0)
		{
			MATRIX[i][j].color = 0x000002 - (5.0 * sqrt(pow(x, 2) + pow(y, 2))) * (COLOR_REF);
			IMG_STR[(i * IMAGE_X + j) * 4 + 0] = (char)(MATRIX[i][j].color % 256 % 256);
			IMG_STR[(i * IMAGE_X + j) * 4 + 1] = (char)(MATRIX[i][j].color / 256 % 256);
			IMG_STR[(i * IMAGE_X + j) * 4 + 2] = (char)(MATRIX[i][j].color / 256 / 256);
			IMG_STR[(i * IMAGE_X + j) * 4 + 3] = 0;
			return (iter);
		}
		iter++;
	}
	return (iter);
}

int		f_burning_ship(t_fractol *fractol, int i, int j)
{
	double		x;
	double		y;
	double		x_temp;
	int			iter;

	iter = 0;
	x = pow(MATRIX[i][j].x, 2) - pow(MATRIX[i][j].y, 2) + MATRIX[i][j].x;
	y = fabs(2 * MATRIX[i][j].x * MATRIX[i][j].y) + MATRIX[i][j].y;
	IMG_STR[(i * IMAGE_X + j) * 4 + 0] = 0;
	IMG_STR[(i * IMAGE_X + j) * 4 + 1] = 0;
	IMG_STR[(i * IMAGE_X + j) * 4 + 2] = 0;
	IMG_STR[(i * IMAGE_X + j) * 4 + 3] = 0;
	while (iter < ITER_RANGE)
	{
		x_temp = fabs(pow(x, 2) - pow(y, 2) + MATRIX[i][j].x);
		y = fabs(2 * x * y) + MATRIX[i][j].y;
		x = x_temp;
		if (pow(x, 2) + pow(y, 2) > 4.0)
		{
			MATRIX[i][j].color = 0x000000 - iter * (COLOR_REF);
			IMG_STR[(i * IMAGE_X + j) * 4 + 0] = (char)(MATRIX[i][j].color % 256 % 256);
			IMG_STR[(i * IMAGE_X + j) * 4 + 1] = (char)(MATRIX[i][j].color / 256 % 256);
			IMG_STR[(i * IMAGE_X + j) * 4 + 2] = (char)(MATRIX[i][j].color / 256 / 256);
			IMG_STR[(i * IMAGE_X + j) * 4 + 3] = 0;
			return (iter);
		}
		iter++;
	}
	return (iter);
}

int			f_newton(t_fractol *fractol, int i, int j)
{
	double		x;
	double		y;
	double		x_temp;
	int			iter;

	iter = 0;
	x = pow(MATRIX[i][j].x, 2) - pow(MATRIX[i][j].y, 2) + CR;
	y = 2 * MATRIX[i][j].x * MATRIX[i][j].y + CI;
	IMG_STR[(i * IMAGE_X + j) * 4 + 0] = 0;
	IMG_STR[(i * IMAGE_X + j) * 4 + 1] = 0;
	IMG_STR[(i * IMAGE_X + j) * 4 + 2] = 0;
	IMG_STR[(i * IMAGE_X + j) * 4 + 3] = 0;
	while (iter < ITER_RANGE)
	{
		x_temp = pow(x, 2) - pow(y, 2) + CR;
		y = 2 * x * y + CI;
		x = x_temp;
		if (pow(x, 2) + pow(y, 2) > 4.0)
		{
			MATRIX[i][j].color = 0x000000 - iter * (COLOR_REF);
			IMG_STR[(i * IMAGE_X + j) * 4 + 0] = (char)(MATRIX[i][j].color % 256 % 256);
			IMG_STR[(i * IMAGE_X + j) * 4 + 1] = (char)(MATRIX[i][j].color / 256 % 256);
			IMG_STR[(i * IMAGE_X + j) * 4 + 2] = (char)(MATRIX[i][j].color / 256 / 256);
			IMG_STR[(i * IMAGE_X + j) * 4 + 3] = 0;
			return (iter);
		}
		iter++;
	}
	return (iter);
}
