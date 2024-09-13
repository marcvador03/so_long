/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:40:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/14 01:55:24 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define HEIGHT 900
#define WIDTH 1440
#define BPP 4
#define PPT 32

void	sl_close(void *str)
{
		ft_printf("%s", (char *)str);
		exit(1);
}

size_t	sl_move_authorized(t_mainwindow *sl, keys_t key)
{
	unsigned int	i;
	unsigned int	j;
	size_t			n;

	n = 0;
	if (PPT < 0)
		sl_close("Error in pixel per tile PPT definition");
	i = sl->hero->instances[0].y / PPT;
	j = sl->hero->instances[0].x / PPT;
	if (key == MLX_KEY_RIGHT && j < sl->w_map)
		if (sl->map[i][j + 1].c != '1')
			sl->hero->instances[n++].x += PPT;
	if (key == MLX_KEY_LEFT && j > 0)
		if (sl->map[i][j - 1].c != '1')
			sl->hero->instances[n++].x -= PPT;
	if (key == MLX_KEY_UP && i > 0)
		if (sl->map[i - 1][j].c != '1')
			sl->hero->instances[n++].y -= PPT;
	if (key == MLX_KEY_DOWN && i < sl->h_map)
		if (sl->map[i + 1][j].c != '1')
			sl->hero->instances[n++].y += PPT;
	return (n);	
}

void	sl_move_action(t_mainwindow *sl)
{
	unsigned int	i;
	unsigned int	j;
	size_t			n;

	if (PPT < 0)
		sl_close("Error in pixel per tile PPT definition");
	i = sl->hero->instances[0].y / PPT;
	j = sl->hero->instances[0].x / PPT;
	if (sl->map[i][j].c == 'C')
	{
		n = sl->map[i][j].instance;
		sl->item->instances[n].enabled = false;
		sl->map[i][j].c = '0';
		sl->item_cnt--;
	}
	if (sl->map[i][j].c == 'E' && sl->item_cnt == 0)
		sl_close("Success!!!\n");
}

void	sl_keyhook(mlx_key_data_t keydata, void *param)
{
	t_mainwindow *sl;
	size_t		n;

	sl = (t_mainwindow *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		sl_close("Closing with ESC\n");
	if (keydata.key >= MLX_KEY_RIGHT && keydata.key <= MLX_KEY_UP)
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		{
			n = sl_move_authorized(sl, keydata.key);
			if (n > 0)
			{
				sl->move_cnt += n;
				ft_printf("Current #movements: %d\n", sl->move_cnt);
				sl_move_action(sl);
			}
		}
}
void	get_map_size(t_mainwindow *sl, char *path)
{
	char	*tmp;
	
	sl->fd = open(path, O_RDONLY);
	if (sl->fd == -1)
		sl_close("error while opening file\n");
	tmp = get_next_line(sl->fd);
	sl->h_map = 0;
	sl->w_map = ft_strlen(tmp) - 1;
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(sl->fd);
		if (tmp != NULL && sl->w_map != (ft_strlen(tmp) - 1))
			sl_close("map is not rectangular");
		sl->h_map++;
	}
	free(tmp);
	tmp = NULL;
	if (close(sl->fd) < 0)
		sl_close("error while closing fd");
}

unsigned int	sl_line_fill(t_map *map, char *line)
{
	int				j;
	unsigned int	item_cnt;

	j = 0;
	item_cnt = 0;
	while (line[j] != '\n')
	{
		if (line[j] != '0' && line[j] != '1')
			if(line[j] !='C' && line[j] != 'E' && line[j] != 'P')
				sl_close("map check: forbidden value");
		map[j].c = line[j];
		if (line[j++] == 'C')
			item_cnt++;
	}
	return (item_cnt);
}

void	sl_map_fill(t_mainwindow *sl, char *path)
{
	char	*line;
	int		i;

	sl->fd = open(path, O_RDONLY);
	if (sl->fd == -1)
		sl_close("error while opening file\n");
	line = get_next_line(sl->fd);
	i = 0;
	sl->item_cnt = 0;
	sl->item_cnt += sl_line_fill(sl->map[i++], line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(sl->fd);
		if (line != NULL)
			sl->item_cnt += sl_line_fill(sl->map[i++], line);
	}
	free(line);
	line = NULL;
	if (close(sl->fd) < 0)
		sl_close("error while closing fd");
}

void	sl_map_check_walls(t_map **map, unsigned int w, unsigned int h)
{
	unsigned int i;
	unsigned int j;

	j = 0;
	while (j <= w)
		if (map[0][j].c != '1' || map[h][j++].c != '1')
			sl_close("map check: missing surrounding walls");
	i = 0;
	while (i <= h)
		if (map[i][0].c != '1' || map[i++][w].c != '1')
			sl_close("map check: missing surrounding walls");
}

void	sl_map_check_dups(t_map **map, unsigned int w, unsigned int h)
{
	unsigned int i;
	unsigned int j;
	unsigned int cnt[3];

	i = 0;
	j = 0;
	while (j <= 2)
		cnt[j++] = 0;
	while (i <= h && (cnt[0] <= 1 || cnt[1] <= 1))
	{
		j = 0;
		while (j <= w)
		{
			if (map[i][j].c == 'E')
				cnt[0]++;
			else if (map[i][j].c == 'P')
				cnt[1]++;
			else if (map[i][j].c == 'C')
				cnt[2]++;
			j++;
		}
		i++;
	}
	if (cnt[0] > 1 || cnt[1] > 1) // yet missing cnt[2]==0 for collectibles	
		sl_close("map check: duplicate entry or start point");
}

