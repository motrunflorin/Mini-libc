#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <internal/syscall.h>
#include <stdlib.h>
#include <error_handle.h>

int puts(const char *s) {
    size_t len = strlen(s);
    char *buf = (char *)malloc(len + 2);

    if (buf == NULL) {
        errno = ENOMEM;
        return -1;
    }

    strcpy(buf, s);
    strcat(buf, "\n");

    int ret = syscall(1, 1, buf, len + 1);
    free(buf);

    return handle_error(ret);
}
