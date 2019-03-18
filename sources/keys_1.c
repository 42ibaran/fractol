/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:09:53 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/18 12:59:15 by ibaran           ###   ########.fr       */
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
	exit(0);
}

void	f_key_iteration(int key, t_fractol *fractol)
{
	if (key == 69)
		ITER_RANGE++;
	else if (key == 78 && ITER_RANGE != 0)
		ITER_RANGE--;
	f_draw(fractol);
}

void	f_key_trans(int key, t_fractol *fractol)
{
	if (key == 123)
	{
		MIN_X -= STEP_X * 15;
		MAX_X -= STEP_X * 15;
	}
	if (key == 124)
	{
		MIN_X += STEP_X * 15;
		MAX_X += STEP_X * 15;
	}
	if (key == 125)
	{
		MIN_Y -= STEP_Y * 15;
		MAX_Y -= STEP_Y * 15;
	}
	if (key == 126)
	{
		MIN_Y += STEP_Y * 15;
		MAX_Y += STEP_Y * 15;
	}
	STEP_X = (MAX_X - MIN_X) / (float)IMAGE_X;
	STEP_Y = (MAX_Y - MIN_Y) / (float)IMAGE_Y;
	f_draw(fractol);
}

int		f_key_press(int key, t_fractol *fractol)
{
	if (key == 53)
		f_key_esc(key, fractol);
	if (key == 78 || key == 69)
		f_key_iteration(key, fractol);
	if (key >= 123 && key <= 126)
		f_key_trans(key, fractol);
	return (0);
}

int		f_key_release(int key, t_fractol *fractol)
{
	key = 0;
	fractol = 0;
	return (0);
}

int		f_mouse_press(int button, int x, int y, t_fractol *fractol)
{
//	float		x_rat;
//	float		y_rat;

	if (!(x >= (WINDOW_X - IMAGE_X) / 2 &&
			x <= WINDOW_X - (WINDOW_X - IMAGE_X) / 2 &&
			y >= (WINDOW_Y - IMAGE_Y) / 2 &&
			y <= WINDOW_Y - (WINDOW_Y - IMAGE_Y) / 2))
		return (0);

/*	x_rat = (float)x / (float)(IMAGE_X);
	y_rat = (float)y / (float)(IMAGE_Y);
	if (button == 5) //out
	{
		MAX_X /= ZOOM_NUM * x_rat;
		MAX_Y /= ZOOM_NUM * y_rat;
		MIN_X /= ZOOM_NUM * (1 - x_rat);
		MIN_Y /= ZOOM_NUM * (1 - y_rat);
	}
	if (button == 4) //in
	{
		MAX_X *= ZOOM_NUM * x_rat;
		MAX_Y *= ZOOM_NUM * y_rat;
		MIN_X *= ZOOM_NUM * (1 - x_rat);
		MIN_Y *= ZOOM_NUM * (1 - y_rat);
	}*/

	if (button == 5)
	{
		MIN_X /= ZOOM_NUM;
		MIN_Y /= ZOOM_NUM;
		MAX_X /= ZOOM_NUM;
		MAX_Y /= ZOOM_NUM;
	}
	if (button == 4)
	{
		MIN_X *= ZOOM_NUM;
		MIN_Y *= ZOOM_NUM;
		MAX_X *= ZOOM_NUM;
		MAX_Y *= ZOOM_NUM;
	}
	STEP_X = (MAX_X - MIN_X) / (float)IMAGE_X;
	STEP_Y = (MAX_Y - MIN_Y) / (float)IMAGE_Y;
	f_draw(fractol);
	return (0);
}

int		f_mouse_release(int button, int x, int y, t_fractol *fractol)
{
//	printf("mouse release: x = %d, y = %d, button = %d\n", x, y, button);
	x = 0;
	y = 0;
	button = 0;
	fractol = 0;
	return (0);
}

int		f_mouse_move(int x, int y, t_fractol *fractol)
{
	if (ft_strcmp(NAME, "Julia") != 0)
		return (0);
	MOUSE_PRE_X = MOUSE_CUR_X;
	MOUSE_PRE_Y = MOUSE_CUR_Y;
	MOUSE_CUR_X = x;
	MOUSE_CUR_Y = y;
	if (MOUSE_CUR_X >= (WINDOW_X - IMAGE_X) / 2 &&
		MOUSE_CUR_X <= WINDOW_X - (WINDOW_X - IMAGE_X) / 2 &&
		MOUSE_CUR_Y >= (WINDOW_Y - IMAGE_Y) / 2 &&
		MOUSE_CUR_Y <= WINDOW_Y - (WINDOW_Y - IMAGE_Y) / 2)
	{
		if (MOUSE_PRE_X != MOUSE_CUR_X)
			CR = 0.004 * (MOUSE_CUR_X - (IMAGE_X / 2) -
				(WINDOW_X - IMAGE_X) / 2);
		if (MOUSE_PRE_Y != MOUSE_CUR_Y)
			CI = 0.004 * (MOUSE_CUR_Y - (IMAGE_Y / 2) -
				(WINDOW_Y - IMAGE_Y) / 2);
		f_draw(fractol);
	}
	x = 0;
	y = 0;
	return (0);
}

int		f_expose(t_fractol *fractol)
{
	fractol = 0;
	return (0);
}
