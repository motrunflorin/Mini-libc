// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	size_t total_size = size + sizeof(size_t);
    void *start = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (start != MAP_FAILED) {
        size_t *size_ptr = start;
        *size_ptr = total_size;

        mem_list_add((char *)start + sizeof(size_t), size);
        return (char *)start + sizeof(size_t);
    }

    return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;

    void *start = malloc(total_size);

    if (start)
        memset(start, 0, total_size);

    return start;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *item = mem_list_find(ptr);

    if (item != NULL) {
        size_t total_size = *((size_t *)ptr - 1) + sizeof(size_t);

        mem_list_del(ptr);
        munmap((char *)ptr - sizeof(size_t), total_size);
    }
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL)
        return malloc(size);

    size_t old_size = *((size_t *)ptr - 1);
    void *start = malloc(size);

    if (start) {
        size_t copy_size;

		if (size < old_size)
    		copy_size = size;
		else
    		copy_size = old_size;

        if (copy_size > 0)
            memcpy(start, ptr, copy_size);

        free(ptr);
    }

    return start;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	void *start = realloc(ptr, nmemb * size);

	if (start == NULL) {
		errno = ENOMEM;
		return NULL;
	}

	return start;
}
