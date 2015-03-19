#include "libabs.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    const char *in = "hello ABS\n";
    char buffer[1024];
    abs_putdata(in, strlen(in));
    abs_getdata(buffer, 1024);
    printf("%s", buffer);
    printf("\n");
    abs_clear();

    return 0;
}
