#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

int nanosleep(struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
