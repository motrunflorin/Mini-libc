#include "time.h"
#include "errno.h"
#include "internal/syscall.h"

int nanosleep(struct timespec *req, struct timespec *rem) {
	long val = syscall(__NR_nanosleep, req, rem);

	if (val == 0) {
		return 0;
	} else if (val == -1 && errno == EINTR) {
		return -1;
	} else {
		errno = -val;
		return -1;
	}
}
