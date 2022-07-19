/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:07:23 by bede-car          #+#    #+#             */
/*   Updated: 2022/07/19 17:09:06 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*buf;

	fd = open("genilson", O_RDONLY);
	while (1)
	{
		buf = get_next_line(fd);
		printf("%s", buf);
		if (!buf)
			break ;
		free (buf);
	}
	free(buf);
	close(fd);
	return (0);
}
