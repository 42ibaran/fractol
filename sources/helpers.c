/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:10:25 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/19 15:32:30 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			f_error(t_fractol *fractol)
{
	if (fractol != NULL)
		free(fractol);
	ft_printf("error occured\n");
	ft_printf("note: ussage: fractol <type>\n");
	ft_printf("available types:\n");
	ft_printf("  - Mandelbrot\n");
	ft_printf("  - Julia\n");
	ft_printf("  - BurningShip\n");
	return (1);
}

size_t		f_initialize(t_fractol *fractol, char *input)
{
	if (NAME == NULL)
		if (!(fractol->matrix = f_allocate_points(IMAGE_X, IMAGE_Y)))
			return (1);
	fractol->name = input;
	MIN_X = -2.0;
	MAX_X = 2.0;
	MIN_Y = -2.0;
	MAX_Y = 2.0;
	STEP_X = (MAX_X - MIN_X) / (double)IMAGE_X;
	STEP_Y = (MAX_Y - MIN_Y) / (double)IMAGE_Y;
	CR = GOLD - 2;
	CI = GOLD - 1;
	MOUSE_CUR_X = 0;
	MOUSE_CUR_Y = 0;
	MOUSE_PRE_X = 0;
	MOUSE_PRE_Y = 0;
	ITER_RANGE = 50;
	COLOR_REF = 0xEEFFDD;
	FIX_JULIA = 'y';
	COLOR_ALG = 'i';
	return (0);
}

size_t		f_check(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (ft_strcmp(av[1], "Julia") != 0 &&
			ft_strcmp(av[1], "Mandelbrot") != 0 &&
			ft_strcmp(av[1], "BurningShip") != 0)
		return (1);
	return (0);
}

size_t		f_mouse_in_window(int x, int y)
{
	if (!(x >= (WINDOW_X - IMAGE_X) / 2 &&
			x <= WINDOW_X - (WINDOW_X - IMAGE_X) / 2 &&
			y >= (WINDOW_Y - IMAGE_Y) / 2 &&
			y <= WINDOW_Y - (WINDOW_Y - IMAGE_Y) / 2))
		return (1);
	return (0);
}

void		f_welcome(void)
{
	ft_printf("Hello and welcome to Fract'ol\n\n");
	ft_printf("INSTRUCTIONS:\n");
	ft_printf("   - Use mouse wheel to zoom in and out\n");
	ft_printf("   - Use arrows to move around\n");
	ft_printf("   - Press 'Tab' to change color set\n");
	ft_printf("   - Press 'C' to change coloring algorithm\n");
	ft_printf("   - Press '+' or '-' to change the maximum iteration\n");
	ft_printf("   - Press 'Space' to fix Julia's parameters\n");
	ft_printf("   - Press 'Return' to return to default settings\n");
	ft_printf("   - Press 'ESC' to exit\n\n");
}
