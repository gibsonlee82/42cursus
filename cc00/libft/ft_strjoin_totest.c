/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:33:41 by giblee            #+#    #+#             */
/*   Updated: 2025/03/06 18:31:49 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

// calculate the total length of all strings + separators
// total length = 0 (empty string) if size = 0
int	calc_length(int size, char **strs, char *sep)
{
	int	i;
	int	total_length;

	total_length = 0;
	if (size == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	return (total_length + (size - 1) * ft_strlen(sep));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_length;
	char	*result;

	total_length = 0;
	if (strs == NULL || strs[0] == NULL)
		return (NULL);
	total_length = calc_length(size, strs, sep);
	result = malloc(sizeof(char) * (total_length + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	result[0] = '\0';
	while (i < size - 1)
	{
		ft_strcat(result, strs[i]);
		ft_strcat(result, sep);
		i++;
	}
	ft_strcat(result, strs[i]);
	result[total_length] = '\0';
	return (result);
}

/*
#include <stdio.h>
int	main(void) 
{
	//char	*strs[] = {};
	char	*strs[] = {"how", "are", "you", "?"};
	int	size = 0;
	char	*sep = ", "; // Separator

	char	*result = ft_strjoin(size, strs, sep);

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