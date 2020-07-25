#include <stdio.h>
# include <fcntl.h>
#include "get_next_line.h"

int	main (void)
{
	char	*line;
	int		fd;

	// fd = 4;
	// line = "1122e12328";
	
	fd = open("text.txt", O_RDONLY);
	// printf("%d\n", fd);
	
	
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
			free(line);
	}
	printf("%s\n", line);
			free(line);
	return(0);
}