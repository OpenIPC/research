/* SigmaStar trade secret */
/* Copyright (c) [2019~2020] SigmaStar Technology.
All rights reserved.

Unless otherwise stipulated in writing, any and all information contained
herein regardless in any format shall remain the sole proprietary of
SigmaStar and be kept in strict confidence
(SigmaStar Confidential Information) by the recipient.
Any unauthorized act including without limitation unauthorized disclosure,
copying, use, reproduction, sale, distribution, modification, disassembling,
reverse engineering and compiling of the contents of SigmaStar Confidential
Information is unlawful and strictly prohibited. SigmaStar hereby reserves the
rights to any and all damages, losses, costs and expenses resulting therefrom.
*/
#ifndef _MI_ISP_H_
#define _MI_ISP_H_

#include "mi_isp_datatype.h"

#define ISP_MAJOR_VERSION   3
#define ISP_SUB_VERSION     0
#define MACRO_TO_STR(macro) #macro
#define ISP_VERSION_STR(major_version, sub_version)                                                                 \
    (                                                                                                               \
        {                                                                                                           \
            char *tmp =                                                                                             \
                sub_version / 100  ? "mi_isp_version_" MACRO_TO_STR(major_version) "." MACRO_TO_STR(sub_version)    \
                : sub_version / 10 ? "mi_isp_version_" MACRO_TO_STR(major_version) ".0" MACRO_TO_STR(sub_version)   \
                                   : "mi_isp_version_" MACRO_TO_STR(major_version) ".00" MACRO_TO_STR(sub_version); \
            tmp;                                                                                                    \
        })
#define MI_ISP_API_VERSION VPE_VERSION_STR(ISP_MAJOR_VERSION, ISP_SUB_VERSION)

#ifdef __cplusplus
extern "C"
{
#endif

    MI_S32 MI_ISP_CreateDevice(MI_ISP_DEV DevId, MI_ISP_DevAttr_t *pstDevAttr);
    MI_S32 MI_ISP_DestoryDevice(MI_ISP_DEV DevId);

    MI_S32 MI_ISP_CreateChannel(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_ChannelAttr_t *pstChAttr);
    MI_S32 MI_ISP_DestroyChannel(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId);

    MI_S32 MI_ISP_SetInputPortCrop(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_SYS_WindowRect_t *pstCropInfo);
    MI_S32 MI_ISP_GetInputPortCrop(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_SYS_WindowRect_t *pstCropInfo);

    MI_S32 MI_ISP_SetChnParam(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_ChnParam_t *pstChnParam);
    MI_S32 MI_ISP_GetChnParam(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_ChnParam_t *pstChnParam);
    MI_S32 MI_ISP_GetSubChnId(MI_ISP_DEV DevId, MI_ISP_CHANNEL MainChnId, MI_ISP_BindSnrId_e eSensorBindId,
                              MI_U32 *pu32SubChnId);

    MI_S32 MI_ISP_SetSubChnParam(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_SUB_CHANNEL SubChnId,
                                 MI_ISP_ChnParam_t *pstChnParam);
    MI_S32 MI_ISP_GetSubChnParam(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_SUB_CHANNEL SubChnId,
                                 MI_ISP_ChnParam_t *pstChnParam);

    MI_S32 MI_ISP_StartChannel(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId);
    MI_S32 MI_ISP_StopChannel(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId);

    MI_S32 MI_ISP_SetOutputPortParam(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_PORT PortId,
                                     MI_ISP_OutPortParam_t *pstOutPortParam);
    MI_S32 MI_ISP_GetOutputPortParam(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_PORT PortId,
                                     MI_ISP_OutPortParam_t *pstOutPortParam);

    MI_S32 MI_ISP_EnableOutputPort(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_PORT PortId);
    MI_S32 MI_ISP_DisableOutputPort(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_PORT PortId);

    MI_S32 MI_ISP_Alloc_IQDataBuf(MI_U32 u32Size, void **pUserVirAddr); // NOLINT
    MI_S32 MI_ISP_Free_IQDataBuf(void *pUserBuf);                       // NOLINT

    MI_S32 MI_ISP_CallBackTask_Register(MI_ISP_DEV DevId, MI_ISP_CallBackParam_t *pstCallBackParam);   // NOLINT
    MI_S32 MI_ISP_CallBackTask_Unregister(MI_ISP_DEV DevId, MI_ISP_CallBackParam_t *pstCallBackParam); // NOLINT

    MI_S32 MI_ISP_SkipFrame(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_U32 u32FrameNum);

    MI_S32 MI_ISP_LoadPortZoomTable(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_ZoomTable_t *pZoomTable);
    MI_S32 MI_ISP_StartPortZoom(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_ZoomAttr_t *pstZoomAttr);
    MI_S32 MI_ISP_StopPortZoom(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId);
    MI_S32 MI_ISP_GetPortCurZoomAttr(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_ZoomAttr_t *pstZoomAttr);

    MI_S32 MI_ISP_SetCustSegAttr(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_CustSegAttr_t *pstCustSegAttr);

    MI_S32 MI_ISP_GetCustSegAttr(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_CustSegAttr_t *pstCustSegAttr);

    MI_S32 MI_ISP_GetCustSegBuf(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_SYS_BUF_HANDLE *pBufHandle,
                                MI_SYS_BufInfo_t *pstInputBufInfo, MI_SYS_BufInfo_t *pstOutputBufInfo,
                                MI_S32 s32MilliSec);

    MI_S32 MI_ISP_PutCustSegBuf(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_SYS_BUF_HANDLE bufHandle);

    MI_S32 MI_ISP_SetChnOverlapAttr(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_Overlap_e eOverlap);
    MI_S32 MI_ISP_GetChnOverlapAttr(MI_ISP_DEV DevId, MI_ISP_CHANNEL ChnId, MI_ISP_Overlap_e *peOverlap);
#ifdef __cplusplus
}
#endif

#endif
