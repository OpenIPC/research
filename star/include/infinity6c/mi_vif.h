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
#ifndef _MI_VIF_H_
#define _MI_VIF_H_

#include "mi_vif_datatype.h"

#define VIF_MAJOR_VERSION   3
#define VIF_SUB_VERSION     3
#define MACRO_TO_STR(macro) #macro
#define VIF_VERSION_STR(major_version, sub_version)                                                                 \
    (                                                                                                               \
        {                                                                                                           \
            char *tmp =                                                                                             \
                sub_version / 100  ? "mi_vif_version_" MACRO_TO_STR(major_version) "." MACRO_TO_STR(sub_version)    \
                : sub_version / 10 ? "mi_vif_version_" MACRO_TO_STR(major_version) ".0" MACRO_TO_STR(sub_version)   \
                                   : "mi_vif_version_" MACRO_TO_STR(major_version) ".00" MACRO_TO_STR(sub_version); \
            tmp;                                                                                                    \
        })
#define MI_VIF_API_VERSION VIF_VERSION_STR(VIF_MAJOR_VERSION, VIF_SUB_VERSION)

#ifdef __cplusplus
extern "C"
{
#endif

    MI_S32 MI_VIF_CreateDevGroup(MI_VIF_GROUP GroupId, MI_VIF_GroupAttr_t *pstGroupAttr);
    MI_S32 MI_VIF_DestroyDevGroup(MI_VIF_GROUP GroupId);
    MI_S32 MI_VIF_GetDevGroupAttr(MI_VIF_GROUP GroupId, MI_VIF_GroupAttr_t *pstGroupAttr);

    MI_S32 MI_VIF_SetDevAttr(MI_VIF_DEV DevId, MI_VIF_DevAttr_t *pstDevAttr);
    MI_S32 MI_VIF_GetDevAttr(MI_VIF_DEV DevId, MI_VIF_DevAttr_t *pstDevAttr);
    MI_S32 MI_VIF_EnableDev(MI_VIF_DEV DevId);
    MI_S32 MI_VIF_DisableDev(MI_VIF_DEV DevId);
    MI_S32 MI_VIF_GetDevStatus(MI_VIF_DEV DevId, MI_VIF_DevStatus_t *pstVifDevStatus);

    MI_S32 MI_VIF_SetOutputPortAttr(MI_VIF_DEV DevId, MI_VIF_PORT PortId, MI_VIF_OutputPortAttr_t *pstAttr);
    MI_S32 MI_VIF_GetOutputPortAttr(MI_VIF_DEV DevId, MI_VIF_PORT PortId, MI_VIF_OutputPortAttr_t *pstAttr);
    MI_S32 MI_VIF_EnableOutputPort(MI_VIF_DEV DevId, MI_VIF_PORT PortId);
    MI_S32 MI_VIF_DisableOutputPort(MI_VIF_DEV DevId, MI_VIF_PORT PortId);

    MI_S32 MI_VIF_Query(MI_VIF_DEV DevId, MI_VIF_PORT PortId, MI_VIF_DevPortStat_t *pstStat);
    MI_S32 MI_VIF_CallBackTask_Register(MI_VIF_DEV DevId, MI_VIF_CallBackParam_t *pstCallBackParam);
    MI_S32 MI_VIF_CallBackTask_UnRegister(MI_VIF_DEV DevId, MI_VIF_CallBackParam_t *pstCallBackParam);

#ifdef __cplusplus
}
#endif

#endif ///_MI_VIF_H_
