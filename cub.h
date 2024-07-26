/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:59:00 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 13:59:37 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include "gnl/get_next_line.h" 
# define WIDTH			2040
# define HEIGHT			1000

# define ROTATE_SPEED	0.15
# define MOVE_SPEED		0.2

# define RIGHT			124
# define LEFT			123
# define ESC			53
# define A				0
# define S				1
# define D				2
# define W				13

# define BUFFER_SIZE2 10

typedef struct s_valid
{
	int		foundmap;
	int		foundtextures;
	int		foundfloorcolor;
	char	*line;
}				t_valid;

typedef struct s_valid2
{
	int			count_f;
	int			count_c;
	int			index_f;
	int			index_c;
	int			i;
	char		*r;
	char		*g;
	char		*b;
}				t_valid2;

typedef struct s_index
{
	int	index_no;
	int	index_so;
	int	index_ea;
	int	index_we;
	int	index_c;
	int	index_f;
}				t_index;

typedef struct s_img
{
	void	*ptr;
	char	*img;
	int		bpp;
	int		width;
	int		height;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_game
{
	int		f_color;
	int		c_color;
	int		index;
	void	*mlx;
	void	*win;
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
	int		x;
	int		y;
}				t_game;

typedef struct s_raycasting
{
	double	perpwalldist;
	double	deltadistx;
	double	deltadisty;
	double	sidedistx;
	double	sidedisty;
	double	camerax;
	double	raydiry;
	double	raydirx;
	double	planex;
	double	planey;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		stepx;
	int		stepy;
	int		side;
	int		mapx;
	int		mapy;
	int		hit;
}				t_raycasting;

typedef struct s_data
{
	int		pos_x;
	int		pos_y;
	char	**map;
	int		x;
	int		y;
}				t_data;

typedef struct s_cub
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
}	t_cub;

typedef struct s_map
{
	char			**texture;
	char			**playfield;
	char			**map;
	int				height;
	int				width;
	void			*mlx;
	void			*imgn;
	void			*imgw;
	void			*imge;
	void			*imgs;
	int				img_w;
	int				img_h;
	void			*win;
	int				win_w;
	int				win_h;
	char			**result;
	char			**result2;
	int				c[3];
	int				f[3];
	int				term[3];
}	t_map;

typedef struct s_addres
{
	t_raycasting	*rcasting;
	t_index			*index;
	t_game			*game;
	t_img			*img;
	t_cub			*cub;
	t_data			data;
}				t_addres;

int				file_exists(char *filename);
char			*get_next_line(int fd);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen2(const char *c);
size_t			ft_strlcpy(char *dest, const char *src, size_t len);
char			**ft_split(char *s, char c);
int				ft_isdigit(int i);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_substr2(char *s, int start, int len);
void			file_validity(char *file_line);
void			clean_tabs(char **map);
int				height_map(char **map);
char			**getmap(char *filename);
void			norming_map(char **full_line, char **line, int *flag);
char			*read_map(int fd);
void			get_textures(char **map, t_map *mapp);
void			get_playfield(char **map, t_map *m);
int				is_north(char **texture);
int				arr_length(char **array);
int				texture_count(char **array);
int				count_strings(char *s, char c);
void			free_strings(char **tab);
char			*malloc_strings(char *s, char c);
char			**split_loop(char *s, char c, int i, int words);
int				ft_error(char *str);
int				walls_spaces(char **map);
int				checking_walls(char **array);
char			*epurstr(char *s);
void			epur_texture(char **texture);
int				validate_color_texture(char **texture, int numLines);
int				substring_one(char **arr, char *sub);
int				parse_textures(char **texture, t_map *map);
int				create_imges(t_map *map);
int				valid_color(char *str, t_map *map);
int				validate_colors(char **texture, t_map *map);
int				dirs(char **map);
int				is_map_symb(char **map);
int				is_empty_line(char **playfield);
void			init_cub(t_map *map, t_cub *cub);
void			initializer(t_addres *addres);
int				create_trgb(int r, int g, int b);
void			init_struct_game(t_addres *address);
void			init_struct_index(t_addres *address);
void			init_struct_img(t_addres *address);
void			init_struct_raycasting(t_addres *address);
void			init_structs(t_addres *address);
void			draw_floor_and_celling(t_addres *data, char *dest);
int				ft_texx(t_addres *address, int n);
int				draw_walls(t_addres *address, char *dest, \
							char *dest_2, int texx);
void			norm_init_win_3(t_addres *address);
float			ft_abs(float num);
char			*get_correct_arg(char *ptr);
void			init_plane(t_addres *address, double i, double j);
void			init_dir(t_addres *address, double i, double j);
void			init_player_pos(t_addres *address, int i, int j);
void			ft_get_data_addr(t_addres *address);
int				check_nwse(t_addres *address);
void			find_pos_player(t_addres *address);
void			norm_init_win_2(t_addres *address);
void			norm_init_win(t_addres *address);
void			continue_init_win(t_addres *address);
void			init_win(t_addres *address);
int				key_manager(int key, t_addres *address);
void			rotate_right(t_addres *address, double rotate);
void			move_left(t_addres *address);
void			move_right(t_addres *address);
void			move_up(t_addres *address);
void			move_down(t_addres *address);
int				close_game(t_addres *address);
void			print_error(t_addres *address, char *err, int flag);
void			free_cub(t_cub map);
void			free_mtx(char **mtx);
void			free_all(t_addres *address);
void			init_vc(t_valid *v);
int				ft_isspace(int c);
int				is_digital_str(char *str);
void			main_helper(t_map *aaa, char **array, char **argv);
void			main_helper2(t_map *aaa);
void			free_texture(t_map *aaa);
void			main_h(t_map *aaa, char **array, t_cub *cub, char **argv);
void			handle_empty_map(void);
int				ft_exit(t_map *v);
t_data			data_collector(t_cub cub, t_map map);
void			fd_check(char *filename);
void			init_v2(t_valid2 *v);
void			free_result(char **arr);
void			isimagevalid(char *file_line);
int				extension_compare(char *str, char *to_find);
void			ft_errorwithexit(char *str);
void			parse_textures2(t_map *map, char **arr, int i, int flag);

#endif