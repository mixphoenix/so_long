#include "../so_long.h"

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	if (!s)
		return (0);
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*constr;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	constr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (!constr)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			constr[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != '\0')
		constr[i++] = s2[j++];
	constr[i] = '\0';
	free(s1);
	return (constr);
}
