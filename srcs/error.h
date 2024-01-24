/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:42:23 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/24 10:58:46 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_OPENING_FILE -2
# define ERROR_ALLOCATING_MEMORY -3
# define ERROR_READING_FILE -4
# define ERROR_INVALID_MAP -5
# define ERROR_EMPTY_MAP -6
# define ERROR_INVALID_CHARACTER -7
# define ERROR_INVALID_DIMENSIONS -8
# define ERROR_INVALID_BOUNDARY -9
# define ERROR_INVALID_PLAYER_COUNT -10
# define ERROR_NO_EXIT -11
# define ERROR_NO_MAP_FILE -12
# define ERROR_INVALID_MAP_FILE -13

# define ERROR_OPENING_FILE_MSG "Error: Opening file\n"
# define ERROR_ALLOCATING_MEMORY_MSG "Error: Allocating memory for map grid\n"
# define ERROR_READING_FILE_MSG "Error: Reading map file\n"
# define ERROR_INVALID_MAP_MSG "Error: Validating map\n"
# define ERROR_EMPTY_MAP_MSG "Error: Empty map\n"
# define ERROR_INVALID_CHARACTER_MSG "Error: Invalid character in map\n"
# define ERROR_INVALID_DIMENSIONS_MSG "Error: Invalid map dimensions\n"
# define ERROR_INVALID_BOUNDARY_MSG "Error: Invalid map boundary. The map \
should be surrounded by walls\n"
# define ERROR_INVALID_PLAYER_COUNT_MSG "Error: Invalid player count. The map \
should contain exactly one player character."
# define ERROR_NO_EXIT_MSG "Error: No exit. The map should contain at least \
one exit."
# define ERROR_NO_MAP_FILE_MSG "Error: No map file provided. Please provide \
a .ber map file as the first argument."
# define ERROR_INVALID_MAP_FILE_MSG "Error: Invalid map file. The map file \
must have a .ber extension."
#endif