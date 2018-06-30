/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeatkey_xor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:19:08 by pierre            #+#    #+#             */
/*   Updated: 2018/06/30 09:26:38 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_string		ft_repeatkey_xor(const t_string str, const t_string key)
{
	t_string	s;	
	size_t		i;
	size_t		j;
	size_t		len;
	size_t		len_str;

	if (!str || !key)
		return (ft_strdup(str));
	i = 0;
	j = 0;
	len = ft_strlen(key);
	len_str = ft_strlen(str);
	s = ft_strnew(len_str);
	while (i < len_str)
	{
		if (j == len)
			j = 0;
		s[i] = str[i] ^ key[j];
		++j;
		++i;
	}
	return (s);
}
