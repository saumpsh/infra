/***********************************************************************************************************************/
/* Main Module Header */
#include "timer_i.h"
#include "timer.h"

/* Standard Includes */
#include <memory>
#include <iostream>

/* External Includes */

/***********************************************************************************************************************/

int main(void){
  std::unique_ptr<hal::timer_i> timer = std::make_unique<hal::timer>(3000, false);

  while(!timer->is_elapsed()){
    std::cout << "Timer not expired" << std::endl;
  }
  std::cout << "Timer expired" << std::endl;

  return 0;
}
