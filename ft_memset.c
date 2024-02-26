/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:48:49 by dmoroz            #+#    #+#             */
/*   Updated: 2024/02/26 18:52:22 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc_c;

	uc_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		((char *)s)[i] = uc_c;
		i++;
	}
	return (s);
}
