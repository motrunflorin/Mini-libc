// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <error_handle.h>
#include <internal/syscall.h>
#include <errno.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	long ret = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

	return handle_error_map(ret);
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long ret = syscall(__NR_mremap, old_address, old_size, new_size, flags);

	return handle_error_map(ret);
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	long ret = syscall(__NR_munmap, addr, length);

	if (ret >= 0)
        return 0;

	errno = -ret;
	return -1;
}
