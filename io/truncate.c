// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <sys/types.h>
#include <error_handle.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
    int ret = syscall(__NR_truncate, path, length);

    return handle_error(ret);
}
