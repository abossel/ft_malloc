#include "ft_malloc.h"

static t_malloc_list	**ft_malloc_list(void)
{
	static t_malloc_list	*list;

	return (&list);
}

void	*ft_malloc(size_t size)
{
	t_malloc_list	**list;
	t_malloc_list	*node;

	list = ft_malloc_list();
	node = (t_malloc_list *)malloc(sizeof(t_malloc_list));
	if (node == NULL)
		return (NULL);
	if (size == 0)
		size = 1;
	node->ptr = malloc(size);
	if (node->ptr == NULL)
	{
		free(node);
		return (NULL);
	}
	node->next = *list;
	*list = node;
	return (node->ptr);
}

void	ft_free(void *ptr)
{
	t_malloc_list	**list;
	t_malloc_list	*prev;
	t_malloc_list	*node;

	if (ptr == NULL)
		return ;
	list = ft_malloc_list();
	prev = NULL;
	node = *list;
	while (node != NULL)
	{
		if (node->ptr == ptr)
		{
			if (prev != NULL)
				prev->next = node->next;
			else
				*list = node->next;
			free(node->ptr);
			free(node);
			return ;
		}
		prev = node;
		node = node->next;
	}
}

void	ft_free_all(void)
{
	t_malloc_list	**list;

	list = ft_malloc_list();
	while (*list != NULL)
		ft_free((*list)->ptr);
}
