#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *res;
    res = ft_lstnew((*f)(lst->content));
    if (!res)
        return (NULL);
    res->next = NULL;
    if (lst->next)
    {
        res->next = ft_lstmap(lst->next, f, del);
        if (!(res->next))
        {
            ft_lstdelone(res, del);
            return (NULL);
        }
    }
    return (res);
}
