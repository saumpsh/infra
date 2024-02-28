#include <gtest/gtest.h>
#include "fff.h"

#include "hello_fff.h"

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(DISPLAY_init);


TEST(GreeterTests, init_initialises_display)
{
    UI_init();
    ASSERT_EQ(DISPLAY_init_fake.call_count, 1);
}
