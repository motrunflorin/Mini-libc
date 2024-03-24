// SPDX-License-Identifier: BSD-3-Clause

#include <error_handle.h>
#include <errno.h>
#include <sys/mman.h>

int handle_error(int ret)
{
	if (ret >= 0)
		return ret;

	errno = -ret;
	return -1;
}

void *handle_error_map(long ret)
{
	if (ret >= 0)
		return (void *) ret;

	errno = -ret;
	return MAP_FAILED;
}
