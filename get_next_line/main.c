#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/*
 * Simple GNL tester... read lines from the STDIN or a regular file
 * if the name of that file is passed as a param.
 *
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	int fd = -1;

	if(argc != 2)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		printf("error reading line from fd...");
		return 1;
	}
	line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return 0;
}
