// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <sys/types.h>
#include <error_handle.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
    int ret = syscall(__NR_ftruncate, fd, length);

    return handle_error(ret);
}
