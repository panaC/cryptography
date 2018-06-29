/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:32:43 by pierre            #+#    #+#             */
/*   Updated: 2018/06/29 20:22:22 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			print_key(t_string encod)
{
	if (!encod)
		return 0;
	t_string		english_freq = " etaonisrhdlucmfwgypbvkxjqz";
	int				len_en = ft_strlen(english_freq);
	t_string		str = ft_unhexlify(encod);
	t_string		strtmp = ft_strdup(str);
	t_string		strres = NULL;
	int				len = ft_strlen(str);
	int				count = 0;
	char			key = 0;
	int				let = 0;

	for (int j = 0; j < len_en; j++) {
		for (int i = 1; i < 256; i++) {
			for (int j = 0; j < len; j++) {
				strtmp[j] = str[j] ^ i;
			}
			if (count < (int)ft_strnbchr(strtmp, english_freq[j])) {
				key = i;
				let = j;
				ft_strdel(&strres);
				strres = ft_strdup(strtmp);
				count = (int)ft_strnbchr(strtmp, english_freq[j]);
			}
		}
	}
	ft_printf("|%60s| Key %d, string |%a|, count=%d, let=%c\n", encod, key, strres, count,
			english_freq[let]);
	ft_strdel(&strtmp);
	ft_strdel(&strres);
	ft_strdel(&str);
	return (count);
}
