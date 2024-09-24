/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:21:11 by mfleury           #+#    #+#             */
/*   Updated: 2024/09/24 23:40:06 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_MISS_ARG "Missing argument pointing to map file" 
# define ERR_OPEN_FILE "Error during opening map file" 
# define ERR_CLOSE_FILE "Error during map file closing" 
# define ERR_MAP_NOT_RECT "Map is not rectangular" 
# define ERR_MAP_FORBID_VALUE "Map contains forbidden value" 
# define ERR_MAP_WALLS "Map does not contain surrounding walls" 
# define ERR_MAP_DUP "Duplicate entry or exit point in map" 
# define ERR_MALLOC "Errors during memory allocation (malloc)" 
# define ERR_SPRITE "Error during sprite creation" 
# define ERR_ANIME "Error during anime creation" 
# define ERR_LOAD_TEXTURE "Error during texture load" 
# define ERR_PPT "Error in Pixel per Tile (PPT) definition < 0" 

#endif
