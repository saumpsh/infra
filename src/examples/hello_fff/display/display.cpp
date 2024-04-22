#include <assert.h>

void DISPLAY_init(){
    // Added to ensure that Unit test does not link the real `display.o` file and instead uses mocked `DISPLAY_init` function
    assert(false);
}