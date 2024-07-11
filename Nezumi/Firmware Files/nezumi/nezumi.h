/* 
This file exists solely to allow the user to create and define a custom LED matrix or RGB matrix for the Nezumi that uses a non-standard style of LED.
*/

#pragma once

#include "quantum.h"
#include <stdint.h>
#include <stdbool.h>

extern bool set_arrow;

void init_nezumi(void);
