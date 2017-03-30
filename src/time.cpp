#include <ellis_op/time.hpp>

#include <time.h>


namespace ellis_op {


timeval now()
{
  struct timespec ts;
  clock_gettime(CLOCK_REALTIME_COARSE, &ts);
  return { ts.tv_sec * 1000000000L + ts.tv_nsec };
}


}  /* namespace ellis_op */
