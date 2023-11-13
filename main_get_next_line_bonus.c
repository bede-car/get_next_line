/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:09:07 by bede-car          #+#    #+#             */
/*   Updated: 2022/07/19 17:30:49 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd[3];
	int		count;
	char	*buf;

	fd[0] = open("genilson", O_RDONLY);
	fd[1] = open("genilda", O_RDONLY);
	fd[2] = open("genildo", O_RDONLY);

	count = 0;
	while (1)
	{
		buf = get_next_line_bonus(fd[count]);
		printf("%s", buf);
		if (!buf)
		{
			count++;
			printf("\nfd%d\n", fd[count]);
			if(count >= 3)
				break ;
		}
		free (buf);
	}
	free(buf);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	return (0);
}
