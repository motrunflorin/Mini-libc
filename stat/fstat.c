// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <error_handle.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	int ret = syscall(__NR_fstat, fd, st);

	return handle_error(ret);
}
