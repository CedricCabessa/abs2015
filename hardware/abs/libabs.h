#ifndef __ABS__
#define __ABS__

#include <sys/types.h>

ssize_t abs_getdata(void *buf, size_t count);

ssize_t abs_putdata(const void *buf, size_t count);

void abs_clear(void);

#endif /* __ABS__ */
