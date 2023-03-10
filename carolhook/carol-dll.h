#pragma once

#include <windows.h>

#include "carolio/carolio.h"

struct carol_dll {
    uint16_t api_version;
    HRESULT (*jvs_init)(void);
    void (*jvs_poll)(uint8_t *opbtn, uint8_t *beams);
    void (*jvs_read_coin_counter)(uint16_t *total);
    HRESULT (*controlbd_init)(void);
    void (*controlbd_start)(carol_io_controlbd_callback_t callback);
    void (*controlbd_stop)(void);
};

struct carol_dll_config {
    wchar_t path[MAX_PATH];
};

extern struct carol_dll carol_dll;

HRESULT carol_dll_init(const struct carol_dll_config *cfg, HINSTANCE self);
