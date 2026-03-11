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

#ifndef _MI_ISP_AE_H_
#define _MI_ISP_AE_H_

#include "mi_isp_ae_datatype.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /************************************* AE  API START *************************************/
    MI_S32 MI_ISP_AE_GetHistoWghtY(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_HistWeightYType_t *data);
    MI_S32 MI_ISP_AE_QueryExposureInfo(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ExpoInfoType_t *data);
    MI_S32 MI_ISP_AE_SetEvComp(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_EvCompType_t *data);
    MI_S32 MI_ISP_AE_GetEvComp(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_EvCompType_t *data);
    MI_S32 MI_ISP_AE_SetExpoMode(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ModeType_e *data);
    MI_S32 MI_ISP_AE_GetExpoMode(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ModeType_e *data);
    MI_S32 MI_ISP_AE_SetManualExpo(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ExpoValueType_t *data);
    MI_S32 MI_ISP_AE_GetManualExpo(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ExpoValueType_t *data);
    MI_S32 MI_ISP_AE_SetManualShortExpo(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ExpoValueType_t *data);
    MI_S32 MI_ISP_AE_GetManualShortExpo(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ExpoValueType_t *data);
    MI_S32 MI_ISP_AE_SetState(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_SmStateType_e *data); // Pause, Resume
    MI_S32 MI_ISP_AE_GetState(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_SmStateType_e *data);
    MI_S32 MI_ISP_AE_SetTarget(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_IntpLutType_t *data);
    MI_S32 MI_ISP_AE_GetTarget(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_IntpLutType_t *data);
    MI_S32 MI_ISP_AE_SetConverge(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ConvConditonType_t *data);
    MI_S32 MI_ISP_AE_GetConverge(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ConvConditonType_t *data);
    MI_S32 MI_ISP_AE_SetExposureLimit(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ExpoLimitType_t *data);
    MI_S32 MI_ISP_AE_GetExposureLimit(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ExpoLimitType_t *data);
    MI_S32 MI_ISP_AE_SetPlainLongExpoTable(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ExpoTableType_t *data);
    MI_S32 MI_ISP_AE_GetPlainLongExpoTable(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ExpoTableType_t *data);
    MI_S32 MI_ISP_AE_SetPlainShortExpoTable(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ExpoTableType_t *data);
    MI_S32 MI_ISP_AE_GetPlainShortExpoTable(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_ExpoTableType_t *data);
    MI_S32 MI_ISP_AE_SetWinWgtType(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_WinWeightModeType_e *data);
    MI_S32 MI_ISP_AE_GetWinWgtType(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_WinWeightModeType_e *data);
    MI_S32 MI_ISP_AE_SetWinWgt(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_WinWeightType_t *data);
    MI_S32 MI_ISP_AE_GetWinWgt(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_WinWeightType_t *data);
    MI_S32 MI_ISP_AE_SetFlicker(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_FlickerType_e *data);
    MI_S32 MI_ISP_AE_GetFlicker(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_FlickerType_e *data);
    MI_S32 MI_ISP_AE_SetFlickerEx(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_FlickerExType_t *data);
    MI_S32 MI_ISP_AE_GetFlickerEx(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_FlickerExType_t *data);
    MI_S32 MI_ISP_AE_QueryFlickerInfo(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_FlickerExInfoType_t *data);
    MI_S32 MI_ISP_AE_SetStrategy(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_StrategyType_t *data);
    MI_S32 MI_ISP_AE_GetStrategy(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_StrategyType_t *data);
    MI_S32 MI_ISP_AE_SetStrategyEx(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_StrategyExType_t *data);
    MI_S32 MI_ISP_AE_GetStrategyEx(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_StrategyExType_t *data);
    MI_S32 MI_ISP_AE_SetStrategyExAdv(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_StrategyExAdvType_t *data);
    MI_S32 MI_ISP_AE_GetStrategyExAdv(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_StrategyExAdvType_t *data);
    MI_S32 MI_ISP_AE_QueryStrategyExInfo(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_StrategyExInfoType_t *data);
    MI_S32 MI_ISP_AE_SetRgbirAe(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_RgbirAeType_t *data);
    MI_S32 MI_ISP_AE_GetRgbirAe(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_RgbirAeType_t *data);
    MI_S32 MI_ISP_AE_SetHdr(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_HdrType_t *data);
    MI_S32 MI_ISP_AE_GetHdr(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_HdrType_t *data);
    MI_S32 MI_ISP_AE_SetStabilizer(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_StabilizerType_t *data);
    MI_S32 MI_ISP_AE_GetStabilizer(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_StabilizerType_t *data);
    MI_S32 MI_ISP_AE_SetDayNightDetection(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_DaynightDetectionType_t *data);
    MI_S32 MI_ISP_AE_GetDayNightDetection(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_DaynightDetectionType_t *data);
    MI_S32 MI_ISP_AE_QueryDayNightInfo(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_DaynightInfoType_t *data);
    MI_S32 MI_ISP_AE_SetPowerLine(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_PowerLineType_t *data);
    MI_S32 MI_ISP_AE_GetPowerLine(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_PowerLineType_t *data);
    MI_S32 MI_ISP_AE_QueryPowerLineInfo(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_PowerLineInfoType_t *data);
    MI_S32 MI_ISP_AE_SetLumaWgt(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_LumaWgtType_t *data);
    MI_S32 MI_ISP_AE_GetLumaWgt(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_LumaWgtType_t *data);
    MI_S32 MI_ISP_AE_GetVersionInfo(MI_U32 DevId, MI_U32 Channel, MI_ISP_AE_VerInfoType_t *data);
    /************************************* AE  API END   *************************************/

    /************************************* LOAD API START*************************************/
    MI_S32 MI_ISP_AE_SetEvCompCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetExpoModeCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetManualExpoCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetManualShortExpoCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetStateCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetTargetCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetConvergeCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetExposureLimitCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetPlainLongExpoTableCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetPlainShortExpoTableCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetWinWgtCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetFlickerCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetFlickerExCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetRgbirAeCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetAeHdrCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetStrategyCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetStrategyExCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetStrategyExAdvCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetStabilizerCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetLumaWgtCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    MI_S32 MI_ISP_AE_SetPowerLineCall(MI_U32 DevId, MI_U32 Channel, MI_U8 *param_ary[], MI_U8 param_num);
    /************************************* LOAD API END  *************************************/

#ifdef __cplusplus
} // end of extern C
#endif

#endif //_MI_ISP_AE_H_
