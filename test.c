#include "so_long.h"

int main()
{
    char *line;
    int   i;

    i = 0;
    int fd = open("map.ber", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        i++;
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    printf("i ->%d\n", i);
}