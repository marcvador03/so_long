/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:21:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/10/04 11:22:30 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_MISS_ARG "Missing argument pointing to map file" 
# define ERR_OPEN_FILE "Error during opening map file" 
# define ERR_FILE_EMPTY "File .ber is empty!" 
# define ERR_FILE_EMPTY_LINE "Empty line has been detected in the input file" 
# define ERR_CLOSE_FILE "Error during map file closing" 
# define ERR_MAP_NOT_RECT "Map is not rectangular" 
# define ERR_MAP_FORBID_VALUE "Map contains forbidden value" 
# define ERR_MAP_WALLS "Map does not contain surrounding walls" 
# define ERR_MAP_DUP "Duplicate entry or exit point in map" 
# define ERR_MAP_HERO "Main character missing on map" 
# define ERR_MAP_EXIT "Exit missing or not reachable" 
# define ERR_MAP_PATH "Not all items can be reached, please revise map path" 
# define ERR_MALLOC "Errors during memory allocation (malloc)" 
# define ERR_SPRITE "Error during sprite creation" 
# define ERR_IMAGE "Error during image loading (MLX42)" 
# define ERR_IMAGE_RES "Error during image resizing (MLX42)" 
# define ERR_ANIME "Error during anime creation" 
# define ERR_LOAD_TEXTURE "Error during texture load" 
# define ERR_PPT "Error in Pixel per Tile (PPT) definition < 0" 
# define ERR_EXT "Wrong map extension file (expected .ber)" 
# define ERR_MAP_SIZE "Map is larger than screen resolution" 
# define ERR_MLX_INIT "Error during Window initialization (MLX42)" 

#endif
