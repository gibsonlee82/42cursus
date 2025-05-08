/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:33:41 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 11:53:38 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// Allocates memory (using malloc(3)) and returns a new string, 
// which is the result of concatenating 's1' and 's2'.
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = 0;
	return (result);
}

/*
#include <stdio.h>
int	main(void) 
{
	char	*result = ft_strjoin("how", " are you?");

	if (result != NULL)
	{
		printf("Result: %s\n", result);
		free(result); // Free the allocated memory
	} 
	else
		printf("Gibson: Memory allocation failed!\n");
	return (0);
}
*/
