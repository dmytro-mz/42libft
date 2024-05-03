/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:34:27 by dmoroz            #+#    #+#             */
/*   Updated: 2024/05/03 10:52:05 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s_s1;
	const unsigned char	*s_s2;

	if (n == 0)
		return (0);
	s_s1 = (const unsigned char *)s1;
	s_s2 = (const unsigned char *)s2;
	i = 0;
	while (s_s1[i] == s_s2[i] && i < n - 1)
		i++;
	return (s_s1[i] - s_s2[i]);
}
