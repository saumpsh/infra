/**
 * @file
 * HAL layer for CAN device - Implementation
 */

#pragma once

/******************************************************************************
 *                        I N C L U D E S
 ******************************************************************************/
/* Standard Includes */
#include <string>

/* External Includes */

/* Module Includes */
#include "hal_can_i.h"

namespace hal {

/******************************************************************************
 *                C L A S S E S
 ******************************************************************************/

class can: public can_i {
public:
  /**
   * @param can_interface Socket CAN interface (can0, vcan0, etc)
   */
    can(std::string can_interface);

    bool transmit(const struct can_frame * a_can_frame) override;
    bool receive(struct can_frame * a_can_frame, uint32_t timeout_ms = UINT_MAX) override;
    bool receive_with_filter(struct can_frame * a_can_frame, uint32_t can_id_to_receive, uint32_t mask, uint32_t timeout_ms = UINT_MAX) override;

    ~can();
private:
    int can_socket;
    bool attempt_receive(struct can_frame * a_can_frame);
    bool attempt_receive_with_filter(struct can_frame * a_can_frame, uint32_t can_id_to_receive, uint32_t mask);
    void configure_can_receive(void);
    void setup_socket_and_bind_to_can_interface(std::string can_interface);
};

}                       // End namespace
