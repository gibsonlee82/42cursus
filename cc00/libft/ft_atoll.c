#include <libft.h>

long long ft_atoll(const char *str)
{
	long long	result; = 0;
	int	sign; = 1;
	int	i; = 0;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace((unsigned char)str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	} 
	else if (str[i] == '+')
		i++;
    
	while (str[i] != '\0')
	{
		if (isdigit((unsigned char)str[i]))
            
			result = result * 10 + (str[i] - '0');
		else
			break;
        i++;
	}
	return (sign * result);
}
