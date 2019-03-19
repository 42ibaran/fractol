/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:42:19 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/19 14:17:53 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "fractol.h"

void		*f_xloop(void *ptr)
{
	t_fractol	*fractol;
	t_thread	*thread;

	thread = (t_thread*)ptr;
	fractol = thread->fractol;
	thread->x = MIN_X;
	thread->j = 0;
	while (thread->j < IMAGE_X)
	{
		MATRIX[thread->i][thread->j].x = thread->x;
		MATRIX[thread->i][thread->j].y = thread->y;
		MATRIX[thread->i][thread->j].iter =
			thread->function(fractol, thread->i, thread->j);
		thread->x += STEP_X;
		thread->j++;
	}
	return (NULL);
}

size_t		f_fill_matrix(t_fractol *fractol, int function())
{
	double		y;
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

size_t		f_draw(t_fractol *fractol)
{
	if (ft_strcmp(fractol->name, "Mandelbrot") == 0)
		f_fill_matrix(fractol, &f_mandelbrot);
	if (ft_strcmp(fractol->name, "Julia") == 0)
		f_fill_matrix(fractol, &f_julia);
	if (ft_strcmp(fractol->name, "BurningShip") == 0)
		f_fill_matrix(fractol, &f_burning_ship);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR,
	(WINDOW_X - IMAGE_X) / 2, (WINDOW_Y - IMAGE_Y) / 2);
	return (0);
}
