/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:09:00 by jkosiara          #+#    #+#             */
/*   Updated: 2021/05/26 12:54:01 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H


# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include <math.h>

# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define CELL_SIZE 30
# define WINDOW_WIDTH maps->mapx * CELL_SIZE
# define WINDOW_HEIGHT maps->mapy * CELL_SIZE
# define NUM_ROWS maps->mapy
# define NUM_COLS maps->mapx
# define NUM_RAYS WINDOW_WIDTH
# define MINIMAPS_SCALE 0.5
# define SPEED = 15;

typedef struct  s_vars 
{
    void    *mlx;
    void    *win;
}               t_vars;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct			s_image
{
	int					width;
	int					height;
	int					size_line;
	int					bpp;
	int					endian;
	void				*img_ptr;
	char				*data;
}						t_image;


typedef struct s_maps
{
    int		resx;
	int		resy;
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	char	*S;
	int		mapx;
	int		mapy;
	char 	**mtx;
	int		F;
	int		C;
	int		red;
	int		green;
	int		blue;
}              t_maps;

typedef struct			s_line
{
	int					x;
	int					y;
	int					y0;
	int					y1;
	int					tex_x;
	int					tex_y;
}						t_line;

typedef struct s_err
{
	int n;
	int m;
}	t_err;

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }				t_list;

 typedef struct s_player
 {
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		raydirX;						//raggio laser
	double		raydirY;
	int			width;
	int			height;
	double		rot_angle;
	double		cameraX;
	int			b_mapX;
	int			b_mapY;
	double		side_distX;
	double		side_distY;
	double		mov_speed;
	double		delta_distX;
	double		delta_distY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int         pix;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		cam_height;
	double		*z_buffer;
	double		px;
	double		py;
}				t_player;

typedef struct s_all{
	t_vars		vars;
	t_maps		maps; 								// mancano i nomi
	t_player	player;
	t_err		err;
	t_data		data;
	t_line		line;
	t_image		**textures;
	t_image		*image;
	int					color_floor;
	int					color_ceiling;

	
}              t_all;

int				ft_create_rgb(int t, int r, int g, int b);
int				ft_check_virg(int i, char *newline);
void			ft_check_rgb(int i, char *newline, t_maps *maps);
void			ft_colors(char *newline, t_maps *maps);
char			*charjoin(char *s, char c, int max);
int				gnl(int fd, char **line);
void			ft_textures(t_maps *maps, char *newline);
int				ft_parsemap(t_all *all, char *newline);
void			ft_res(char *newline, t_maps *maps);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				ft_close(int keycode, t_all *all);
int				key_hook(int keycode, t_all *all);
void 			ft_init(t_maps *maps);
int				ft_validmap(t_maps *maps);
int				ft_jumpspace(int c);
void			free_matrix(char **matrix);
char			**ft_write_map(char *newline, int *my, int *mx, char **tb);
void	   		my_pixel_put(t_vars *vars, t_maps *maps, int i, int j);
int	    	ft_draw_map(t_vars *vars, t_maps *maps);
void			ft_pos(t_maps *maps, t_player *player);
// void			draw_line(t_player *player, t_vars *vars);
void			ft_init_player(t_player *player);
void			ft_fill_mtx(char **tmp_cell, t_all *all);
int		 		ft_raycasting(t_all *all);
void 			hit(t_all *all);
static void		predict_wall_face(t_all *all);
void			perp_and_height(t_all *all);
void			next_step(t_all *all);
int				is_map_char(char c, char *mapchars);
char			*str_to_map_rows(char *str);
static void		texture_on_img(t_line *line, t_image *texture, t_all *all);
void			ver_line_texture_image(t_line *line, t_all *all, t_image *texture);
void			ver_line_color_image(t_line *line, t_all *all, int color);
static void		determine_side_draw(t_all *all, t_line *line, double wall_x);
int				texturisation(t_all *all);
void			pixel_put_to_image(int color, int x, int y, t_image *img);
int				ft_error(int i);
static void		do_raycasting(t_all *all);
int			set_texture(t_all *all, const char *path, int texture_index);
int     ft_render_next(t_all *all);
void    ft_draw_line(t_all *all);





#endif 