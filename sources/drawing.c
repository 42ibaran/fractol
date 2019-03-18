/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:42:19 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/15 18:33:59 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "fractol.h"

void		*f_xloop(void *ptr)
{
	int			i;
	int			j;
	float		x;
	float		y;
	t_fractol	*fractol;
	t_thread	*thread;

	thread = (t_thread*)ptr;
	fractol = thread->fractol;
	y = thread->y;
	i = thread->i;
	x = MIN_X;
	j = 0;
	while (j < IMAGE_X)
	{
		MATRIX[i][j].x = x;
		MATRIX[i][j].y = y;
		MATRIX[i][j].iter = thread->function(fractol, i, j);
		x += STEP_X;
		j++;
	}
	return (NULL);
}

size_t		f_fill_matrix(t_fractol *fractol, int function())
{
	float		y;
	int			i;
	t_thread	thread_y[IMAGE_Y];

	i = 0;
	y = MIN_Y;
	while (i < IMAGE_Y)
	{
		thread_y[i].fractol = fractol;
		thread_y[i].function = function;
		thread_y[i].i = i;
		thread_y[i].y = y;
		pthread_create(&(thread_y[i].thread_id), NULL, f_xloop, &(thread_y[i]));
		y += STEP_Y;
		i++;
	}
	i = 0;
	while (i < IMAGE_Y)
	{
		pthread_join(thread_y[i].thread_id, NULL);
		i++;
	}
	return (0);
}

void		f_fill_image(t_fractol *fractol)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (i < IMAGE_Y)
	{
		j = 0;
		while (j < IMAGE_X)
		{
			IMG_STR[k + 0] = (char)(MATRIX[i][j].color % 256 % 256);
			IMG_STR[k + 1] = (char)(MATRIX[i][j].color / 256 % 256);
			IMG_STR[k + 2] = (char)(MATRIX[i][j].color / 256 / 256);
			IMG_STR[k + 3] = 0;
			k += 4;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR,
		(WINDOW_X - IMAGE_X) / 2, (WINDOW_Y - IMAGE_Y) / 2);
}

size_t		f_draw(t_fractol *fractol)
{
	if (ft_strcmp(fractol->name, "Mandelbrot") == 0)
		f_fill_matrix(fractol, &f_mandelbrot);
	if (ft_strcmp(fractol->name, "Julia") == 0)
		f_fill_matrix(fractol, &f_julia);
	if (ft_strcmp(fractol->name, "BurningShip") == 0)
		f_fill_matrix(fractol, &f_burning_ship);
/*	if (ft_strcmp(fractol->name, "Mandelbrot") == 0)
		f_draw_mandelbrot(fractol);
	if (ft_strcmp(fractol->name, "Mandelbrot") == 0)
		f_draw_mandelbrot(fractol);*/
//	f_fill_image(fractol);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR,
	(WINDOW_X - IMAGE_X) / 2, (WINDOW_Y - IMAGE_Y) / 2);
	return (0);
}

	/*	x = MIN_X;
		j = 0;
		while (j < IMAGE_X)
		{
			MATRIX[i][j].x = x;
			MATRIX[i][j].y = y;
			thread[i].fractol = fractol;
			thread[i].i = i;
			thread[i].j = j;
			thread[i].x = x;
			thread[i].y = y;
//			thread[i].fun = function;
			pthread_create(&(thread[i].thread_id), NULL, blabla, &thread[i]);
		//	wait(NULL);
			pthread_join(thread[i].thread_id, NULL);
//			MATRIX[i][j].iter = function(fractol, i, j);
			x += STEP_X;
			j++;
		}*/
