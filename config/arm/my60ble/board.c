/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/init.h>

static int my60ble_init(void)
{
    return 0;
}

SYS_INIT(my60ble_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
