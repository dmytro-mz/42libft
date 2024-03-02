#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    if (lst->next)
        return (ft_lstlast(lst->next));
    return (lst);
}
