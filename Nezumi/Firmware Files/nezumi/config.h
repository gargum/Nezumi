/* Created in 2024 by Gareth Gummow <https://github.com/gargum> (@gargum)

This program is a program. Please take very good care of it.
*/

#pragma once

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define USB_SUSPEND_WAKEUP_DELAY 200

#define TAPPING_TERM 185
#define TAPPING_TOGGLE 1

#define I2C1_SCL_PIN GP7
#define I2C1_SDA_PIN GP6

#define MOUSE_EXTENDED_REPORT
#define CIRQUE_PINNACLE_CIRCULAR_SCROLL_ENABLE
#define CIRQUE_PINNACLE_DIAMETER_MM 40
// #define CIRQUE_PINNACLE_CURVED_OVERLAY /* Uncomment this line if your Cirque does have a curved overlay. */
#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
