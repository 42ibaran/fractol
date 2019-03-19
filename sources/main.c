/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:16:14 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/19 15:20:16 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char *av[])
{
	t_fractol	*fractol;
	int			bpp;
	int			s_l;
	int			endian;

	fractol = NULL;
	if (!(fractol = (t_fractol*)malloc(sizeof(t_fractol))) ||
			f_check(ac, av) == 1)
		return (f_error(fractol));
	NAME = NULL;
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, WINDOW_X, WINDOW_Y, "fractol");
	IMG_PTR = mlx_new_image(MLX_PTR, IMAGE_X, IMAGE_Y);
	IMG_STR = mlx_get_data_addr(IMG_PTR, &bpp, &s_l, &endian);
	if (f_initialize(fractol, av[1]) == 1)
		return (f_error(fractol));
	f_welcome();
	f_draw(fractol);
	mlx_hook(WIN_PTR, 2, 0, &f_key_press, fractol);
	mlx_hook(WIN_PTR, 4, 0, &f_mouse_press, fractol);
	mlx_hook(WIN_PTR, 6, 0, &f_mouse_move, fractol);
	mlx_loop(MLX_PTR);
	return (0);
}
