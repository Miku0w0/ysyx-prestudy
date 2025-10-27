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

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__top__DOT__mode;
    __Vdly__top__DOT__mode = 0;
    IData/*25:0*/ __Vdly__top__DOT__u_div__DOT__cnt;
    __Vdly__top__DOT__u_div__DOT__cnt = 0;
    CData/*5:0*/ __Vdly__top__DOT__sec;
    __Vdly__top__DOT__sec = 0;
    CData/*5:0*/ __Vdly__top__DOT__min;
    __Vdly__top__DOT__min = 0;
    CData/*4:0*/ __Vdly__top__DOT__hour;
    __Vdly__top__DOT__hour = 0;
    // Body
    vlSelf->__Vdly__top__DOT__clk_1hz = vlSelf->top__DOT__clk_1hz;
    __Vdly__top__DOT__u_div__DOT__cnt = vlSelf->top__DOT__u_div__DOT__cnt;
    __Vdly__top__DOT__mode = vlSelf->top__DOT__mode;
    __Vdly__top__DOT__hour = vlSelf->top__DOT__hour;
    __Vdly__top__DOT__min = vlSelf->top__DOT__min;
    __Vdly__top__DOT__sec = vlSelf->top__DOT__sec;
    if (vlSelf->rst) {
        __Vdly__top__DOT__u_div__DOT__cnt = 0U;
        vlSelf->__Vdly__top__DOT__clk_1hz = 0U;
        __Vdly__top__DOT__mode = 0U;
        __Vdly__top__DOT__sec = 0U;
        __Vdly__top__DOT__min = 0U;
        __Vdly__top__DOT__hour = 0U;
        vlSelf->top__DOT__u_core__DOT__running = 0U;
    } else {
        if ((0x14U == vlSelf->top__DOT__u_div__DOT__cnt)) {
            vlSelf->__Vdly__top__DOT__clk_1hz = (1U 
                                                 & (~ (IData)(vlSelf->top__DOT__clk_1hz)));
            __Vdly__top__DOT__u_div__DOT__cnt = 0U;
        } else {
            __Vdly__top__DOT__u_div__DOT__cnt = (0x3ffffffU 
                                                 & ((IData)(1U) 
                                                    + vlSelf->top__DOT__u_div__DOT__cnt));
        }
        if (((IData)(vlSelf->btn_mode) & (~ (IData)(vlSelf->top__DOT__u_mode_switcher__DOT__btn_mode_last)))) {
            __Vdly__top__DOT__mode = (1U & (~ (IData)(vlSelf->top__DOT__mode)));
        }
        if (vlSelf->btn_reset) {
            __Vdly__top__DOT__sec = 0U;
            __Vdly__top__DOT__min = 0U;
            __Vdly__top__DOT__hour = 0U;
        }
        if ((((~ (IData)(vlSelf->top__DOT__clk_1hz)) 
              & (IData)(vlSelf->top__DOT__u_core__DOT__clk_1hz_d)) 
             & (IData)(vlSelf->top__DOT__u_core__DOT__running))) {
            if ((0x3bU == (IData)(vlSelf->top__DOT__sec))) {
                if ((0x3bU == (IData)(vlSelf->top__DOT__min))) {
                    __Vdly__top__DOT__hour = ((0x17U 
                                               == (IData)(vlSelf->top__DOT__hour))
                                               ? 0U
                                               : (0x1fU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->top__DOT__hour))));
                    __Vdly__top__DOT__min = 0U;
                } else {
                    __Vdly__top__DOT__min = (0x3fU 
                                             & ((IData)(1U) 
                                                + (IData)(vlSelf->top__DOT__min)));
                }
                __Vdly__top__DOT__sec = 0U;
            } else {
                __Vdly__top__DOT__sec = (0x3fU & ((IData)(1U) 
                                                  + (IData)(vlSelf->top__DOT__sec)));
            }
        }
        if (vlSelf->btn_start) {
            vlSelf->top__DOT__u_core__DOT__running = 1U;
        }
        if (vlSelf->btn_pause) {
            vlSelf->top__DOT__u_core__DOT__running = 0U;
        }
    }
    vlSelf->top__DOT__u_div__DOT__cnt = __Vdly__top__DOT__u_div__DOT__cnt;
    vlSelf->top__DOT__mode = __Vdly__top__DOT__mode;
    vlSelf->top__DOT__sec = __Vdly__top__DOT__sec;
    vlSelf->top__DOT__min = __Vdly__top__DOT__min;
    vlSelf->top__DOT__hour = __Vdly__top__DOT__hour;
    vlSelf->top__DOT__u_mode_switcher__DOT__btn_mode_last 
        = ((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->btn_mode));
    vlSelf->top__DOT__u_core__DOT__clk_1hz_d = ((~ (IData)(vlSelf->rst)) 
                                                & (IData)(vlSelf->top__DOT__clk_1hz));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*3:0*/ __Vdly__top__DOT__stopwatch_l;
    __Vdly__top__DOT__stopwatch_l = 0;
    CData/*3:0*/ __Vdly__top__DOT__stopwatch_h;
    __Vdly__top__DOT__stopwatch_h = 0;
    CData/*7:0*/ __Vdly__top__DOT__u_led__DOT__led_cnt;
    __Vdly__top__DOT__u_led__DOT__led_cnt = 0;
    // Body
    __Vdly__top__DOT__stopwatch_h = vlSelf->top__DOT__stopwatch_h;
    __Vdly__top__DOT__stopwatch_l = vlSelf->top__DOT__stopwatch_l;
    __Vdly__top__DOT__u_led__DOT__led_cnt = vlSelf->top__DOT__u_led__DOT__led_cnt;
    if (vlSelf->rst) {
        __Vdly__top__DOT__u_led__DOT__led_cnt = 0U;
        vlSelf->led = 0U;
        vlSelf->top__DOT__u_led__DOT__led_cnt = __Vdly__top__DOT__u_led__DOT__led_cnt;
        vlSelf->top__DOT__stopwatch_overflow = 0U;
        __Vdly__top__DOT__stopwatch_l = 0U;
        __Vdly__top__DOT__stopwatch_h = 0U;
    } else {
        if (vlSelf->top__DOT__stopwatch_overflow) {
            __Vdly__top__DOT__u_led__DOT__led_cnt = 0x32U;
        } else if ((0U < (IData)(vlSelf->top__DOT__u_led__DOT__led_cnt))) {
            __Vdly__top__DOT__u_led__DOT__led_cnt = 
                (0xffU & ((IData)(vlSelf->top__DOT__u_led__DOT__led_cnt) 
                          - (IData)(1U)));
        }
        vlSelf->led = (0U < (IData)(vlSelf->top__DOT__u_led__DOT__led_cnt));
        vlSelf->top__DOT__u_led__DOT__led_cnt = __Vdly__top__DOT__u_led__DOT__led_cnt;
        vlSelf->top__DOT__stopwatch_overflow = 0U;
        if (((((~ (IData)(vlSelf->top__DOT__u_stopwatch__DOT__last_clk1hz)) 
               & (IData)(vlSelf->top__DOT__clk_1hz)) 
              & (IData)(vlSelf->btn_start)) & (~ (IData)(vlSelf->btn_pause)))) {
            if ((9U == (IData)(vlSelf->top__DOT__stopwatch_l))) {
                __Vdly__top__DOT__stopwatch_l = 0U;
                if ((9U == (IData)(vlSelf->top__DOT__stopwatch_h))) {
                    __Vdly__top__DOT__stopwatch_h = 0U;
                    vlSelf->top__DOT__stopwatch_overflow = 1U;
                } else {
                    __Vdly__top__DOT__stopwatch_h = 
                        (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__stopwatch_h)));
                }
            } else {
                __Vdly__top__DOT__stopwatch_l = (0xfU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->top__DOT__stopwatch_l)));
            }
        }
    }
    vlSelf->top__DOT__stopwatch_l = __Vdly__top__DOT__stopwatch_l;
    vlSelf->top__DOT__stopwatch_h = __Vdly__top__DOT__stopwatch_h;
    vlSelf->top__DOT__u_stopwatch__DOT__last_clk1hz 
        = vlSelf->top__DOT__clk_1hz;
}

