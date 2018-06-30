/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s1c5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 21:42:01 by pierre            #+#    #+#             */
/*   Updated: 2018/06/30 09:41:31 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

#include "ft_repeatkey_xor.c"
t_string		ft_repeatkey_xor(const t_string str, const t_string key);


int			main(int ac, char **av)
{
	if (ac != 3)
		return 1;
	t_string		encod = av[1];
	t_string		key = av[2];
	t_string		res = ft_hexlify(ft_repeatkey_xor(encod, key), ft_strlen(encod));

	ft_printf("%s\n", res);
	ft_strdel(&res);
	return 0;
}
