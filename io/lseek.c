// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <sys/types.h>
#include <error_handle.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
    int ret = syscall(__NR_lseek, fd, offset, whence);

    return handle_error(ret);
}
