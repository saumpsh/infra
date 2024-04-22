/***********************************************************************************************************************
 *
 *                                                  I N C L U D E S
 *
 **********************************************************************************************************************/
/* Main Module Header */
#include "hal_can_i.h"
#include "hal_can.h"

/* Standard Includes */
#include <memory>
#include <iostream>
#include <string.h>
#include <cassert>

/* External Includes */

/***********************************************************************************************************************
 *
 *                                          P U B L I C   F U N C T I O N S
 *
 **********************************************************************************************************************/

int main(void){
  std::unique_ptr<hal::can_i> vcan_0 = std::make_unique<hal::can>("vcan0");

  struct can_frame a_can_frame = {0};
  uint8_t data[] = {'D', 'E', 'A', 'D', 'B', 'E', 'E', 'F'};
  memcpy(a_can_frame.data, data, sizeof(data));
  a_can_frame.can_dlc = sizeof(data);
  a_can_frame.can_id = 0x123;

  vcan_0->transmit(&a_can_frame);

  struct can_frame a_can_frame_receive;
  vcan_0->receive(&a_can_frame_receive, 5000);

  // Assert this to verify behavior
  vcan_0->receive_with_filter(&a_can_frame_receive, 0x124, 0x7ff, 5000);

  return 0;
}
