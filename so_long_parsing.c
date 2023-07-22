#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

void	ft_error(void)
{
	printf("Error\n");
	exit(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;
	char	*s;

	if (len == 0 && !haystack && needle)
		return (NULL);
	p = (char *)haystack;
	s = (char *)needle;
	if (s[0] == '\0')
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (p[i + j] != '\0' && i < len)
	{
		while (p[i + j] == s[j] && i + j < len)
		{
			j++;
			if (s[j] == '\0')
				return ((char *)haystack + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}