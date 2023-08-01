#include "../so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*constr;
	int		i;
	int		j;
	int		len;

	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	constr = malloc(len * sizeof(char));
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
	return (constr);
}