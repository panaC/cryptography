/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s1c4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 09:51:35 by pierre            #+#    #+#             */
/*   Updated: 2018/06/29 20:21:03 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <get_next_line.h>
#include <unistd.h>
#include <fcntl.h>

#include "print_key.c"
int				print_key(t_string encod);

int				main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int			fd = open(av[1], O_RDONLY);
	char		*line;
	char		*res = NULL;
	int			count = 0;
	int			count_tmp = 0;

	if (fd < 1)
		return (1);
	while (get_next_line(fd, &line)) {
		count_tmp = print_key(line);
		if (count <= count_tmp)
		{
			ft_strdel(&res);
			res = ft_strdup(line);
			count = count_tmp;
		}
		ft_strdel(&line);
	}
	ft_printf("\nRESULT: ");
	print_key(res);
	ft_strdel(&res);
	return (0);
}
