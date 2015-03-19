#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define ABS_DEV "/dev/abs"
#define MAX_SIZE 1024


ssize_t abs_getdata(void *buf, size_t count)
{
    int fd = open(ABS_DEV, O_RDONLY);
    ssize_t ret = read(fd, buf, count);
    close(fd);
    return ret;
}


ssize_t abs_putdata(const void *buf, size_t count)
{
    int fd = open(ABS_DEV, O_WRONLY);
    // assume input is null terminated. No check
    ssize_t ret = write(fd, buf, count+1);
    close(fd);
    return ret;
}

void abs_clear(void)
{
    int fd = open(ABS_DEV, O_WRONLY);
    write(fd, 0, 0);
}
