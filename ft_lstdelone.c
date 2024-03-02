#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    (*del)(lst->content);
    lst->content = NULL;
    lst->next = NULL;
    free(lst);
}
