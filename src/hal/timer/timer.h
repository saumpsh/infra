/**
 * @file
 * Class to implement the interface `timer_i`
 */

#pragma once

/**********************************************************************************************************************/
/* Standard Includes */

/* External Includes */

/* Module Includes */
#include "timer_i.h"

/**********************************************************************************************************************/

namespace hal {

class timer : public timer_i {
public:
/**
 * Initialize a timer instance with the given parameters.
 * @param timeout_duration_ms       desired timeout duration in milliseconds
 * @param expired_on_initialization if the timer should be initialized as expired or not
 */
  timer(uint32_t timeout_duration_ms, bool expired_on_initialization);

  bool is_elapsed() override;
  void set_timeout_duration_ms(uint32_t timeout_duration_ms) override;
  void restart(void) override;

private:
  uint32_t timeout_duration_ms;
  uint32_t start_time_ms;
  bool is_time_expired;

  uint32_t get_time_ms(void);
  uint32_t get_time_elapsed_ms(uint32_t past_time_ms);
}; 

}                       // End namespace
