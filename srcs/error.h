/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:42:23 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/22 13:44:56 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_OPENING_FILE -2
# define ERROR_ALLOCATING_MEMORY -3
# define ERROR_READING_FILE -4
# define ERROR_INVALID_MAP -5

# define ERROR_OPENING_FILE_MSG "Error opening file\n"
# define ERROR_ALLOCATING_MEMORY_MSG "Error allocating memory for map grid\n"
# define ERROR_READING_FILE_MSG "Error reading map file\n"
# define ERROR_INVALID_MAP_MSG "Error validating map\n"

#endif