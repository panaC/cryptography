/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s1c3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 09:51:35 by pierre            #+#    #+#             */
/*   Updated: 2018/06/28 11:01:25 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	t_string		str = ft_unhexlify(av[1]);
	t_string		strtmp = ft_strdup(str);
	t_string		strres = NULL;
	int				len = ft_strlen(str);
	int				count_space = 0;
	char			key = 0;

	for (int i = 1; i < 256; i++) {
		for (int j = 0; j < len; j++) {
			strtmp[j] = str[j] ^ i;
		}
		if (count_space < (int)ft_strnbchr(strtmp, (int)' ')) {
			key = i;
			ft_strdel(&strres);
			strres = ft_strdup(strtmp);
			count_space = (int)ft_strnbchr(strtmp, (int)' ');
		}
	}
	ft_printf("Key %d:%c ; string |%s|\n", key, key, strres);
	ft_strdel(&strtmp);
	ft_strdel(&strres);
	ft_strdel(&str);
	return 0;
}
