#include "libft.h"

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list  *tmp;

    tmp = lst;
    while (lst)
    {
        f(tmp->content);
        tmp = tmp->next;
    }
}
