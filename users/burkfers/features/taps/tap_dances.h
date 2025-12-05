// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "quantum.h"

// Define a type for as many tap dance states as you need
typedef enum { TD_NONE, TD_UNKNOWN, TD_SINGLE_TAP, TD_SINGLE_HOLD, TD_DOUBLE_TAP } td_state_t;

extern tap_dance_action_t tap_dance_actions[];

typedef struct {
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

// Our custom TD keys
enum {
    U_TD_BOOT,
    U_TD_CLR,
#ifdef EE_HANDS
    U_TD_MAKER,
    U_TD_MAKEL,
#else
    U_TD_MAKE,
#endif
    U_TD_SYSRQ,
    U_SLS_PT,
};

void u_td_fn_boot(tap_dance_state_t *, void *);
#ifdef EE_HANDS
void u_td_fn_make_l(tap_dance_state_t *, void *) void u_td_fn_make_r(tap_dance_state_t *, void *);
#else
void u_td_fn_make(tap_dance_state_t *, void *);
#endif
void u_td_fn_sysrq_reisub(tap_dance_state_t *, void *);
void u_td_fn_clr(tap_dance_state_t *, void *);
