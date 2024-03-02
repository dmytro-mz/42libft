#include "libft.h"

int ft_lstsize(t_list *lst) 1234
{
    int size;
    
    size = 1;
    while (lst->next)
    {
        lst = lst->next;
        size++;
    }
    return (size);
}
