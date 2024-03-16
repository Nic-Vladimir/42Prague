#include <unistd.h>

char    *ft_strjoin(const char *s1, const char *s2)
{
    char    *res;
    int     i;
    int     j;

    i = 0;
    j = 0;
    res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char);
    if (!res)
        return (NULL)
    while (s1[i])
    {
        res[j] = s1[i];
        i++;
        j++;
    }
    i = 0;
    while (s2[i])
    {
        res[j] = s2[i];
        i++;
        j++;
    }
    res[j] = '\0';
    return (res);
}
