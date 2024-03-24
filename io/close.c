// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <error_handle.h>

int close(int fd)
{
	/* TODO: Implement close(). */
    int ret = syscall(__NR_close, fd);

    return handle_error(ret);
}
