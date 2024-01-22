/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:42:23 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/22 14:22:40 by lkilpela         ###   ########.fr       */
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


# define ERROR_OPENING_FILE_MSG "Error: Opening file\n"
# define ERROR_ALLOCATING_MEMORY_MSG "Error: Allocating memory for map grid\n"
# define ERROR_READING_FILE_MSG "Error: Reading map file\n"
# define ERROR_INVALID_MAP_MSG "Error: Validating map\n"
# define ERROR_EMPTY_MAP_MSG "Error: Empty map\n"
# define ERROR_INVALID_CHARACTER_MSG "Error: Invalid character in map\n"
# define ERROR_INVALID_DIMENSIONS_MSG "Error: Invalid map dimensions\n"

#endif