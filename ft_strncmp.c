/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:17:14 by dmoroz            #+#    #+#             */
/*   Updated: 2024/05/03 11:41:07 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*_s1;
	const unsigned char	*_s2;

	_s1 = (const unsigned char *)s1;
	_s2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (_s1[i] && _s2[i] && _s1[i] == _s2[i] && i < n - 1)
		i++;
	return (_s1[i] - _s2[i]);
}
