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
    VL_OUT8(seg0,6,0);
    VL_OUT8(seg1,6,0);
    VL_OUT8(led,0,0);
    CData/*0:0*/ top__DOT__clk_1hz;
    CData/*3:0*/ top__DOT__digit_l;
    CData/*3:0*/ top__DOT__digit_h;
    CData/*0:0*/ top__DOT__overflow;
    CData/*0:0*/ top__DOT__start;
    CData/*0:0*/ top__DOT__pause;
    CData/*7:0*/ top__DOT__u_div__DOT__cnt;
    CData/*0:0*/ top__DOT__u_cnt__DOT__last_clk1hz;
    CData/*7:0*/ top__DOT__u_led__DOT__led_cnt;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__rst;
    CData/*0:0*/ __VactContinue;
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
