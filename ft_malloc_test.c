#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "ft_malloc.h"

/*
 * malloc 'count' blocks of memory each up to 'size' bytes
 * then free every 'span' block
 */
void	multi_malloc(int count, int bytes, int span)
{
	char	*ptr;
	size_t	size;

	if (count <= 0)
		return ;
	size = rand() % bytes + 1;
	ptr = (char *)ft_malloc(size);
	if (ptr != NULL)
		memset(ptr, 0xff, size);
	else
		printf("error: ft_malloc failed\n");
	multi_malloc(count - 1, bytes, span);
	if (ptr != NULL & count % span == 0)
		ft_free(ptr);
}

int	main(void)
{
	srand(time(NULL));
	multi_malloc(100000, 1000, 10);
	ft_free_all();
	return (0);
}
