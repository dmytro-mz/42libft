/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:12:21 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/28 17:16:36 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	const char		*res;

	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			res = s + i;
		i++;
	}
	if (s[i] == c)
		res = s + i;
	return ((char *)res);
}
