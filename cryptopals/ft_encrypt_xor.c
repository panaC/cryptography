/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_encrypt_xor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 21:30:38 by pierre            #+#    #+#             */
/*   Updated: 2018/06/29 22:09:40 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_string			ft_encrypt_xor_char(const t_string encod, char key)
{
	t_string		s;
	size_t			i;
	size_t			nb;

	if (!key || !encod)
		return (ft_strdup(""));
	nb = ft_strlen(encod);
	s = ft_strnew(nb);
	i = 0;
	while (i < nb)
	{
		s[i] = encod[i] ^ key;
		++i;
	}
	return (s);
}

t_string			ft_encrypt_xor(const t_string encod, const t_string key)
{
	t_string		s1;
	t_string		s2;
	size_t			i;
	size_t			nb;

	if (!key || !encod || !key[0])
		return (ft_strdup(encod));
	s1 = (t_string)encod;
	nb = ft_strlen(key);
	s1 = ft_encrypt_xor_char(s1, key[0]);
	i = 1;
	while (i < nb)
	{
		s2 = ft_encrypt_xor_char(s1, key[i]);
		ft_strdel(&s1);
		s1 = s2;
		++i;
	}
	return (s1);
}
