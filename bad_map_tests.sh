#!/bin/bash

# Directory where the .cub files are stored (change if needed)
MAP_DIR="./maps/bad/"

# List of all .cub files (based on the screenshot)
MAPS=(
	"color_double.cub"
	"color_invalid_rgb.cub"
	"color_missing_ceiling_rgb.cub"
	"color_missing_floor_rgb.cub"
	"color_missing.cub"
	"color_none.cub"
	"color_triple.cub"
	"empty.cub"
	"file_letter_end.cub"
	"filetype_missing"
	"filetype_norights.cub"
	"filetype_wrong.buc"
	"forbidden.cub"
	"map_bad_characters.cub"
	"map_bad_door.cub"
	"map_first.cub"
	"map_middle.cub"
	"map_missing.cub"
	"map_only.cub"
	"map_too_small.cub"
	"map_void.cub"
	"player_multiple.cub"
	"player_none.cub"
	"player_on_edge.cub"
	"textures_dir.cub"
	"textures_duplicates_double_missing.cub"
	"textures_duplicates.cub"
	"textures_forbidden.cub"
	"textures_invalid.cub"
	"textures_missing.cub"
	"textures_none.cub"
	"textures_not_xpm.cub"
	"wall_hole_east.cub"
	"wall_hole_north.cub"
	"wall_hole_south.cub"
	"wall_hole_west.cub"
	"wall_none.cub"
)

chmod 000 maps/bad/filetype_norights.cub

# Loop through each map and run ./cub3d
for MAP in "${MAPS[@]}"; do
	echo -e "\e[31mTesting:$MAP_DIR$MAP\e[0m"
	./cub3D "$MAP_DIR$MAP"
	echo "-------------------------------------"
done

chmod 777 maps/bad/filetype_norights.cub