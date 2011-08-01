#ifndef TIMER_H_
#define TIMER_H_

#include <time.h>
#include <sys/time.h>


#define CPU_TIME        CLOCK_PROCESS_CPUTIME_ID
#define WALLCLOCK_TIME  CLOCK_MONOTONIC

/*
 * Timer that can measure cpu time or wall clock time.
 */
class Timer {
public:
    /*
     * Timer automatically starts on creation, but can be reset any time.
     */
    Timer(clockid_t clockId): clockId(clockId) {
        restart();
    }
    float elapsed() {
        timespec endTime;
        clock_gettime(this->clockId, &endTime);
        return (endTime.tv_sec - this->startTime.tv_sec) + (endTime.tv_nsec - this->startTime.tv_nsec) / 1000000000.0;
    }
    void restart(){
        clock_gettime(this->clockId, &this->startTime);
    }
private:
    timespec startTime;
    clockid_t clockId;
};

#endif /* TIMER_H_ */