void	sl_load_image(t_mainwindow *sl)
{
	unsigned int	i;
	unsigned int	j;
	size_t			n;
	
	i = 0;
	n = 0;
	while (i <= sl->h_map - 1)
	{
		j = 0;
		while (j <= sl->w_map - 1)
		{
			if (sl->map[i][j].c == '0')
			{
				mlx_image_to_window(sl->slx, sl->bckg, j * PPT, i * PPT);
				n = sl->bckg->count - 1;
				mlx_set_instance_depth(&sl->bckg->instances[n], 0);
				sl->map[i][j].instance = n;
			}
			else if (sl->map[i][j].c == '1')
			{
				mlx_image_to_window(sl->slx, sl->wall, j * PPT, i * PPT);
				n = sl->wall->count - 1;
				mlx_set_instance_depth(&sl->wall->instances[n], 3);
				sl->map[i][j].instance = n;
			}
			else if (sl->map[i][j].c == 'E')
			{
				mlx_image_to_window(sl->slx, sl->exit, j * PPT, i * PPT);
				n = sl->exit->count - 1;
				mlx_set_instance_depth(&sl->exit->instances[n], 3);
				sl->map[i][j].instance = n;
			}
			else if (sl->map[i][j].c == 'C')
			{
				mlx_image_to_window(sl->slx, sl->bckg, j * PPT, i * PPT);
				n = sl->bckg->count - 1;
				mlx_set_instance_depth(&sl->bckg->instances[n], 0);
				sl->map[i][j].instance = n;
				mlx_image_to_window(sl->slx, sl->item, j * PPT, i * PPT);
				n = sl->item->count - 1;
				mlx_set_instance_depth(&sl->item->instances[n], 3);
				sl->map[i][j].instance = n;
			}
			else if (sl->map[i][j].c == 'P')
			{
				mlx_image_to_window(sl->slx, sl->bckg, j * PPT, i * PPT);
				n = sl->bckg->count - 1;
				mlx_set_instance_depth(&sl->bckg->instances[n], 0);
				sl->map[i][j].instance = n;
				mlx_image_to_window(sl->slx, sl->hero, j * PPT, i * PPT);
				n = sl->hero->count - 1;
				mlx_set_instance_depth(&sl->hero->instances[n], 3);
				sl->map[i][j].instance = n;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_mainwindow	sl;
	mlx_texture_t	*texture;
	unsigned int	i;

	if (argc != 2)
		sl_close("missing argument\n");
	get_map_size(&sl, argv[1]);
	sl.map = (t_map **)ft_calloc(sl.h_map, sizeof(t_map *));
	if (sl.map == NULL)
		sl_close("error in calloc map");	
	i = 0;
	while (i <= (sl.h_map))
	{
		sl.map[i++] = (t_map *)ft_calloc(sl.w_map, sizeof(t_map));
		if (sl.map == NULL)
			sl_close("error in calloc map[i]");	
	}
	sl.map[i] = NULL;
	sl_map_fill(&sl, argv[1]);
	sl_map_check_walls(sl.map, sl.w_map - 1, sl.h_map - 1);
	sl_map_check_dups(sl.map, sl.w_map - 1, sl.h_map - 1);
	//mlx_get_monitor_size(0, &sl.m_width, &sl.m_height);
	sl.slx = mlx_init(sl.w_map * PPT, sl.h_map * PPT, "Test", true);
	if (sl.slx == NULL)
		sl_close("Error");
	
	sl.move_cnt = 0;	
	
	texture = mlx_load_png("textures/animals/ax_bear2.png");
	if (texture == NULL)
		sl_close("Error loading texture");
	sl.hero = mlx_texture_to_image(sl.slx, texture);
	if(mlx_resize_image(sl.hero, PPT, PPT) == false)
		sl_close("Error resizing image");
	
	texture = mlx_load_png("textures/fruits/01.png");
	if (texture == NULL)
		sl_close("Error loading texture");
	sl.item = mlx_texture_to_image(sl.slx, texture);
	if(mlx_resize_image(sl.item, PPT, PPT) == false)
		sl_close("Error resizing image");
	
	texture = mlx_load_png("textures/fruits/02.png");
	if (texture == NULL)
		sl_close("Error loading texture");
	sl.bckg = mlx_texture_to_image(sl.slx, texture);
	if(mlx_resize_image(sl.bckg, PPT, PPT) == false)
		sl_close("Error resizing image");
	
	texture = mlx_load_png("textures/fruits/03.png");
	if (texture == NULL)
		sl_close("Error loading texture");
	sl.exit = mlx_texture_to_image(sl.slx, texture);
	if(mlx_resize_image(sl.exit, PPT, PPT) == false)
		sl_close("Error resizing image");

	texture = mlx_load_png("textures/fruits/04.png");
	if (texture == NULL)
		sl_close("Error loading texture");
	sl.wall = mlx_texture_to_image(sl.slx, texture);
	if(mlx_resize_image(sl.wall, PPT, PPT) == false)
		sl_close("Error resizing image");
	
	sl_load_image(&sl);
	mlx_close_hook(sl.slx, sl_close, "Closing\n");	
	mlx_key_hook(sl.slx, &sl_keyhook, &sl);
	mlx_loop(sl.slx);
	sl_close("");
	return (0);
}
