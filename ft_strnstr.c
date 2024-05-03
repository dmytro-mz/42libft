/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:39:41 by dmoroz            #+#    #+#             */
/*   Updated: 2024/05/03 11:48:01 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;

	if (!sub[0])
		return ((char *)str);
	i = 0;
	while (i < len && str[i])
	{
		j = 0;
		while (sub[j] && str[i + j] == sub[j])
			j++;
		if (i + j > len)
			break ;
		if (!sub[j])
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
