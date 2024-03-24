// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <error_handle.h>

ssize_t write(int fd, const void *buf, size_t len)
{
	int ret = syscall(__NR_write, fd, buf, len);

	return handle_error(ret);
}

ssize_t read(int fd, void *buf, size_t len)
{
	int ret =  syscall(__NR_read, fd, buf, len);

	return handle_error(ret);
}
