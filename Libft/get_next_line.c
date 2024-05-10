/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:52:12 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/05 18:52:54 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_buffer(char *buffer, int fd)
{
	int		byte_count;
	char	temp[GNL_BUFFER_SIZE + 1];
	char	*container;

	byte_count = 1;
	if (!buffer)
		buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && byte_count >= 0)
	{
		byte_count = read(fd, temp, GNL_BUFFER_SIZE);
		if (byte_count < 0)
			return (free(buffer), NULL);
		if (byte_count == 0)
			break ;
		temp[byte_count] = '\0';
		container = ft_strjoin(buffer, temp);
		if (!container)
			return (free(buffer), NULL);
		free(buffer);
		buffer = container;
	}
	return (buffer);
}

char	*ft_line_extract(char *buffer)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	new_line = (char *)malloc(i + 1 * sizeof(char));
	if (!new_line)
		return (NULL);
	while (j != i)
	{
		new_line[j] = buffer[j];
		j++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_refresh(char *buffer)
{
	int		i;
	int		j;
	char	*new;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	new = malloc(ft_strlen(buffer) - i + 1);
	if (new == NULL)
		return (free(buffer), NULL);
	i++;
	while (buffer[i])
		new[j++] = buffer[i++];
	new[j] = '\0';
	free(buffer);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*final_line;

	final_line = NULL;
	if (fd < 0 || GNL_BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_read_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	final_line = ft_line_extract(buffer);
	if (!final_line || final_line[0] == '\0')
	{
		if (buffer)
			return (free(buffer), buffer = NULL, NULL);
		return (NULL);
	}
	buffer = ft_refresh(buffer);
	return (final_line);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	fd = open("empty.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	i = 0;
// 	while (i != 5)
// 	{
// 		printf("Line: %s", line = get_next_line(fd));
// 		i++;
// 	}
// }
