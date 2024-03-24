#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req_time = {seconds, 0};
    struct timespec rem_time = {0, 0};

    while (nanosleep(&req_time, &rem_time) == -1 && errno == EINTR)
        req_time = rem_time;

    return rem_time.tv_sec;
}
