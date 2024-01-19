#include "so_long.h"
int read_map_into_struct(t_map *map, char *map_file);

t_map map;
char *map_file = "/Users/lumik/workspace/git/so_long/game_maps/map.ber";

// Test get_map_dimension
int result = get_map_dimension(&map, map_file);
assert(result == 0);
assert(map.height == 3);
assert(map.width == 4);

// Test allocate_map_grid
result = allocate_map_grid(&map);
assert(result == 0);

// Test read_map_into_struct
result = read_map_into_struct(&map, map_file);
assert(result == 0);

// Test validate_map
result = validate_map(&map);
assert(result == 0);