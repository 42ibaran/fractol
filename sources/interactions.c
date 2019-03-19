/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:32:36 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/19 16:19:44 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		f_key_press(int key, t_fractol *fractol)
{
	if (key == 53)
		f_key_esc(key, fractol);
	if (key == 78 || key == 69)
		f_key_iteration(key, fractol);
	if (key >= 123 && key <= 126)
		f_key_trans(key, fractol);
	if (key == 49)
		FIX_JULIA = (FIX_JULIA == 'n' ? 'y' : 'n');
	if (key == 48)
		f_key_color_ref(key, fractol);
	if (key == 8)
		f_key_color_alg(key, fractol);
	if (key == 36)
		f_initialize(fractol, NAME);
	f_draw(fractol);
	return (0);
}

int		f_mouse_press(int button, int x, int y, t_fractol *fractol)
{
	double		x_rat;
	double		y_rat;

	x_rat = (double)x / (double)(IMAGE_X);
	y_rat = (double)y / (double)(IMAGE_Y);
	if (button == 5 && f_mouse_in_window(x, y) == 0 &&
			MAX_X - MIN_X > MIN_RANGE_XY && MAX_Y - MIN_Y > MIN_RANGE_XY)
	{
		MIN_X += ZOOM_NUM * STEP_X * x_rat;
		MAX_X -= ZOOM_NUM * STEP_X * (1 - x_rat);
		MIN_Y += ZOOM_NUM * STEP_Y * (y_rat);
		MAX_Y -= ZOOM_NUM * STEP_Y * (1 - y_rat);
	}
	if (button == 4 && MAX_X - MIN_X < 4.3 && MAX_Y - MIN_Y < 4.3 &&
			f_mouse_in_window(x, y) == 0)
	{
		MIN_X -= ZOOM_NUM * STEP_X * x_rat;
		MAX_X += ZOOM_NUM * STEP_X * (1 - x_rat);
		MIN_Y -= ZOOM_NUM * STEP_Y * (y_rat);
		MAX_Y += ZOOM_NUM * STEP_Y * (1 - y_rat);
	}
	STEP_X = (MAX_X - MIN_X) / (double)IMAGE_X;
	STEP_Y = (MAX_Y - MIN_Y) / (double)IMAGE_Y;
	f_draw(fractol);
	return (0);
}

int		f_mouse_move(int x, int y, t_fractol *fractol)
{
	if (ft_strcmp(NAME, "Julia") != 0 || FIX_JULIA == 'y')
		return (0);
	MOUSE_PRE_X = MOUSE_CUR_X;
	MOUSE_PRE_Y = MOUSE_CUR_Y;
	MOUSE_CUR_X = x;
	MOUSE_CUR_Y = y;
	if (f_mouse_in_window(x, y) == 0)
	{
		if (MOUSE_PRE_X != MOUSE_CUR_X)
			CR = STEP_X * (double)(MOUSE_CUR_X - (IMAGE_X / 2));
		if (MOUSE_PRE_Y != MOUSE_CUR_Y)
			CI = STEP_Y * (double)(MOUSE_CUR_Y - (IMAGE_Y / 2));
		f_draw(fractol);
	}
	return (0);
}
