#include "so_long.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		x;
	char	*p;

	i = 0;
	x = ft_strlen(src) + 1;
	p = (char *)malloc(x * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;
	char	*s;

	if (len == 0 || (!haystack && needle))
		return (NULL);
	p = (char *)haystack;
	s = (char *)needle;
	if (s[0] == '\0')
		return (p);
	i = 0;
	j = 0;
	while (p[i] != '\0' && i < len)
	{
		while (p[i + j] == s[j] && (i + j) < len)
		{
			j++;
			if (s[j] == '\0')
				return (p + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}

void	ft_free_double_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}
