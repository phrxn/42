# get_next_line

<p align="center">
  <img src="https://raw.githubusercontent.com/phrxn/phrxn/master/42/badges/get_next_linem.png" />
</p>
<p align="center">
	<b><i>Reading a line from a fd is way too tedious.</i></b><br>
</p>

## Status
Finished: 2022-10-07.

## Run and Usage/Test

Create a simple main:

```
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
```


``gcc main.c get_next_line.c -DBUFFER_SIZE=<n>`` to compile. Where N is the buffer size > 0 && <= MAX READ SYSTEM CALL.

After compilation:

``./a.out file.txt`` or ``./a.out`` to read from STDIN.
