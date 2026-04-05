/**
 * cf03_driver.cpp — CWClockfaceDriver adapter for cw-cf-0x03 (World Map)
 * v3 bridge: wraps the v2 CF03::Clockface class in the function-pointer API.
 */

#include "Clockface03.h"        // v2 class, namespace CF03
#include <CWClockfaceDriver.h>     // v3 driver API

static CF03::Clockface* s_face = nullptr;

static void cf03_setup(Adafruit_GFX* display, CWDateTime* dateTime) {
    if (!s_face) s_face = new CF03::Clockface(display);
    s_face->setup(dateTime);
}

static void cf03_update() {
    if (s_face) s_face->update();
}

static void cf03_teardown() {
    // Instance kept alive for fast re-activation.
}

CWClockfaceDriver cf_worldmap = {
    .name     = "World Map",
    .index    = 2,
    .setup    = cf03_setup,
    .update   = cf03_update,
    .teardown = cf03_teardown,
};
