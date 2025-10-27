// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux241.h for the primary calling header

#include "verilated.h"

#include "Vmux241___024root.h"

VL_INLINE_OPT void Vmux241___024root___ico_sequent__TOP__0(Vmux241___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux241__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux241___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->y = ((2U & (IData)(vlSelf->s)) ? ((1U & (IData)(vlSelf->s))
                                               ? (IData)(vlSelf->a3)
                                               : (IData)(vlSelf->a2))
                  : ((1U & (IData)(vlSelf->s)) ? (IData)(vlSelf->a1)
                      : (IData)(vlSelf->a0)));
}

void Vmux241___024root___eval_ico(Vmux241___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux241__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux241___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vmux241___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vmux241___024root___eval_act(Vmux241___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux241__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux241___024root___eval_act\n"); );
}

void Vmux241___024root___eval_nba(Vmux241___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux241__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux241___024root___eval_nba\n"); );
}

void Vmux241___024root___eval_triggers__ico(Vmux241___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux241___024root___dump_triggers__ico(Vmux241___024root* vlSelf);
#endif  // VL_DEBUG
void Vmux241___024root___eval_triggers__act(Vmux241___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux241___024root___dump_triggers__act(Vmux241___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux241___024root___dump_triggers__nba(Vmux241___024root* vlSelf);
#endif  // VL_DEBUG

void Vmux241___024root___eval(Vmux241___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux241__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux241___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<0> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vmux241___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vmux241___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("mux241.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vmux241___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vmux241___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vmux241___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("mux241.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vmux241___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vmux241___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("mux241.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vmux241___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vmux241___024root___eval_debug_assertions(Vmux241___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux241__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux241___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->a0 & 0xfcU))) {
        Verilated::overWidthError("a0");}
    if (VL_UNLIKELY((vlSelf->a1 & 0xfcU))) {
        Verilated::overWidthError("a1");}
    if (VL_UNLIKELY((vlSelf->a2 & 0xfcU))) {
        Verilated::overWidthError("a2");}
    if (VL_UNLIKELY((vlSelf->a3 & 0xfcU))) {
        Verilated::overWidthError("a3");}
    if (VL_UNLIKELY((vlSelf->s & 0xfcU))) {
        Verilated::overWidthError("s");}
}
#endif  // VL_DEBUG
