/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:27:50 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/19 16:01:05 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	f_key_esc(int key, t_fractol *fractol)
{
	key = 0;
	mlx_destroy_image(MLX_PTR, IMG_PTR);
	mlx_clear_window(MLX_PTR, WIN_PTR);
	mlx_destroy_window(MLX_PTR, WIN_PTR);
	f_free_points(fractol);
	ft_printf("Good bye and have a good day!\n");
	exit(0);
}

void	f_key_iteration(int key, t_fractol *fractol)
{
	if (key == 69)
		ITER_RANGE++;
	else if (key == 78 && ITER_RANGE != 0)
		ITER_RANGE--;
}

void	f_key_trans(int key, t_fractol *fractol)
{
	if (key == 123 && MAX_X >= -2.0)
	{
		MIN_X -= STEP_X * 15;
		MAX_X -= STEP_X * 15;
	}
	if (key == 124 && MIN_X <= 2.0)
	{
		MIN_X += STEP_X * 15;
		MAX_X += STEP_X * 15;
	}
	if (key == 125 && MAX_Y >= -2.0)
	{
		MIN_Y -= STEP_Y * 15;
		MAX_Y -= STEP_Y * 15;
	}
	if (key == 126 && MIN_Y <= 2.0)
	{
		MIN_Y += STEP_Y * 15;
		MAX_Y += STEP_Y * 15;
	}
	STEP_X = (MAX_X - MIN_X) / (double)IMAGE_X;
	STEP_Y = (MAX_Y - MIN_Y) / (double)IMAGE_Y;
}

void	f_key_color_ref(int key, t_fractol *fractol)
{
	key = 0;
	if (COLOR_REF == 0xEEFFDD)
		COLOR_REF = 0xFFEEDD;
	else if (COLOR_REF == 0xFFEEDD)
		COLOR_REF = 0xFFDDEE;
	else if (COLOR_REF == 0xFFDDEE)
		COLOR_REF = 0xDDFFEE;
	else if (COLOR_REF == 0xDDFFEE)
		COLOR_REF = 0xEEDDFF;
	else if (COLOR_REF == 0xEEDDFF)
		COLOR_REF = 0xEEFFDD;
}

void	f_key_color_alg(int key, t_fractol *fractol)
{
	key = 0;
	COLOR_ALG = (COLOR_ALG == 'i' ? 'x' : 'i');
}
