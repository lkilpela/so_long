/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:51:24 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/24 14:26:46 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char	*g_error_msgs[] = {
	"No error.",
	"Error: Null argument provided.",
	"Error: Opening file.",
	"Error: Allocating memory for map grid.",
	"Error: Reading map file.",
	"Error: Validating map.",
	"Error: Empty map.",
	"Error: Invalid character in map.",
	"Error: Invalid map dimensions.",
	"Error: Invalid map boundary. The map should be surrounded by walls.",
	"Error: Invalid player count. The map should contain exactly one player.",
	"Error: Invalid exit count. The map should contain at least one exit.",
	"Error: No file provided. Please provide a .ber file as the 1st	argument.",
	"Error: Invalid map file. The map file must have a .ber extension.",
	"Error: No player found in the map.",
	"Error: No exit found in the map.",
	"Error: No collectible found in the map."
};

// Exit the program as failure.
void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	print_error(int err)
{
	if (err < 0 && err > LAST_ERROR)
		printf("%s\n", error_msgs[-err]);
	else
		printf("Unknown error\n");
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 != 0 || *s2 != 0) && n > 0)
	{
		if (*s1 != *s2)
			return ((int)(unsigned char)*s1 - (int)(unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	n = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack != 0 && n <= len)
	{
		if (ft_strncmp(haystack, needle, n) == 0)
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (0);
}
