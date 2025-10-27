// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*6:0*/, 16> Vtop__ConstPool__TABLE_hae6b8225_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*0:0*/ __Vdly__top__DOT__pause;
    __Vdly__top__DOT__pause = 0;
    CData/*3:0*/ __Vdly__top__DOT__digit_l;
    __Vdly__top__DOT__digit_l = 0;
    CData/*3:0*/ __Vdly__top__DOT__digit_h;
    __Vdly__top__DOT__digit_h = 0;
    CData/*7:0*/ __Vdly__top__DOT__u_led__DOT__led_cnt;
    __Vdly__top__DOT__u_led__DOT__led_cnt = 0;
    // Body
    __Vdly__top__DOT__pause = vlSelf->top__DOT__pause;
    __Vdly__top__DOT__digit_h = vlSelf->top__DOT__digit_h;
    __Vdly__top__DOT__digit_l = vlSelf->top__DOT__digit_l;
    __Vdly__top__DOT__u_led__DOT__led_cnt = vlSelf->top__DOT__u_led__DOT__led_cnt;
    if (vlSelf->btn_pause) {
        __Vdly__top__DOT__pause = (1U & (~ (IData)(vlSelf->top__DOT__pause)));
    }
    if (vlSelf->btn_reset) {
        __Vdly__top__DOT__pause = 0U;
        __Vdly__top__DOT__u_led__DOT__led_cnt = 0U;
        vlSelf->led = 0U;
        vlSelf->top__DOT__u_led__DOT__led_cnt = __Vdly__top__DOT__u_led__DOT__led_cnt;
        vlSelf->top__DOT__overflow = 0U;
        __Vdly__top__DOT__digit_l = 0U;
        __Vdly__top__DOT__digit_h = 0U;
    } else {
        if (vlSelf->top__DOT__overflow) {
            __Vdly__top__DOT__u_led__DOT__led_cnt = 0x32U;
        } else if ((0U < (IData)(vlSelf->top__DOT__u_led__DOT__led_cnt))) {
            __Vdly__top__DOT__u_led__DOT__led_cnt = 
                (0xffU & ((IData)(vlSelf->top__DOT__u_led__DOT__led_cnt) 
                          - (IData)(1U)));
        }
        vlSelf->led = (0U < (IData)(vlSelf->top__DOT__u_led__DOT__led_cnt));
        vlSelf->top__DOT__u_led__DOT__led_cnt = __Vdly__top__DOT__u_led__DOT__led_cnt;
        vlSelf->top__DOT__overflow = 0U;
        if (((((~ (IData)(vlSelf->top__DOT__u_cnt__DOT__last_clk1hz)) 
               & (IData)(vlSelf->top__DOT__clk_1hz)) 
              & (IData)(vlSelf->top__DOT__start)) & 
             (~ (IData)(vlSelf->top__DOT__pause)))) {
            if ((9U == (IData)(vlSelf->top__DOT__digit_l))) {
                __Vdly__top__DOT__digit_l = 0U;
                if ((9U == (IData)(vlSelf->top__DOT__digit_h))) {
                    __Vdly__top__DOT__digit_h = 0U;
                    vlSelf->top__DOT__overflow = 1U;
                } else {
                    __Vdly__top__DOT__digit_h = (0xfU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->top__DOT__digit_h)));
                }
            } else {
                __Vdly__top__DOT__digit_l = (0xfU & 
                                             ((IData)(1U) 
                                              + (IData)(vlSelf->top__DOT__digit_l)));
            }
        }
    }
    vlSelf->top__DOT__pause = __Vdly__top__DOT__pause;
    vlSelf->top__DOT__digit_l = __Vdly__top__DOT__digit_l;
    vlSelf->top__DOT__digit_h = __Vdly__top__DOT__digit_h;
    __Vtableidx1 = vlSelf->top__DOT__digit_l;
    vlSelf->seg0 = Vtop__ConstPool__TABLE_hae6b8225_0
        [__Vtableidx1];
    __Vtableidx2 = vlSelf->top__DOT__digit_h;
    vlSelf->seg1 = Vtop__ConstPool__TABLE_hae6b8225_0
        [__Vtableidx2];
    vlSelf->top__DOT__u_cnt__DOT__last_clk1hz = vlSelf->top__DOT__clk_1hz;
    if (vlSelf->btn_start) {
        vlSelf->top__DOT__start = 1U;
    }
    if (vlSelf->btn_reset) {
        vlSelf->top__DOT__start = 0U;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*7:0*/ __Vdly__top__DOT__u_div__DOT__cnt;
    __Vdly__top__DOT__u_div__DOT__cnt = 0;
    CData/*0:0*/ __Vdly__top__DOT__clk_1hz;
    __Vdly__top__DOT__clk_1hz = 0;
    // Body
    __Vdly__top__DOT__clk_1hz = vlSelf->top__DOT__clk_1hz;
    __Vdly__top__DOT__u_div__DOT__cnt = vlSelf->top__DOT__u_div__DOT__cnt;
    if (vlSelf->rst) {
        __Vdly__top__DOT__u_div__DOT__cnt = 0U;
        __Vdly__top__DOT__clk_1hz = 0U;
    } else if ((0x14U == (IData)(vlSelf->top__DOT__u_div__DOT__cnt))) {
        __Vdly__top__DOT__clk_1hz = (1U & (~ (IData)(vlSelf->top__DOT__clk_1hz)));
        __Vdly__top__DOT__u_div__DOT__cnt = 0U;
    } else {
        __Vdly__top__DOT__u_div__DOT__cnt = (0xffU 
                                             & ((IData)(1U) 
                                                + (IData)(vlSelf->top__DOT__u_div__DOT__cnt)));
    }
    vlSelf->top__DOT__u_div__DOT__cnt = __Vdly__top__DOT__u_div__DOT__cnt;
    vlSelf->top__DOT__clk_1hz = __Vdly__top__DOT__clk_1hz;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/craics/ysyx-workbench/prestudy/labs-ysyx/lab4clk/vsrc/top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/craics/ysyx-workbench/prestudy/labs-ysyx/lab4clk/vsrc/top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->btn_start & 0xfeU))) {
        Verilated::overWidthError("btn_start");}
    if (VL_UNLIKELY((vlSelf->btn_pause & 0xfeU))) {
        Verilated::overWidthError("btn_pause");}
    if (VL_UNLIKELY((vlSelf->btn_reset & 0xfeU))) {
        Verilated::overWidthError("btn_reset");}
}
#endif  // VL_DEBUG
