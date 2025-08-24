#ifndef	_SYS_TIME_H
#define _SYS_TIME_H

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

#endif