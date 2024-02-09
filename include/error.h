/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:42:23 by lkilpela          #+#    #+#             */
/*   Updated: 2024/02/09 12:42:34 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

enum e_errcode
{
	NO_ERROR,
	ERROR_NULL_ARGUMENT,
	ERROR_OPENING_FILE,
	ERROR_ALLOCATING_MEMORY,
	ERROR_READING_FILE,
	ERROR_INVALID_MAP,
	ERROR_EMPTY_MAP,
	ERROR_INVALID_CHARACTER,
	ERROR_INVALID_DIMENSIONS,
	ERROR_INVALID_BOUNDARY,
	ERROR_INVALID_PLAYER_COUNT,
	ERROR_INVALID_EXIT_COUNT,
	ERROR_NO_MAP_FILE,
	ERROR_INVALID_FILE_EXTENSION,
	ERROR_NO_PLAYER,
	ERROR_NO_EXIT,
	ERROR_NO_COLLECTIBLE,
	ERROR_LOAD_TEXTURE,
	ERROR_INVALID_PATH,
	ERROR_EMPTY_LINE,
	LAST_ERROR
};

#endif