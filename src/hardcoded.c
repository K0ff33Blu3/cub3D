#include "cub3D.h"

/**
 * @brief Crea una mappa hardcoded per testare il gioco
 * 
 * @return t_map* Puntatore alla mappa allocata, o NULL se fallisce
 */
t_map	*hardcoded_map()
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->map_width = 6;
	map->map_height = 5;
	map->map_skeleton = (char **)malloc(sizeof(char *) * map->map_height);
	map->map_skeleton[0] = "111111";
	map->map_skeleton[1] = "100101";
	map->map_skeleton[2] = "101001";
	map->map_skeleton[3] = "1100N1";
	map->map_skeleton[4] = "111111";
	map->ceiling_rgb[0] = 220;
	map->ceiling_rgb[1] = 100; 
	map->ceiling_rgb[2] = 0;
	map->ceiling_hex = rgb_to_hex(map->ceiling_rgb);
	map->floor_rgb[0] = 220;
	map->floor_rgb[1] = 100; 
	map->floor_rgb[2] = 0;
	map->floor_hex = rgb_to_hex(map->floor_rgb);
	map->NO_text_path = "./textures/BrickWall.png";
	map->EA_text_path = "./textures/BrickWall.png";
	map->SO_text_path = "./textures/BrickWall.png";
	map->WE_text_path = "./textures/BrickWall.png";
	map->player = (t_player *)malloc(sizeof(t_player));
	map->player->pos.x = 4;
	map->player->pos.y = 4;
	map->player->dir.x = 0;
	map->player->dir.y = -1;
	map->player->plane.x = 0.70;
	map->player->plane.y = 0;
	return (map);
}