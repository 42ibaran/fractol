/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:36:54 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/19 14:58:53 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <libc.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"

# define WINDOW_X 900
# define WINDOW_Y 900
# define IMAGE_X 900
# define IMAGE_Y 900
# define IMG_MID_X (IMAGE_X / 2)
# define IMG_MID_Y (IMAGE_Y / 2)
# define WIN_MID_X (WINDOW_X / 2)
# define WIN_MID_Y (WINDOW_Y / 2)
# define GOLD ((1 + sqrt(5.0)) / 2)
# define ZOOM_NUM 105
# define MIN_RANGE_XY 0.00000000001

# define MLX_PTR fractol->mlx_ptr
# define WIN_PTR fractol->win_ptr
# define IMG_PTR fractol->img_ptr
# define IMG_STR fractol->img_str

# define MATRIX fractol->matrix
# define NAME fractol->name
# define ITER_RANGE fractol->iter_range

# define MIN_X fractol->fract_min_x
# define MIN_Y fractol->fract_min_y
# define MAX_X fractol->fract_max_x
# define MAX_Y fractol->fract_max_y

# define STEP_X fractol->step_x
# define STEP_Y fractol->step_y

# define CR fractol->cr
# define CI fractol->ci

# define MOUSE_CUR_X fractol->mouse_current_x
# define MOUSE_CUR_Y fractol->mouse_current_y
# define MOUSE_PRE_X fractol->mouse_previous_x
# define MOUSE_PRE_Y fractol->mouse_previous_y

# define CR_STEP ((MAX_X - MIN_X) / IMAGE_X)
# define CI_STEP ((MAX_Y - MIN_Y) / IMAGE_Y)

# define COLOR_REF fractol->color_reference
# define COLOR_ALG fractol->color_algorithm
# define FIX_JULIA fractol->fix_julia_flag

typedef struct		s_point
{
	double			x;
	double			y;
	int				iter;
	unsigned int	color;
}					t_point;

typedef struct		s_fractol
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_str;
	t_point			**matrix;
	char			*name;
	int				iter_range;
	double			fract_min_x;
	double			fract_min_y;
	double			fract_max_x;
	double			fract_max_y;
	double			step_x;
	double			step_y;
	double			cr;
	double			ci;
	int				mouse_current_x;
	int				mouse_current_y;
	int				mouse_previous_x;
	int				mouse_previous_y;
	unsigned int	color_reference;
	char			fix_julia_flag;
	char			color_algorithm;
}					t_fractol;

typedef struct		s_thread
{
	pthread_t		thread_id;
	t_fractol		*fractol;
	int				i;
	int				j;
	double			x;
	double			y;
	int				(*function)(t_fractol*, int ,int);
}					t_thread;

/*
** Helpers
*/
int					f_error(t_fractol *fractol);
size_t				f_initialize(t_fractol *fractol, char *input);
size_t				f_check(int ac, char **av);
size_t				f_mouse_in_window(int x, int y);
void				f_welcome(void);

/*
** Keys
*/
int					f_key_press(int key, t_fractol *fractol);
int					f_mouse_press(int button, int x, int y, t_fractol *fractol);
int					f_mouse_move(int x, int y, t_fractol *fractol);

/*
** Allocation
*/
t_point				**f_allocate_points(int x, int y);
void				f_free_points(t_fractol *fractol);

/*
** Drawing
*/
size_t				f_draw(t_fractol *fractol);

/*
** Calculation
*/
int					f_mandelbrot(t_fractol *fractol, int i, int j);
int					f_julia(t_fractol *fractol, int i, int j);
int					f_burning_ship(t_fractol *fractol, int i, int j);
int					f_newton(t_fractol *fractol, int i, int j);

/*
** Change params
*/
void				f_key_esc(int key, t_fractol *fractol);
void				f_key_iteration(int key, t_fractol *fractol);
void				f_key_trans(int key, t_fractol *fractol);
void				f_key_color_ref(int key, t_fractol *fractol);
void				f_key_color_alg(int key, t_fractol *fractol);

#endif
