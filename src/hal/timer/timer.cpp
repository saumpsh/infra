/***********************************************************************************************************************/

/* Main Module Header */
#include "timer.h"

/* Standard Includes */
#include <chrono>

/* External Includes */

/***********************************************************************************************************************/

uint32_t hal::timer::get_time_ms(void){
    auto now = std::chrono::high_resolution_clock::now();

    // Conversion to milliseconds
    uint32_t milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    return milliseconds;
}

uint32_t hal::timer::get_time_elapsed_ms(uint32_t past_time_ms) {
  return (this->get_time_ms() - past_time_ms);
}

/***********************************************************************************************************************/

hal::timer::timer(uint32_t timeout_duration_ms, bool expired_on_initialization) {
  this->timeout_duration_ms = timeout_duration_ms;
  this->start_time_ms = get_time_ms();
  this->is_time_expired = expired_on_initialization;
}

bool hal::timer::is_elapsed(){
  bool is_elapsed = true;

  if (!this->is_time_expired) {
    this->is_time_expired = (get_time_elapsed_ms(this->start_time_ms) >= this->timeout_duration_ms);
    is_elapsed = this->is_time_expired;
  }

  return is_elapsed;
}

void hal::timer::set_timeout_duration_ms(uint32_t timeout_duration_ms){
  this->timeout_duration_ms = timeout_duration_ms;
}

void hal::timer::restart(void){
  this->is_time_expired = false;
  this->start_time_ms = get_time_ms();
}
