/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s1c3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 09:51:35 by pierre            #+#    #+#             */
/*   Updated: 2018/06/29 20:11:17 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

#include "print_key.c"
int		print_key(t_string encod);

int		main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	print_key(av[1]);
	return 0;
}
