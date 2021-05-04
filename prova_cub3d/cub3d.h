/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:09:00 by jkosiara          #+#    #+#             */
/*   Updated: 2021/05/04 16:32:56 by mmurello         ###   ########.fr       */
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

typedef struct s_maps
{
    int		resx;
	int		resy;
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	char	*S;
	int		F;
	int		C;
	int		red;
	int		green;
	int		blue;
	char	**map;
}              t_maps;

// typedef struct s_pos{
//    
// }              t_pos;

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }				t_list;

 typedef struct s_coord
 {
// 	double		posx;
// 	double		posy;
// 	double		dirx;
// 	double		diry;
// 	double		planex;
// 	double		planey;
// 	double		raydirx;						//raggio laser
// 	double		raydiry;
// 	int			mapx;							// casella mappa
// 	int			mapy;
//	char		**mtx;
int	mapx;										// quantita' caselle orizz
int	mapy;										// quantita' caselle vert
char **mtx;										// caselle effettive mtx[i][j]
// 	double 		deltadistx; 					// distanza che il raggio deve percorrere per andare da 1 lato x al successivo lato x, viceversa
// 	double 		deltadisty;
// 	int 		stepx;							//controllo delle componenti
// 	int 		stepy;
// 	double 		sidedistx;						//distanza dalla posizione iniziale del raggio al primo lato o destro o sinistro, dip dalla componente del raggio
// 	double 		sidedisty;
// 	double 		perpwalldist;					//verrà utilizzata per calcolare la lunghezza del raggio
}				t_coord;

typedef struct s_all{
	t_vars vars;
	t_maps maps; 								// mancano i nomi
	t_coord coord;
}              t_all;

int			ft_create_rgb(int t, int r, int g, int b);
int			ft_check_virg(int i, char *newline);
void		ft_check_rgb(int i, char *newline, t_maps *maps);
void		ft_colors(char *newline, t_maps *maps);
char		*charjoin(char *s, char c, int max);
int			gnl(int fd, char **line);
void		ft_textures(t_maps *maps, char *newline);
void		ft_parsemap(t_maps *maps, char *newline);
void		ft_res(char *newline, t_maps *maps);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_close(int keycode, t_vars *vars);
int			key_hook(int keycode, t_vars *vars);

#endif 