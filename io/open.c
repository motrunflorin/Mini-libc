// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <error_handle.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
    va_list args;
    va_start(args, flags);
    mode_t mode = 0;

    if (flags & O_CREAT)
        mode = va_arg(args, mode_t);

    int ret = syscall(__NR_open, filename, flags, mode);

    va_end(args);

    return handle_error(ret);
}
