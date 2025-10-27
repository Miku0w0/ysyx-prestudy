// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(btn_start,0,0);
    VL_IN8(btn_pause,0,0);
    VL_IN8(btn_reset,0,0);
    VL_IN8(btn_mode,0,0);
    VL_OUT8(led,0,0);
    VL_OUT8(seg0,6,0);
    VL_OUT8(seg1,6,0);
    VL_OUT8(seg2,6,0);
    VL_OUT8(seg3,6,0);
    VL_OUT8(seg4,6,0);
    VL_OUT8(seg5,6,0);
    CData/*0:0*/ top__DOT__clk_1hz;
    CData/*5:0*/ top__DOT__sec;
    CData/*5:0*/ top__DOT__min;
    CData/*4:0*/ top__DOT__hour;
    CData/*3:0*/ top__DOT__stopwatch_l;
    CData/*3:0*/ top__DOT__stopwatch_h;
    CData/*0:0*/ top__DOT__stopwatch_overflow;
    CData/*0:0*/ top__DOT__mode;
    CData/*0:0*/ top__DOT__u_mode_switcher__DOT__btn_mode_last;
    CData/*0:0*/ top__DOT__u_core__DOT__running;
    CData/*0:0*/ top__DOT__u_core__DOT__clk_1hz_d;
    CData/*0:0*/ top__DOT__u_stopwatch__DOT__last_clk1hz;
    CData/*7:0*/ top__DOT__u_led__DOT__led_cnt;
    CData/*0:0*/ __Vdly__top__DOT__clk_1hz;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__rst;
    CData/*0:0*/ __VactContinue;
    IData/*25:0*/ top__DOT__u_div__DOT__cnt;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
