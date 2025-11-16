#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>

typedef struct s_malloc_list
{
	void					*ptr;
	struct s_malloc_list	*next;
}	t_malloc_list;

void	*ft_malloc(size_t size);
void	ft_free(void *ptr);
void	ft_free_all(void);

#endif
