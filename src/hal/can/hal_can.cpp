/***********************************************************************************************************************
 *
 *                                                  I N C L U D E S
 *
 **********************************************************************************************************************/
/* Main Module Header */
#include "hal_can.h"

/* Standard Includes */
#include <unistd.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <string.h>
#include <fcntl.h>
#include <chrono>
#include <thread>
#include <bitset>
#include <sstream>
#include <iostream>

/* External Includes */
#include "absl/log/log.h"
#include "timer_i.h"
#include "timer.h"

/***********************************************************************************************************************
 *
 *                               P R O T E C T E D / P R I V A T E   F U N C T I O N S
 *
 **********************************************************************************************************************/
bool hal::can::attempt_receive(struct can_frame * a_can_frame){
    ssize_t nbytes_received = read(this->can_socket, a_can_frame, sizeof(struct can_frame));

    return ((ssize_t)CAN_MTU == nbytes_received);
}

bool hal::can::attempt_receive_with_filter(struct can_frame * a_can_frame, uint32_t can_id_to_receive, uint32_t mask){
    ssize_t nbytes_received = read(this->can_socket, a_can_frame, sizeof(struct can_frame));

    bool is_can_frame_valid = ((ssize_t)CAN_MTU == nbytes_received);
    bool does_can_frame_match_filter = (can_id_to_receive & mask) == (a_can_frame->can_id & mask);

    return is_can_frame_valid && does_can_frame_match_filter;
}

void hal::can::configure_can_receive(void){
    //  Set CAN read to non-blocking
    int flags = fcntl(this->can_socket, F_GETFL, 0);
    if (-1 != flags) {
      flags |= (O_NONBLOCK | SO_RCVTIMEO);
      if(-1 == fcntl(this->can_socket, F_SETFL, flags)){
        LOG(ERROR) << " Failed to set Socket CAN status flags !";
      }
    }
}

void hal::can::setup_socket_and_bind_to_can_interface(std::string can_interface){
    // Setup socket address
    struct sockaddr_can addr;
    struct ifreq ifr;
    strcpy(ifr.ifr_name, can_interface.c_str());
    ioctl(this->can_socket, SIOCGIFINDEX, &ifr);
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    // Bind socket to the CAN interface
    if (bind(this->can_socket, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        LOG(ERROR) << " Failed to bind socket to the CAN interface " << can_interface ;
        close(this->can_socket);
        return;
    }
}

/***********************************************************************************************************************
 *
 *                                          P U B L I C   F U N C T I O N S
 *
 **********************************************************************************************************************/

hal::can::can(std::string can_interface) {
    // Create socket
    if ((this->can_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        LOG(ERROR) << " CAN Socket creation failed !";
        return;
    }

    this->configure_can_receive();

    this->setup_socket_and_bind_to_can_interface(can_interface);
}

bool hal::can::transmit(const struct can_frame * a_can_frame){
    bool can_frame_sent = true;

    ssize_t nbytes = write(this->can_socket, a_can_frame, sizeof(struct can_frame));
    if (nbytes != sizeof(struct can_frame)) {
        LOG(WARNING) << " Failed to send CAN frame !";
        can_frame_sent = false;
    }

    return can_frame_sent;
}

bool hal::can::receive(struct can_frame * a_can_frame, uint32_t timeout_ms){
    bool can_frame_received = false;

    std::unique_ptr<hal::timer_i> timer = std::make_unique<hal::timer>(timeout_ms, false);
    do {
      can_frame_received = this->attempt_receive(a_can_frame);
      if (!can_frame_received) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
      }
    } while (!timer->is_elapsed() && (!can_frame_received));

    if(!can_frame_received){
        LOG(WARNING) << " Failed to receive CAN frame for " << timeout_ms << " miliseconds";
    }

    return can_frame_received;
}

bool hal::can::receive_with_filter(struct can_frame * a_can_frame, uint32_t can_id_to_receive, uint32_t mask, uint32_t timeout_ms){
    bool can_frame_received = false;

    std::unique_ptr<hal::timer_i> timer = std::make_unique<hal::timer>(timeout_ms, false);
    do {
      can_frame_received = this->attempt_receive_with_filter(a_can_frame, can_id_to_receive, mask);
      if (!can_frame_received) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
      }
    } while (!timer->is_elapsed() && (!can_frame_received));

    if(!can_frame_received){
        LOG(WARNING) << " Failed to receive CAN frame for " << timeout_ms << " miliseconds for CAN_ID:mask " << std::hex << 
            can_id_to_receive <<  ":" << std::hex << mask  ;
    }

    return can_frame_received;
}

hal::can::~can(){
    close(this->can_socket);
}
