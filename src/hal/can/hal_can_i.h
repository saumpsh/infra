/**
 * @file
 * HAL layer for CAN device
 */

#pragma once

/***********************************************************************************************************************
 *
 *                                                  I N C L U D E S
 *
 **********************************************************************************************************************/
/* Standard Includes */
#include <stdint.h>
#include <stddef.h>
#include <linux/can.h>
#include <limits.h>

/* External Includes */

/* Module Includes */

namespace hal {


/***********************************************************************************************************************
 *
 *                                                   C L A S S E S
 *
 **********************************************************************************************************************/

class can_i {
public:
  /**
   * Transmits a single CAN frame
   * This is a blocking call i.e. the API will not return until the CAN frame has been sent on the CAN bus
   * 
   * @return True if transmit is success
   */
    virtual bool transmit(const struct can_frame * a_can_frame) = 0;

  /**
   * Receive a single CAN frame if available within the provided timeout
   * If the timeout_ms argument is not provided this becomes equivalent to  blocking call i.e. the default time_out == 4,294,967,295 ms == 49 days
   * 
   * @param timeout_ms desired timeout duration in milliseconds
   * 
   * @return True if CAN frame is received within the time out.
   */
    virtual bool receive(struct can_frame * a_can_frame, uint32_t timeout_ms = UINT_MAX) = 0;

   /**
   * Receive a single CAN frame when (<received_can_id> & mask == can_id & mask) within the provided timeout
   * If the timeout_ms argument is not provided this becomes equivalent to  blocking call i.e. the default time_out == 4,294,967,295 ms == 49 days
   * 
   * @param mask Bit mask value. Mask value 0x77f is used to get a specific single CAN frame
   * @param timeout_ms desired timeout duration in milliseconds
   * 
   * @return True if CAN frame is received within the time out.
   */
    virtual bool receive_with_filter(struct can_frame * a_can_frame, uint32_t can_id_to_receive, uint32_t mask, uint32_t timeout_ms = UINT_MAX) = 0;

    virtual ~can_i(){};
};

}                       // End namespace
