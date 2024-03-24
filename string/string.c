// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *dest_tmp = destination;

	while (*source) {
		*dest_tmp = *source;
		dest_tmp++;
		source++;
	}

	*dest_tmp = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	if (destination == NULL || source == NULL || len == 0)
		return NULL;

	char *dest_tmp = destination;

	while (*source && len > 0) {
		*dest_tmp = *source;
		dest_tmp++;
		source++;
		len--;
	}

	while (len > 0) {
		*dest_tmp = '\0';
		dest_tmp++;
		len--;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *dest_tmp = destination;

	while (*dest_tmp)
		dest_tmp++;

	while (*source) {
		*dest_tmp = *source;
		dest_tmp++;
		source++;
	}

	*dest_tmp = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *dest_tmp = destination;

	while (*dest_tmp)
		dest_tmp++;

	while (*source && len > 0) {
		*dest_tmp = *source;
		dest_tmp++;
		source++;
		len--;
	}

	*dest_tmp = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2)) {
		str1++;
		str2++;
	}

	return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	while (*str1 && (*str1 == *str2) && len > 0) {
		str1++;
		str2++;
		len--;
	}

	if (len == 0)
		return 0;

	return *str1 - *str2;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str) {
		if (*str == c)
			return (char *)str;

	str++;
	}

	if (c == '\0')
		return (char *)str;

	return NULL;
}

char *strrchr(const char *str, int c)
{
	char *last = NULL;

	while (*str) {
		if (*str == c)
			last = (char *)str;

		str++;
	}

	return last;
}

char *strstr(const char *haystack, const char *needle)
{
	 int len = strlen(needle);

	 while (*haystack)	{
		 if ( strncmp(haystack, needle, len) == 0)
		 	return (char *)haystack;

		haystack++;
	 }

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *last = NULL;
	int len = strlen(needle);

	while (*haystack) {
		if (strncmp(haystack, needle, len) == 0)
			last = (char *)haystack;

		haystack++;
	}

	return last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dest_tmp = (char *)destination;
	char *src_tmp = (char *)source;

	for (size_t i = 0; i < num; i++)
		dest_tmp[i] = src_tmp[i];

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dest_tmp = (char *)destination;
	char *src_tmp = (char *)source;

	if (destination > source) {
		for (size_t i = num; i > 0; i--)
			dest_tmp[i - 1] = src_tmp[i - 1];
	} else {
		for (size_t i = 0; i < num; i++)
			dest_tmp[i] = src_tmp[i];
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *ptr1_temp = (char*) ptr1;
	char *ptr2_temp = (char*) ptr2;

	for (size_t i = 0 ; i < num; i++)
		if (ptr1_temp[i] != ptr2_temp[i])
			return ptr1_temp[i] - ptr2_temp[i];

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *src_tmp = (char*) source;
	for (size_t i = 0 ; i < num; i++)
		src_tmp[i] = value;

	return source;
}
