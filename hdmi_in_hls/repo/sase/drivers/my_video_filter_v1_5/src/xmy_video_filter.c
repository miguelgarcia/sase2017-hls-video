// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2015.3
// Copyright (C) 2015 Xilinx Inc. All rights reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "xmy_video_filter.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMy_video_filter_CfgInitialize(XMy_video_filter *InstancePtr, XMy_video_filter_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMy_video_filter_Start(XMy_video_filter *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMy_video_filter_ReadReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_AP_CTRL) & 0x80;
    XMy_video_filter_WriteReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMy_video_filter_IsDone(XMy_video_filter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMy_video_filter_ReadReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMy_video_filter_IsIdle(XMy_video_filter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMy_video_filter_ReadReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMy_video_filter_IsReady(XMy_video_filter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMy_video_filter_ReadReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMy_video_filter_EnableAutoRestart(XMy_video_filter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMy_video_filter_WriteReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XMy_video_filter_DisableAutoRestart(XMy_video_filter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMy_video_filter_WriteReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_AP_CTRL, 0);
}

void XMy_video_filter_Set_width(XMy_video_filter *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMy_video_filter_WriteReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_WIDTH_DATA, Data);
}

u32 XMy_video_filter_Get_width(XMy_video_filter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMy_video_filter_ReadReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_WIDTH_DATA);
    return Data;
}

void XMy_video_filter_Set_height(XMy_video_filter *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMy_video_filter_WriteReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_HEIGHT_DATA, Data);
}

u32 XMy_video_filter_Get_height(XMy_video_filter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMy_video_filter_ReadReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_HEIGHT_DATA);
    return Data;
}

void XMy_video_filter_InterruptGlobalEnable(XMy_video_filter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMy_video_filter_WriteReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_GIE, 1);
}

void XMy_video_filter_InterruptGlobalDisable(XMy_video_filter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMy_video_filter_WriteReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_GIE, 0);
}

void XMy_video_filter_InterruptEnable(XMy_video_filter *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMy_video_filter_ReadReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_IER);
    XMy_video_filter_WriteReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_IER, Register | Mask);
}

void XMy_video_filter_InterruptDisable(XMy_video_filter *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMy_video_filter_ReadReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_IER);
    XMy_video_filter_WriteReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_IER, Register & (~Mask));
}

void XMy_video_filter_InterruptClear(XMy_video_filter *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMy_video_filter_WriteReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_ISR, Mask);
}

u32 XMy_video_filter_InterruptGetEnabled(XMy_video_filter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMy_video_filter_ReadReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_IER);
}

u32 XMy_video_filter_InterruptGetStatus(XMy_video_filter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMy_video_filter_ReadReg(InstancePtr->Axilites_BaseAddress, XMY_VIDEO_FILTER_AXILITES_ADDR_ISR);
}
