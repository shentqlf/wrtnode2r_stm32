/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010 Perry Hung.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @brief Main include file for the Wirish core.
 *
 * Includes most of Wirish, and (transitively or otherwise)
 * substantial pieces of libmaple proper.
 */

#ifndef _WIRISH_WIRISH_H_
#define _WIRISH_WIRISH_H_

#include <stdint.h>
#include <stdbool.h>

#include <libmaple/stm32.h>

#include <wirish/boards.h>
#include <wirish/io.h>
#include <wirish/bit_constants.h>
#include <wirish/pwm.h>
#include <wirish/ext_interrupts.h>
//#include <wirish/wirish_debug.h>
//#include <wirish/wirish_math.h>
#include <wirish/wirish_time.h>
#ifndef MAPLE_USE_WIRISHC
#include <wirish/HardwareSPI.h>
#include <wirish/HardwareSerial.h>
#include <wirish/HardwareTimer.h>
#else
#include <wirishC/HardwareSPI.h>
#include <wirishC/HardwareSerial.h>
#include <wirishC/HardwareTimer.h>
#endif /* MAPLE_USE_WIRISHC */
#if (BOARD_HAVE_SERIALUSB)
#ifndef MAPLE_USE_WIRISHC
#include <wirish/usb_serial.h>
#else
#include <wirishC/usb_serial.h>
#endif /* MAPLE_USE_WIRISHC */
#endif
#include <wirish/wirish_types.h>

#include <libmaple/libmaple.h>

/* Wiring macros and bit defines */

#define LSBFIRST 0
#define MSBFIRST 1

#define lowByte(w)                     ((w) & 0xFF)
#define highByte(w)                    (((w) >> 8) & 0xFF)
#define bitRead(value, bit)            (((value) >> (bit)) & 0x01)
#define bitSet(value, bit)             ((value) |= (1UL << (bit)))
#define bitClear(value, bit)           ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : \
                                                   bitClear(value, bit))
#define bit(b)                         (1UL << (b))

#endif