extern const VlUnpacked<CData/*6:0*/, 16> Vtop__ConstPool__TABLE_hae6b8225_0;

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    // Init
    IData/*23:0*/ top__DOT__u_disp_mux__DOT____VdfgTmp_hdbca9b12__0;
    top__DOT__u_disp_mux__DOT____VdfgTmp_hdbca9b12__0 = 0;
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*3:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*3:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*3:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    // Body
    top__DOT__u_disp_mux__DOT____VdfgTmp_hdbca9b12__0 
        = ((IData)(vlSelf->top__DOT__mode) ? (((IData)(vlSelf->top__DOT__stopwatch_h) 
                                               << 4U) 
                                              | (IData)(vlSelf->top__DOT__stopwatch_l))
            : ((0xf00000U & (VL_DIV_III(32, (IData)(vlSelf->top__DOT__hour), (IData)(0xaU)) 
                             << 0x14U)) | ((0xf0000U 
                                            & (VL_MODDIV_III(32, (IData)(vlSelf->top__DOT__hour), (IData)(0xaU)) 
                                               << 0x10U)) 
                                           | ((0xf000U 
                                               & (VL_DIV_III(32, (IData)(vlSelf->top__DOT__min), (IData)(0xaU)) 
                                                  << 0xcU)) 
                                              | ((0xf00U 
                                                  & (VL_MODDIV_III(32, (IData)(vlSelf->top__DOT__min), (IData)(0xaU)) 
                                                     << 8U)) 
                                                 | ((0xf0U 
                                                     & (VL_DIV_III(32, (IData)(vlSelf->top__DOT__sec), (IData)(0xaU)) 
                                                        << 4U)) 
                                                    | (0xfU 
                                                       & VL_MODDIV_III(32, (IData)(vlSelf->top__DOT__sec), (IData)(0xaU)))))))));
    __Vtableidx1 = (0xfU & top__DOT__u_disp_mux__DOT____VdfgTmp_hdbca9b12__0);
    vlSelf->seg0 = Vtop__ConstPool__TABLE_hae6b8225_0
        [__Vtableidx1];
    __Vtableidx2 = (0xfU & (top__DOT__u_disp_mux__DOT____VdfgTmp_hdbca9b12__0 
                            >> 4U));
    vlSelf->seg1 = Vtop__ConstPool__TABLE_hae6b8225_0
        [__Vtableidx2];
    __Vtableidx3 = (0xfU & (top__DOT__u_disp_mux__DOT____VdfgTmp_hdbca9b12__0 
                            >> 8U));
    vlSelf->seg2 = Vtop__ConstPool__TABLE_hae6b8225_0
        [__Vtableidx3];
    __Vtableidx4 = (0xfU & (top__DOT__u_disp_mux__DOT____VdfgTmp_hdbca9b12__0 
                            >> 0xcU));
    vlSelf->seg3 = Vtop__ConstPool__TABLE_hae6b8225_0
        [__Vtableidx4];
    __Vtableidx5 = (0xfU & (top__DOT__u_disp_mux__DOT____VdfgTmp_hdbca9b12__0 
                            >> 0x10U));
    vlSelf->seg4 = Vtop__ConstPool__TABLE_hae6b8225_0
        [__Vtableidx5];
    __Vtableidx6 = (0xfU & (top__DOT__u_disp_mux__DOT____VdfgTmp_hdbca9b12__0 
                            >> 0x14U));
    vlSelf->seg5 = Vtop__ConstPool__TABLE_hae6b8225_0
        [__Vtableidx6];
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->top__DOT__clk_1hz = vlSelf->__Vdly__top__DOT__clk_1hz;
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
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
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
                    VL_FATAL_MT("/home/craics/ysyx-workbench/prestudy/labs-ysyx/lab4clock/vsrc/top.v", 1, "", "Active region did not converge.");
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
                VL_FATAL_MT("/home/craics/ysyx-workbench/prestudy/labs-ysyx/lab4clock/vsrc/top.v", 1, "", "NBA region did not converge.");
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
    if (VL_UNLIKELY((vlSelf->btn_mode & 0xfeU))) {
        Verilated::overWidthError("btn_mode");}
}
#endif  // VL_DEBUG
