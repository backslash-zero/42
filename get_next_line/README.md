# Get Next Line

__Visual representation:__

draw.io [here](https://drive.google.com/open?id=1eHQ9cjbArg3vZhWuy42zMX3kynZsKIGr)

**Usage:**
* `get next line is a function that reads a file line by line`

**Return value:**
* `return 1 when it read a line`
* `return 0 when it finished reading a file`
* `return -1 when an error occurs`

**Compilation and Execution**
* `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=XX main.c get_next_line.c get_next_line_utils.c && ./a.out [file]`