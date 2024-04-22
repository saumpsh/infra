/**
 * @file
 * HAL layer for OS Timer
 * Simple Timer module. Timer will stay expired until sl_timer__reset is called.
 */

#pragma once

/**********************************************************************************************************************/
/* Standard Includes */
#include <stdint.h>

/* External Includes */

/* Module Includes */



/**********************************************************************************************************************/
namespace hal {

class timer_i {
public:
  /**
   * Check if the timer has elapsed/expired.
   * The timer is considered expired if the time elapsed during initialization has passed.
   * @return True if the timer is expired or has not been initialized yet; else false if the timer is not expired
   */
  virtual bool is_elapsed() = 0;

  /**
 * Set the timeout duration for the given timer.
 * Set duration to 0 to stop a timer. Does not reset the start time.
 * @param timeout_duration_ms desired timeout duration in milliseconds
 */
  virtual void set_timeout_duration_ms(uint32_t timeout_duration_ms) = 0;

  /**
 * Restart a timer.
 * Restart will clear timer expiration and reset the start time.
 * @return        true: timer restarted; false: failed
 */
  virtual void restart(void) = 0;

  virtual ~timer_i(){};
};

}                       // End namespace
