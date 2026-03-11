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

/*
 * iq_apiset.h
 *
 *  Created on: 2016/8/16
 *      Author: Elsa-cf.Lin
 */

#ifndef _MI_ISP_IQ_DATATYPE_H_
#define _MI_ISP_IQ_DATATYPE_H_

#ifdef __USE_USERSPACE_3A__
#include "mi_common.h"
#endif

// put here temporarily, should add mi_isp_cali_datatype.h?

typedef enum __attribute__((aligned(1)))
{
    E_SS_CALI_ITEM_AWB  = 0,
    E_SS_CALI_ITEM_OBC  = 1,
    E_SS_CALI_ITEM_SDC  = 2,
    E_SS_CALI_ITEM_ALSC = 3,
    E_SS_CALI_ITEM_LSC  = 4,
    E_SS_CALI_ITEM_AWB_EX = 5,
    E_SS_CALI_ITEM_MAX,
} MI_ISP_IQ_CaliItem_e;

/************************************* API20 Define the structure declaration START ***********************************/
#if 1 // API20 struct

#define MI_ISP_AUTO_NUM           (16)
#define ALSC_TBL_MAX              459
#define ENABLE_CCM_COEFF_SUM_INFO 1

#define RGBGAMMA_NUM                 256
#define YUVGAMMA_Y_NUM               256
#define YUVGAMMA_U_NUM               128
#define YUVGAMMA_V_NUM               128
#define ADAPTIVE_GAMMA_NUM           256
#define SAT_LUT_X_NUM                5
#define SAT_LUT_Y_NUM                6
#define CCM_COEFF_SUM_INFO_NUM       12
#define CCM_NUM                      9
#define NR3D_BY_Y_NUM                12
#define NR3D_BY_MOT_NUM              16
#define NR3D_ES_YGAIN_X_NUM          11
#define NR3D_ES_YGAIN_Y_NUM          12
#define NR3D_ES_STDREMAP_X_NUM       2
#define NR3D_ES_STDREMAP_Y_NUM       2
#define NR3D_ES_STDGAIN_X_NUM        2
#define NR3D_ES_STDGAIN_Y_NUM        2
#define NR3D_EX_AR_MOT_NUM           2
#define NR3D_EX_AR_LUMA_NUM          2
#define NR3D_EX_PR_RATIO_CONF_NUM    4
#define NR3D_EX_PR_CONTRAST_TH_NUM   2
#define NR3D_EX_PR_MOT_TH_NUM        2
#define NRDESPIKE_BLEND_LUT_NUM      5
#define NRDESPIKE_BY_Y_NUM           15
#define NRLUMA_ADV_PIX_NUM           4
#define NRLUMA_ADV_BY_LUMA_NUM       8
#define NRLUMA_ADV_LUMASFT_NUM       7
#define NRLUMA_ADV_KERWEI_NUM        16
#define NRLUMA_ADV_RADIUSSFT_NUM     5
#define NRLUMA_ADV_RADIUS_NUM        6
#define NRLUMA_ADV_BY_Y_NUM          16
#define NRLUMA_ADV_SMO_DELTA_LUT_NUM 16
#define NRLUMA_ADV_BY_MOT_NUM        16
#define NRLUMA_ADV_LEVEL_NUM         2
#define NRLUMA_ADV_BY_HUE_NUM        24
#define NRLUMA_ADV_BY_SAT_NUM        2
#define NRCHROMA_BY_CEDGE_NUM        6
#define NRCHROMA_ADV_BY_Y_NUM        8
#define NRCHROMA_ADV_BY_YEDGE_NUM    8
#define NRCHROMA_ADV_BY_CEDGE_NUM    8
#define NRCHROMA_ADV_BY_MOT_NUM      16
#define NRCHROMA_PRE_YC_NUM          2
#define SHARPNESS_FREQ_NUM           3
#define SHARPNESS_FREQ_WEI_NUM       4
#define SHARPNESS_DA_STATE_NUM       2
#define SHARPNESS_DER_Y_NUM          2
#define SHARPNESS_LUT_X_NUM          6
#define SHARPNESS_LUT_Y_NUM          7
#define SHARPNESS_BY_STATE_NUM       9
#define SHARPNESS_BY_Y_NUM           9
#define SHARPNESS_BY_MOT_NUM         16
#define SHARPNESS_BY_HUE_NUM         24
#define SHARPNESS_BY_SAT_NUM         2
#define SHARPNESSEX_FREQ_NUM         2
#define SHARPNESSEX_FREQ_WEI_NUM     4
#define SHARPNESSEX_DER_Y_NUM        2
#define SHARPNESSEX_LUT_X_NUM        6
#define SHARPNESSEX_LUT_Y_NUM        7
#define SHARPNESSEX_BY_STATE_NUM     9
#define SHARPNESSEX_BY_Y_NUM         9
#define SHARPNESSEX_BY_MOT_NUM       16
#define SHARPNESSEX_BY_HUE_NUM       24
#define SHARPNESSEX_BY_SAT_NUM       2
#define CROSSTALK_BY_Y_NUM           15
#define WDR_BY_Y_NUM                 33
#define WDR_BY_MOT_NUM               16
#define WDR_LTM_BY_Y_NUM             3
#define WDR_NR_LUT_X_NUM             12
#define WDR_NR_LUT_Y_NUM             13
#define WDR_VND_LUT_X_NUM            8
#define WDR_VND_LUT_Y_NUM            9
#define WDR_CURVE_FULL_LUT_X_NUM     31
#define WDR_CURVE_FULL_LUT_Y_NUM     32
#define WDR_CURVE_FULL_CURVE_NUM     33
#define WDR_PLANE_NUM                2
#define DYNAMIC_DP_LUT_NUM           6
#define DYNAMIC_DP_CLUSTER_CH_NUM    4
#define DYNAMIC_DP_CLUSTER_TBL_NUM   6
#define HSV_HUE_NUM                  36
#define HSV_SAT_NUM                  9
#define HSV_Y_NUM                    9
#define RGBIR_BY_Y_NUM               6
#define PFC_BY_Y_NUM                 8
#define PFC_LUT_NUM                  2
#define PFC_BY_CONTRAST_NUM          8
#define PFC_EX_BY_HUE_NUM            13
#define COLORTRANS_MATRIX_NUM        9
#define HDR_LUT_X_NUM                6
#define HDR_LUT_Y_NUM                7
#define HDR_MOT_LUT_X_NUM            6
#define HDR_MOT_LUT_Y_NUM            7
#define HDR_BLEND_LUT_X_NUM          6
#define HDR_BLEND_LUT_Y_NUM          7
#define HDR_BLEND_V_NUM              2
#define HDR_BY_Y_NUM                 16
#define HDR_STR_BY_DIFF              32
#define HDR_EX_MOT_LUT_X_NUM         6
#define INTP_LUT_NUM                 16
#define LSC_TBL_SIZE                 32
#define LSC_CCT_NUM_MAX              3
#define ALSC_CCT_NUM_MAX             3
#define ALSC_DELTA_LUT_NUM           26
#define R2Y_MATRIX_NUM               9
#define DUMMY_NUM                    256
#define DUMMY_EX_NUM                 256
#define TEMP_NR3D_NUM                2
#define TEMP_SHARPNESS_NUM           2
#define TEMP_COLOR_TONE_NUM          3
#define TEMP_LUT_NUM                 16

typedef enum __attribute__((aligned(4)))
{
    E_SS_IQ_FALSE = 0,
    E_SS_IQ_TRUE  = !E_SS_IQ_FALSE,
    E_SS_IQ_BOOL_MAX
} MI_ISP_IQ_Bool_e;

typedef enum __attribute__((aligned(4)))
{
    E_SS_IQ_OP_TYP_AUTO   = 0,
    E_SS_IQ_OP_TYP_MANUAL = !E_SS_IQ_OP_TYP_AUTO,
    E_SS_IQ_OP_TYP_MODE_MAX
} MI_ISP_IQ_OpType_e;

typedef enum __attribute__((aligned(4)))
{
    E_API20_AUTO = 0, //[00]
    // API2.0
    E_API20_FPN,            //[01]
    E_API20_CCM,            //[02]
    E_API20_SAT,            //[03]
    E_API20_OBC,            //[04]
    E_API20_OBC_P1,         //[05]
    E_API20_FCOLOR,         //[06]
    E_API20_CR,             //[07]
    E_API20_NR_DESPIKE,     //[08]
    E_API20_SHP,            //[09]
    E_API20_NR_3D,          //[10]
    E_API20_BRI,            //[11]
    E_API20_LIG,            //[12]
    E_API20_CST,            //[13]
    E_API20_GMA,            //[14]
    E_API20_CTG,            //[15]
    E_API20_NR_NLM,         //[16]
    E_API20_DEFOG,          //[17]
    E_API20_DRC,            //[18]
    E_API20_DPC,            //[19]
    E_API20_HSV,            //[20]
    E_API20_WDR_LOC,        //[21]
    E_API20_RGBIR,          //[22]
    E_API20_YUVGMA,         //[23]
    E_API20_HDR16TO12,      //[24]
    E_API20_COLORTRANS,     //[25]
    E_API20_HDR,            //[26]
    E_API20_EFFECT,         //[27]
    E_API20_PFC,            //[28]
    E_API20_SIIR,           //[29]
    E_API20_DM,             //[30]
    E_API20_NR_3D_P1,       //[31]
    E_API20_WDR_CURVE_ADV,  //[32]
    E_API20_MXNR,           //[33]
    E_API20_R2Y,            //[34]
    E_API20_LSC,            //[35]
    E_API20_LSC_CTRL,       //[36]
    E_API20_ALSC,           //[37]
    E_API20_ALSC_CTRL,      //[38]
    E_API20_DPC_CLUSTER,    //[39]
    E_API20_PFC_EX,         //[40]
    E_API20_HDR_EX,         //[41]
    E_API20_SHP_EX,         //[42]
    E_API20_NR_3D_EX,       //[43]
    E_API20_GNR,            //[44]
    E_API20_DUMMY,          //[45]
    E_API20_DUMMY_EX,       //[46]
    E_API20_WDR_CURVE_FULL, //[47]
    E_API20_ADAPTIVE_GMA,   //[48]
    E_API20_XNR,            //[49]
    E_API20_TEMP,           //[50]
    E_API20_TEMP_INFO,      //[51]
    E_API20_CSA,            //[52]
    E_API20_WDR_LCE,        //[53]
    E_API20_WDR_NR,         //[54]
    E_API20_YCLPF,          //[55]
    E_API20_DARKSHADING,    //[56]
    E_API20_WDR_LTM,        //[57]
    E_API20_COLORTRANS_EX,  //[58]
    E_API20_MAX,            // for para reset
} MI_ISP_IQ_ApiId_e;

typedef struct MI_ISP_IQ_ColorToGrayType_s
{
    MI_ISP_IQ_Bool_e bEnable; // 0 ~ 1
} MI_ISP_IQ_ColorToGrayType_t;

typedef struct MI_ISP_IQ_LevelBaseParam_s
{
    MI_U32 u32Lev; // 0 ~ 100
} MI_ISP_IQ_LevelBaseParam_t;

typedef struct MI_ISP_IQ_LightnessManualAttr_s
{
    MI_ISP_IQ_LevelBaseParam_t stParaAPI;
} MI_ISP_IQ_LightnessManualAttr_t;

typedef struct MI_ISP_IQ_LightnessAutoAttr_s
{
    MI_ISP_IQ_LevelBaseParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_LightnessAutoAttr_t;

typedef struct MI_ISP_IQ_LightnessType_s
{
    MI_ISP_IQ_Bool_e                bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e              enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_LightnessAutoAttr_t   stAuto;
    MI_ISP_IQ_LightnessManualAttr_t stManual;
} MI_ISP_IQ_LightnessType_t;

typedef struct MI_ISP_IQ_ContrastManualAttr_s
{
    MI_ISP_IQ_LevelBaseParam_t stParaAPI;
} MI_ISP_IQ_ContrastManualAttr_t;

typedef struct MI_ISP_IQ_ContrastAutoAttr_s
{
    MI_ISP_IQ_LevelBaseParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_ContrastAutoAttr_t;

typedef struct MI_ISP_IQ_ContrastType_s
{
    MI_ISP_IQ_Bool_e               bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e             enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_ContrastAutoAttr_t   stAuto;
    MI_ISP_IQ_ContrastManualAttr_t stManual;
} MI_ISP_IQ_ContrastType_t;

typedef struct MI_ISP_IQ_BrightnessManualAttr_s
{
    MI_ISP_IQ_LevelBaseParam_t stParaAPI;
} MI_ISP_IQ_BrightnessManualAttr_t;

typedef struct MI_ISP_IQ_BrightnessAutoAttr_s
{
    MI_ISP_IQ_LevelBaseParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_BrightnessAutoAttr_t;

typedef struct MI_ISP_IQ_BrightnessType_s
{
    MI_ISP_IQ_Bool_e                 bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e               enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_BrightnessAutoAttr_t   stAuto;
    MI_ISP_IQ_BrightnessManualAttr_t stManual;
} MI_ISP_IQ_BrightnessType_t;

typedef struct MI_ISP_IQ_RgbGammaParam_s
{
    MI_U16 u16LutR[RGBGAMMA_NUM]; // 0 ~ 4095
    MI_U16 u16LutG[RGBGAMMA_NUM]; // 0 ~ 4095
    MI_U16 u16LutB[RGBGAMMA_NUM]; // 0 ~ 4095
} MI_ISP_IQ_RgbGammaParam_t;

typedef struct MI_ISP_IQ_RgbGammaManualAttr_s
{
    MI_ISP_IQ_RgbGammaParam_t stParaAPI;
} MI_ISP_IQ_RgbGammaManualAttr_t;

typedef struct MI_ISP_IQ_RgbGammaAutoAttr_s
{
    MI_ISP_IQ_RgbGammaParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_RgbGammaAutoAttr_t;

typedef struct MI_ISP_IQ_RgbGammaType_s
{
    MI_ISP_IQ_Bool_e               bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e             enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_RgbGammaAutoAttr_t   stAuto;
    MI_ISP_IQ_RgbGammaManualAttr_t stManual;
} MI_ISP_IQ_RgbGammaType_t;

typedef struct MI_ISP_IQ_YuvGammaParam_s
{
    MI_U16 u16LutY[YUVGAMMA_Y_NUM]; // 0 ~ 1023
    MI_U16 u16LutU[YUVGAMMA_U_NUM]; // 0 ~  511
    MI_U16 u16LutV[YUVGAMMA_V_NUM]; // 0 ~  511
} MI_ISP_IQ_YuvGammaParam_t;

typedef struct MI_ISP_IQ_YuvGammaManualAttr_s
{
    MI_ISP_IQ_YuvGammaParam_t stParaAPI;
} MI_ISP_IQ_YuvGammaManualAttr_t;

typedef struct MI_ISP_IQ_YuvGammaAutoAttr_s
{
    MI_ISP_IQ_YuvGammaParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_YuvGammaAutoAttr_t;

typedef struct MI_ISP_IQ_YuvGammaType_s
{
    MI_ISP_IQ_Bool_e               bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e             enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_YuvGammaAutoAttr_t   stAuto;
    MI_ISP_IQ_YuvGammaManualAttr_t stManual;
} MI_ISP_IQ_YuvGammaType_t;

typedef struct MI_ISP_IQ_AdaptiveGammaType_s
{
    MI_ISP_IQ_Bool_e bEnable;
    MI_U16           u16BTGamma[ADAPTIVE_GAMMA_NUM];
    MI_U16           u16DTGamma[ADAPTIVE_GAMMA_NUM];
} MI_ISP_IQ_AdaptiveGammaType_t;

typedef struct MI_ISP_IQ_SaturationParam_s
{
    MI_U8 u8SatAllStr;                   // 0 ~ 127 (32 = 1X)
    MI_U8 u8SatByYSFTAdv[SAT_LUT_X_NUM]; // 0 ~ 8
    MI_U8 u8SatByYLUTAdv[SAT_LUT_Y_NUM]; // 0 ~ 128
    MI_U8 u8SatBySSFTAdv[SAT_LUT_X_NUM]; // 0 ~ 8
    MI_U8 u8SatBySLUTAdv[SAT_LUT_Y_NUM]; // 0 ~ 128
    MI_U8 u8SatCoring;
} MI_ISP_IQ_SaturationParam_t;

typedef struct MI_ISP_IQ_SaturationManualAttr_s
{
    MI_ISP_IQ_SaturationParam_t stParaAPI;
} MI_ISP_IQ_SaturationManualAttr_t;

typedef struct MI_ISP_IQ_SaturationAutoAttr_s
{
    MI_ISP_IQ_SaturationParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_SaturationAutoAttr_t;

typedef struct MI_ISP_IQ_SaturationType_s
{
    MI_ISP_IQ_Bool_e                 bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e               enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_SaturationAutoAttr_t   stAuto;
    MI_ISP_IQ_SaturationManualAttr_t stManual;
} MI_ISP_IQ_SaturationType_t;

typedef struct MI_ISP_IQ_DefogParam_s
{
    MI_U8 u8Strength;
} MI_ISP_IQ_DefogParam_t;

typedef struct MI_ISP_IQ_DefogManualAttr_s
{
    MI_ISP_IQ_DefogParam_t stParaAPI;
} MI_ISP_IQ_DefogManualAttr_t;

typedef struct MI_ISP_IQ_DefogAutoAttr_s
{
    MI_ISP_IQ_DefogParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_DefogAutoAttr_t;

typedef struct MI_ISP_IQ_DefogType_s
{
    MI_ISP_IQ_Bool_e            bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e          enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_DefogAutoAttr_t   stAuto;
    MI_ISP_IQ_DefogManualAttr_t stManual;
} MI_ISP_IQ_DefogType_t;

typedef struct MI_ISP_IQ_RgbMatrixParam_s
{
    MI_U16 u16CCTthr;
#if ENABLE_CCM_COEFF_SUM_INFO
    MI_U16 u16CCM[CCM_COEFF_SUM_INFO_NUM]; // 0 ~ 8191(1024 = 1X)
#else
    MI_U16 u16CCM[CCM_NUM]; // 0 ~ 8191(1024 = 1X)
#endif
    MI_U8 u8CCMSat; // 0 ~ 100 0:Unit matrix, 100:User matrix
} MI_ISP_IQ_RgbMatrixParam_t;

typedef struct MI_ISP_IQ_RgbMatrixManualAttr_s
{
#if ENABLE_CCM_COEFF_SUM_INFO
    MI_U16 u16CCM[CCM_COEFF_SUM_INFO_NUM]; // 0 ~ 8191(1024 = 1X)
#else
    MI_U16 u16CCM[CCM_NUM]; // 0 ~ 8191(1024 = 1X)
#endif
    MI_U8 u8CCMSat; // 0 ~ 100 0:Unit matrix, 100:User matrix
} MI_ISP_IQ_RgbMatrixManualAttr_t;

typedef struct MI_ISP_IQ_RgbMatrixAutoAttr_s
{
    MI_ISP_IQ_Bool_e           bISOActEn; // 0 ~ 1
    MI_ISP_IQ_RgbMatrixParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_RgbMatrixAutoAttr_t;

typedef struct MI_ISP_IQ_RgbMatrixType_s
{
    MI_ISP_IQ_Bool_e                bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e              enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_RgbMatrixAutoAttr_t   stAuto;
    MI_ISP_IQ_RgbMatrixManualAttr_t stManual;
} MI_ISP_IQ_RgbMatrixType_t;

typedef struct MI_ISP_IQ_CcmInfoType_s
{
    MI_U16 u16CCM[CCM_COEFF_SUM_INFO_NUM]; // 0 ~ 8191(1024 = 1X)
    MI_U16 u16CCT;
} MI_ISP_IQ_CcmInfoType_t;

typedef struct MI_ISP_IQ_FalseColorParam_s
{
    MI_ISP_IQ_Bool_e bDbgEn;          // 0~1
    MI_U8            u8ColorSpaceSel; // 0~1
    MI_U8            u8Preserve;      // 0~7
    MI_U8            u8Strength;      // 0~31
} MI_ISP_IQ_FalseColorParam_t;

typedef struct MI_ISP_IQ_FalseColorManualAttr_s
{
    MI_ISP_IQ_FalseColorParam_t stParaAPI;
} MI_ISP_IQ_FalseColorManualAttr_t;

typedef struct MI_ISP_IQ_FalseColorAutoAttr_s
{
    MI_ISP_IQ_FalseColorParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_FalseColorAutoAttr_t;

typedef struct MI_ISP_IQ_FalseColorType_s
{
    MI_ISP_IQ_Bool_e                 bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e               enOpType; // OP_TYP_AUTO ~ (OP_TPY_MODMAX-1)
    MI_ISP_IQ_FalseColorAutoAttr_t   stAuto;
    MI_ISP_IQ_FalseColorManualAttr_t stManual;
} MI_ISP_IQ_FalseColorType_t;

typedef struct MI_ISP_IQ_Nr3dParam_s
{
    MI_U8  u8TfStrY;                              // 0~127
    MI_U8  u8TfStrC;                              // 0~127
    MI_U8  u8MdThd;                               // 0~255
    MI_U16 u16MdGain;                             // 0~1023
    MI_U16 u16MotEdgeRefineStr;                   // 0~1023
    MI_U8  u8MdThdByY[NR3D_BY_Y_NUM];             // 0~255
    MI_U8  u8MdGainByY[NR3D_BY_Y_NUM];            // 0~255
    MI_U8  u8M2SLut[NR3D_BY_MOT_NUM];             // 0~31
    MI_U8  u8M2SHistDelayByDiff[NR3D_BY_MOT_NUM]; // 0~7
    MI_U16 u16TfLut[NR3D_BY_MOT_NUM];             // 0~4095
    MI_U8  u8MotShpBlendLut[NR3D_BY_MOT_NUM];     // 0~64
} MI_ISP_IQ_Nr3dParam_t;

typedef struct MI_ISP_IQ_Nr3dManualAttr_s
{
    MI_ISP_IQ_Nr3dParam_t stParaAPI;
} MI_ISP_IQ_Nr3dManualAttr_t;

typedef struct MI_ISP_IQ_Nr3dAutoAttr_s
{
    MI_ISP_IQ_Nr3dParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_Nr3dAutoAttr_t;

typedef struct MI_ISP_IQ_Nr3dType_s
{
    MI_ISP_IQ_Bool_e           bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e         enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_Nr3dAutoAttr_t   stAuto;
    MI_ISP_IQ_Nr3dManualAttr_t stManual;
} MI_ISP_IQ_Nr3dType_t;

typedef struct MI_ISP_IQ_Nr3dExParam_s
{
    MI_ISP_IQ_Bool_e bDbgEn;                          // 0~1
    MI_ISP_IQ_Bool_e bAREn;                           // 0~1
    MI_U8            u8ARLumaTh[NR3D_EX_AR_LUMA_NUM]; // 0~255
    MI_U8            u8ARMotTh[NR3D_EX_AR_MOT_NUM];   // 0~255
} MI_ISP_IQ_Nr3dExParam_t;

typedef struct MI_ISP_IQ_Nr3dExManualAttr_s
{
    MI_ISP_IQ_Nr3dExParam_t stParaAPI;
} MI_ISP_IQ_Nr3dExManualAttr_t;

typedef struct MI_ISP_IQ_Nr3dExType_s
{
    MI_ISP_IQ_Bool_e             bEnable; // 0 ~ 1
    MI_ISP_IQ_Nr3dExManualAttr_t stManual;
} MI_ISP_IQ_Nr3dExType_t;

typedef struct MI_ISP_IQ_Nr3dP1Type_s
{
    MI_ISP_IQ_Bool_e bEnable; // 0 ~ 1
} MI_ISP_IQ_Nr3dP1Type_t;

typedef struct MI_ISP_IQ_NrDespikeParam_s
{
    MI_U8  u8BlendRatio;                         // 0 ~ 15
    MI_U8  u8StrengthCenterNeighbor;             // 0 ~ 5
    MI_U8  u8StrengthMeanStd;                    // 0 ~ 5
    MI_U8  u8StrengthCornerCross;                // 0 ~ 5
    MI_U8  u8DiffGainMeanStd;                    // 0 ~ 31
    MI_U8  u8DiffGainCenterNeighbor;             // 0 ~ 255
    MI_U8  u8DiffThdCornerCross;                 // 0 ~ 255
    MI_U16 u16BlendLut[NRDESPIKE_BLEND_LUT_NUM]; // 0 ~ 2047
    MI_U8  u8StrengthByY[NRDESPIKE_BY_Y_NUM];    // 0 ~ 64
} MI_ISP_IQ_NrDespikeParam_t;

typedef struct MI_ISP_IQ_NrDespikeManualAttr_s
{
    MI_ISP_IQ_NrDespikeParam_t stParaAPI;
} MI_ISP_IQ_NrDespikeManualAttr_t;

typedef struct MI_ISP_IQ_NrDespikeAutoAttr_s
{
    MI_ISP_IQ_NrDespikeParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_NrDespikeAutoAttr_t;

typedef struct MI_ISP_IQ_NrDespikeType_s
{
    MI_ISP_IQ_Bool_e                bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e              enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_NrDespikeAutoAttr_t   stAuto;
    MI_ISP_IQ_NrDespikeManualAttr_t stManual;
} MI_ISP_IQ_NrDespikeType_t;

typedef struct MI_ISP_IQ_NrLumaAdvParam_s
{
    //====defect detect====//
    MI_U8  u8HotPixCnt;                                    // 0 ~ 7
    MI_U8  u8DarkPixCnt;                                   // 0 ~ 7
    MI_U8  u8HotPix[NRLUMA_ADV_PIX_NUM];                   // 0 ~ 255
    MI_U8  u8DarkPix[NRLUMA_ADV_PIX_NUM];                  // 0 ~ 255
    //====edge detect=====//
    MI_U8  u8DbgMode;                                      // 0 ~ 2
    MI_U16 u16EdgeThByLuma[NRLUMA_ADV_BY_LUMA_NUM];        // 0 ~ 8192
    MI_U8  u8LumaSft[NRLUMA_ADV_LUMASFT_NUM];              // 0 ~ 8
    MI_U8  u8EdgeThByMot[NRLUMA_ADV_BY_MOT_NUM];           // 0 ~ 255
    MI_U8  u8EdgeThByMot1[NRLUMA_ADV_BY_MOT_NUM];          // 0 ~ 255
    //=====SF1, SF2======//
    MI_U8  u8SF1_str;                                      // 0 ~ 127
    MI_U8  u8SF2_str;                                      // 0 ~ 127
    //=======SF3=========//
    MI_U8  u8SF3_KerStr;                                   // 0 ~ 9
    MI_U8  u8SF3_KerWei[NRLUMA_ADV_KERWEI_NUM];            // 0 ~ 63
    MI_U8  u8SF3_StrByLuma[NRLUMA_ADV_BY_LUMA_NUM];        // 0 ~ 127
    MI_U8  u8SF3_StrByMot[NRLUMA_ADV_BY_MOT_NUM];          // 0 ~ 127
    MI_U8  u8SF3_StrByHue[NRLUMA_ADV_BY_HUE_NUM];          // 0 ~ 127
    MI_U8  u8SF3_StrByHue_SatTh[NRLUMA_ADV_LEVEL_NUM];     // 0 ~ 127
    MI_U8  u8SF3_StrByRadius_Sft[NRLUMA_ADV_RADIUSSFT_NUM];// 0 ~ 7
    MI_U8  u8SF3_StrByRadius[NRLUMA_ADV_RADIUS_NUM];       // 0 ~ 127
    //=======SF4=========//
    MI_U8  u8SF4_KerStr;                                   // 0 ~ 9
    MI_U8  u8SF4_KerWei[NRLUMA_ADV_KERWEI_NUM];            // 0 ~ 63
    MI_U8  u8SF4_StrByMot[NRLUMA_ADV_BY_MOT_NUM];          // 0 ~ 6
    //=blending(global strength)=//
    MI_U16 u16Strength[NRLUMA_ADV_LEVEL_NUM];              // 0 ~ 256
    MI_U8  u8StrengthByMot[NRLUMA_ADV_BY_MOT_NUM];         // 0 ~ 64
    MI_U8  u8StrengthByLuma[NRLUMA_ADV_BY_LUMA_NUM];       // 0 ~ 64
} MI_ISP_IQ_NrLumaAdvParam_t;


typedef struct MI_ISP_IQ_NrLumaAdvManualAttr_s
{
    MI_ISP_IQ_NrLumaAdvParam_t stParaAPI;
} MI_ISP_IQ_NrLumaAdvManualAttr_t;

typedef struct MI_ISP_IQ_NrLumaAdvAutoAttr_s
{
    MI_ISP_IQ_NrLumaAdvParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_NrLumaAdvAutoAttr_t;

typedef struct MI_ISP_IQ_NrLumaAdvType_s
{
    MI_ISP_IQ_Bool_e                bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e              enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_NrLumaAdvAutoAttr_t   stAuto;
    MI_ISP_IQ_NrLumaAdvManualAttr_t stManual;
} MI_ISP_IQ_NrLumaAdvType_t;

typedef struct MI_ISP_IQ_NrChromaParam_s
{
    MI_U8  u8MatchRatio;                              // 0 ~ 127
    MI_U16 u16UvTh;                                   // 0 ~ 1023
    MI_U16 u16StrengthByCEdge[NRCHROMA_BY_CEDGE_NUM]; // 0 ~ 1023
} MI_ISP_IQ_NrChromaParam_t;

typedef struct MI_ISP_IQ_NrChromaManualAttr_s
{
    MI_ISP_IQ_NrChromaParam_t stParaAPI;
} MI_ISP_IQ_NrChromaManualAttr_t;

typedef struct MI_ISP_IQ_NrChromaAutoAttr_s
{
    MI_ISP_IQ_NrChromaParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_NrChromaAutoAttr_t;

typedef struct MI_ISP_IQ_NrChromaType_s
{
    MI_ISP_IQ_Bool_e               bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e             enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_NrChromaAutoAttr_t   stAuto;
    MI_ISP_IQ_NrChromaManualAttr_t stManual;
} MI_ISP_IQ_NrChromaType_t;

typedef struct MI_ISP_IQ_NrChromaAdvParam_s
{
    MI_U8 u8StrengthByY[NRCHROMA_ADV_BY_Y_NUM];         // 0 ~ 255
    MI_U8 u8StrengthByYEdge[NRCHROMA_ADV_BY_YEDGE_NUM]; // 0 ~ 63
    MI_U8 u8StrengthByCEdge[NRCHROMA_ADV_BY_CEDGE_NUM]; // 0 ~ 255
    MI_U8 u8MaxStrength;                                // 0 ~ 255
    MI_U8 u8StrengthByMot[NRCHROMA_ADV_BY_MOT_NUM];     // 0 ~ 63
    MI_U8 u8MotionClip;                                 // 0 ~ 255
    MI_U8 u8MotionColorReduce;                          // 0 ~ 255
    MI_U8 u8MotionColorRecover;                         // 0 ~ 255
    MI_U8 u8PreStrength;                                // 0 ~ 128
} MI_ISP_IQ_NrChromaAdvParam_t;

typedef struct MI_ISP_IQ_NrChromaAdvManualAttr_s
{
    MI_ISP_IQ_NrChromaAdvParam_t stParaAPI;
} MI_ISP_IQ_NrChromaAdvManualAttr_t;

typedef struct MI_ISP_IQ_NrChromaAdvAutoAttr_s
{
    MI_ISP_IQ_NrChromaAdvParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_NrChromaAdvAutoAttr_t;

typedef struct MI_ISP_IQ_NrChromaAdvType_s
{
    MI_ISP_IQ_Bool_e                  bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e                enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_NrChromaAdvAutoAttr_t   stAuto;
    MI_ISP_IQ_NrChromaAdvManualAttr_t stManual;
} MI_ISP_IQ_NrChromaAdvType_t;

typedef struct MI_ISP_IQ_NrChromaPreParam_s
{
    MI_ISP_IQ_Bool_e bDbgEn;                                 // 0 ~ 1
    MI_U16           u16Strength;                            // 0 ~ 256
    MI_U8            u8MotionEnhance[NRCHROMA_PRE_YC_NUM];   // 0 ~ 127
    MI_U16           u16MaskGenTh;                           // 0 ~ 1023
    MI_U16           u16MeanFilterTh[NRCHROMA_PRE_YC_NUM];   // 0 ~ 1023
    MI_U16           u16MedianFilterTh[NRCHROMA_PRE_YC_NUM]; // 0 ~ 1023
    MI_U16           u16BlendTh;                             // 0 ~ 1023
    MI_U8            u8BlendGap;                             // 0 ~ 15
} MI_ISP_IQ_NrChromaPreParam_t;

typedef struct MI_ISP_IQ_NrChromaPreManualAttr_s
{
    MI_ISP_IQ_NrChromaPreParam_t stParaAPI;
} MI_ISP_IQ_NrChromaPreManualAttr_t;

typedef struct MI_ISP_IQ_NrChromaPreAutoAttr_s
{
    MI_ISP_IQ_NrChromaPreParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_NrChromaPreAutoAttr_t;

typedef struct MI_ISP_IQ_NrChromaPreType_s
{
    MI_ISP_IQ_Bool_e                  bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e                enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_NrChromaPreAutoAttr_t   stAuto;
    MI_ISP_IQ_NrChromaPreManualAttr_t stManual;
} MI_ISP_IQ_NrChromaPreType_t;

typedef struct MI_ISP_IQ_SharpnessParam_s
{
    MI_U8            u8SharpnessUD[SHARPNESS_FREQ_NUM];            // 0 ~ 127
    MI_U8            u8SharpnessD[SHARPNESS_FREQ_NUM];             // 0 ~ 127
    MI_U8            u8PreCorUD[SHARPNESS_FREQ_NUM];               // 0 ~ 63
    MI_U8            u8PreCorD[SHARPNESS_FREQ_NUM];                // 0 ~ 63
    MI_U8            u8FilterSel;                                  // 0 ~ 1
    MI_U8            u8StateByGain[SHARPNESS_DA_STATE_NUM];        // 0 ~ 31
    MI_U8            u8StateByOffset[SHARPNESS_DA_STATE_NUM];      // 0 ~ 255
    MI_U8            u8StdvByY[SHARPNESS_BY_Y_NUM];                // 0 ~ 255
    MI_U8            u8StdvByMot[SHARPNESS_BY_MOT_NUM];            // 0 ~ 63
    MI_U16           u16UDWeiByState[SHARPNESS_FREQ_WEI_NUM];      // 0 ~ 256
    MI_U16           u16DWeiByState[SHARPNESS_FREQ_WEI_NUM];       // 0 ~ 256
    MI_U16           u16UDWeiByMot[SHARPNESS_BY_MOT_NUM];          // 0 ~ 256
    MI_U16           u16DWeiByMot[SHARPNESS_BY_MOT_NUM];           // 0 ~ 256
    MI_U8            u8UDGainByStd[SHARPNESS_LUT_Y_NUM];           // 0 ~ 255
    MI_U8            u8DGainByStd[SHARPNESS_LUT_Y_NUM];            // 0 ~ 255
    MI_U16           u16UDEdgeKillLutUp[SHARPNESS_LUT_Y_NUM];      // 0 ~ 1023
    MI_U16           u16UDEdgeKillLutDown[SHARPNESS_LUT_Y_NUM];    // 0 ~ 1023
    MI_U16           u16DEdgeKillLutUp[SHARPNESS_LUT_Y_NUM];       // 0 ~ 1023
    MI_U16           u16DEdgeKillLutDown[SHARPNESS_LUT_Y_NUM];     // 0 ~ 1023
    MI_U16           u16DRatioByState[SHARPNESS_BY_STATE_NUM];     // 0 ~ 256
    MI_U16           u16EdgeGain;                                  // 0 ~ 1023
    MI_U8            u8GainByStd[SHARPNESS_LUT_Y_NUM];             // 0 ~ 255
    MI_U8            u8GainByStdSft[SHARPNESS_LUT_X_NUM];          // 0 ~ 15
    MI_U8            u8CorByY[SHARPNESS_BY_Y_NUM];                 // 0 ~ 255
    MI_U8            u8SclByY[SHARPNESS_BY_Y_NUM];                 // 0 ~ 255
    MI_U8            u8GainByMot[SHARPNESS_BY_MOT_NUM];            // 0 ~ 255
    MI_U8            u8DerRmNRCnt[SHARPNESS_DER_Y_NUM];            // 0 ~ 12 --> API : 0 ~ 6
    MI_U8            u8DerOverShootGain[SHARPNESS_LUT_Y_NUM];      // 0 ~ 255
    MI_U8            u8DerUnderShootGain[SHARPNESS_LUT_Y_NUM];     // 0 ~ 255
    MI_U8            u8DerGainByMot[SHARPNESS_BY_MOT_NUM];         // 0 ~ 255
    MI_U16           u16DerOverShootLimitByY[SHARPNESS_BY_Y_NUM];  // 0 ~ 1023
    MI_U16           u16DerUnderShootLimitByY[SHARPNESS_BY_Y_NUM]; // 0 ~ 1023
    MI_U8            u8StrengthByHue[SHARPNESS_BY_HUE_NUM];        // 0 ~ 255
    MI_U8            u8StrengthBySat[SHARPNESS_BY_SAT_NUM];        // 0 ~ 127
    MI_U8            u8BranchStrength;                             // 0 ~ 255
    MI_U8            u8BranchGainByStd[SHARPNESS_LUT_Y_NUM];       // 0 ~ 255
    MI_ISP_IQ_Bool_e bDbgEn;                                       // 0 ~ 1
} MI_ISP_IQ_SharpnessParam_t;

typedef struct MI_ISP_IQ_SharpnessManualAttr_s
{
    MI_ISP_IQ_SharpnessParam_t stParaAPI;
} MI_ISP_IQ_SharpnessManualAttr_t;

typedef struct MI_ISP_IQ_SharpnessAutoAttr_s
{
    MI_ISP_IQ_SharpnessParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_SharpnessAutoAttr_t;

typedef struct MI_ISP_IQ_SharpnessType_s
{
    MI_ISP_IQ_Bool_e                bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e              enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_SharpnessAutoAttr_t   stAuto;
    MI_ISP_IQ_SharpnessManualAttr_t stManual;
} MI_ISP_IQ_SharpnessType_t;

typedef struct MI_ISP_IQ_SharpnessExParam_s
{
    MI_U8            u8Sharpness[SHARPNESSEX_FREQ_NUM];              // 0 ~ 127
    MI_U8            u8PreCor[SHARPNESSEX_FREQ_NUM];                 // 0 ~ 63
    MI_U8            u8StateByGain;                                  // 0 ~ 31
    MI_U8            u8StateByOffset;                                // 0 ~ 255
    MI_U8            u8StdvByY[SHARPNESSEX_BY_Y_NUM];                // 0 ~ 255
    MI_U8            u8StdvByMot[SHARPNESSEX_BY_MOT_NUM];            // 0 ~ 63
    MI_U16           u16WeiByState[SHARPNESSEX_FREQ_WEI_NUM];        // 0 ~ 128
    MI_U16           u16WeiByMot[SHARPNESSEX_BY_MOT_NUM];            // 0 ~ 256
    MI_U16           u16EdgeGain;                                    // 0 ~ 1023
    MI_U8            u8GainByStd[SHARPNESSEX_LUT_Y_NUM];             // 0 ~ 255
    MI_U8            u8GainByStdSft[SHARPNESSEX_LUT_X_NUM];          // 0 ~ 15
    MI_U8            u8CorByY[SHARPNESSEX_BY_Y_NUM];                 // 0 ~ 255
    MI_U8            u8SclByY[SHARPNESSEX_BY_Y_NUM];                 // 0 ~ 255
    MI_U8            u8GainByMot[SHARPNESSEX_BY_MOT_NUM];            // 0 ~ 255
    MI_U8            u8DerOverShootGain[SHARPNESSEX_LUT_Y_NUM];      // 0 ~ 255
    MI_U8            u8DerUnderShootGain[SHARPNESSEX_LUT_Y_NUM];     // 0 ~ 255
    MI_U8            u8DerGainByMot[SHARPNESSEX_BY_MOT_NUM];         // 0 ~ 255
    MI_U16           u16DerOverShootLimitByY[SHARPNESSEX_BY_Y_NUM];  // 0 ~ 1023
    MI_U16           u16DerUnderShootLimitByY[SHARPNESSEX_BY_Y_NUM]; // 0 ~ 1023
    MI_U8            u8StrengthByHue[SHARPNESSEX_BY_HUE_NUM];        // 0 ~ 255
    MI_U8            u8StrengthBySat[SHARPNESSEX_BY_SAT_NUM];        // 0 ~ 127
    MI_ISP_IQ_Bool_e bDbgEn;                                         // 0 ~ 1
} MI_ISP_IQ_SharpnessExParam_t;

typedef struct MI_ISP_IQ_SharpnessExManualAttr_s
{
    MI_ISP_IQ_SharpnessExParam_t stParaAPI;
} MI_ISP_IQ_SharpnessExManualAttr_t;

typedef struct MI_ISP_IQ_SharpnessExAutoAttr_s
{
    MI_ISP_IQ_SharpnessExParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_SharpnessExAutoAttr_t;

typedef struct MI_ISP_IQ_SharpnessExType_s
{
    MI_ISP_IQ_Bool_e                  bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e                enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_SharpnessExAutoAttr_t   stAuto;
    MI_ISP_IQ_SharpnessExManualAttr_t stManual;
} MI_ISP_IQ_SharpnessExType_t;

typedef struct MI_ISP_IQ_DarkShadingParam_s
{
    MI_U16 u16Radius;
    MI_U8  u8SmoothBoundary;
} MI_ISP_IQ_DarkShadingParam_t;

typedef struct MI_ISP_IQ_DarkShadingManualAttr_s
{
    MI_ISP_IQ_DarkShadingParam_t stParaAPI;
} MI_ISP_IQ_DarkShadingManualAttr_t;

typedef struct MI_ISP_IQ_DarkShadingType_s
{
    MI_ISP_IQ_Bool_e                  bEnable; // 0 ~ 1
    MI_ISP_IQ_DarkShadingManualAttr_t stManual;
} MI_ISP_IQ_DarkShadingType_t;

typedef struct MI_ISP_IQ_CrosstalkParam_s
{
    MI_U8  u8Strength;                        // 0 ~ 31
    MI_U8  u8StrengthByY[CROSSTALK_BY_Y_NUM]; // 0 ~ 127
    MI_U8  u8Threshold;                       // 0 ~ 255
    MI_U16 u16Offset;                         // 0 ~ 4095
} MI_ISP_IQ_CrosstalkParam_t;

typedef struct MI_ISP_IQ_CrosstalkManualAttr_s
{
    MI_ISP_IQ_CrosstalkParam_t stParaAPI;
} MI_ISP_IQ_CrosstalkManualAttr_t;

typedef struct MI_ISP_IQ_CrosstalkAutoAttr_s
{
    MI_ISP_IQ_CrosstalkParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_CrosstalkAutoAttr_t;

typedef struct MI_ISP_IQ_CrosstalkType_s
{
    MI_ISP_IQ_Bool_e                bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e              enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_CrosstalkAutoAttr_t   stAuto;
    MI_ISP_IQ_CrosstalkManualAttr_t stManual;
} MI_ISP_IQ_CrosstalkType_t;

typedef struct MI_ISP_IQ_ObcParam_s
{
    MI_U16 u16ValR;  // 0 ~ 255
    MI_U16 u16ValGr; // 0 ~ 255
    MI_U16 u16ValGb; // 0 ~ 255
    MI_U16 u16ValB;  // 0 ~ 255
} MI_ISP_IQ_ObcParam_t;

typedef struct MI_ISP_IQ_ObcManualAttr_s
{
    MI_ISP_IQ_ObcParam_t stParaAPI;
} MI_ISP_IQ_ObcManualAttr_t;

typedef struct MI_ISP_IQ_ObcAutoAttr_s
{
    MI_ISP_IQ_ObcParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_ObcAutoAttr_t;

typedef struct MI_ISP_IQ_ObcType_s
{
    MI_ISP_IQ_Bool_e          bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e        enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_ObcAutoAttr_t   stAuto;
    MI_ISP_IQ_ObcManualAttr_t stManual;
} MI_ISP_IQ_ObcType_t;

typedef struct MI_ISP_IQ_WdrParam_s
{
    MI_U8            u8GlobalDarkToneEnhance;    // 0 ~ 15
    MI_U8            u8WDRStrByY[WDR_BY_Y_NUM];  // 0 ~ 255
    MI_U8            u8Strength;                 // 0 ~ 255
    MI_U8            u8DarkLimit;                // 0 ~ 255
    MI_U8            u8BrightLimit;              // 0 ~ 255
    MI_U8            u8DeSatSrcSel;              // 0 ~ 2
    MI_ISP_IQ_Bool_e bDeSatCrEn;                 // 0 ~ 1
    MI_U8            u8DeSatCbLut[WDR_BY_Y_NUM]; // 0 ~ 255
    MI_U8            u8DeSatCrLut[WDR_BY_Y_NUM]; // 0 ~ 255
} MI_ISP_IQ_WdrParam_t;

typedef struct MI_ISP_IQ_WdrManualAttr_s
{
    MI_ISP_IQ_WdrParam_t stParaAPI;
} MI_ISP_IQ_WdrManualAttr_t;

typedef struct MI_ISP_IQ_WdrAutoAttr_s
{
    MI_ISP_IQ_WdrParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_WdrAutoAttr_t;

typedef struct MI_ISP_IQ_WdrType_s
{
    MI_ISP_IQ_Bool_e          bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e        enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_WdrAutoAttr_t   stAuto;
    MI_ISP_IQ_WdrManualAttr_t stManual;
} MI_ISP_IQ_WdrType_t;

typedef struct MI_ISP_IQ_WdrLtmParam_s
{
    MI_U8 u8LocalStr;         // 0 ~ 255
    MI_U8 u8LevelStr;         // 0 ~ 255
    MI_U8 u8CoarseBoxNum;     // 0 ~ 3
    MI_U8 u8CoarseFltCoef;    // 0 ~ 4
    MI_U8 u8CoarseToneMapStr; // 0 ~ 255
    MI_U8 u8FineBoxNum;       // 0 ~ 4
    MI_U8 u8FineFltCoef;      // 0 ~ 4
    MI_U8 u8FineToneMapStr;   // 0 ~ 255
} MI_ISP_IQ_WdrLtmParam_t;

typedef struct MI_ISP_IQ_WdrLtmManualAttr_s
{
    MI_ISP_IQ_WdrLtmParam_t stParaAPI;
} MI_ISP_IQ_WdrLtmManualAttr_t;

typedef struct MI_ISP_IQ_WdrLtmAutoAttr_s
{
    MI_ISP_IQ_WdrLtmParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_WdrLtmAutoAttr_t;

typedef struct MI_ISP_IQ_WdrLtmType_s
{
    MI_ISP_IQ_Bool_e             bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e           enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_WdrLtmAutoAttr_t   stAuto;
    MI_ISP_IQ_WdrLtmManualAttr_t stManual;
} MI_ISP_IQ_WdrLtmType_t;

typedef struct MI_ISP_IQ_WdrNrParam_s
{
    MI_U8            u8Strength;                    // 0 ~ 255
    MI_U16           u16NrThdScl;                   // 0 ~ 65535
    MI_U16           u16NrGainScl;                  // 0 ~ 65535
    MI_U8            u8NrSft[WDR_NR_LUT_X_NUM];     // 1 ~ 15
    MI_U16           u16NrRThd[WDR_NR_LUT_Y_NUM];   // 0 ~ 4095
    MI_U16           u16NrRGain[WDR_NR_LUT_Y_NUM];  // 0 ~ 4095
    MI_U16           u16NrGThd[WDR_NR_LUT_Y_NUM];   // 0 ~ 4095
    MI_U16           u16NrGGain[WDR_NR_LUT_Y_NUM];  // 0 ~ 4095
    MI_U16           u16NrBThd[WDR_NR_LUT_Y_NUM];   // 0 ~ 4095
    MI_U16           u16NrBGain[WDR_NR_LUT_Y_NUM];  // 0 ~ 4095
    MI_U8            u8NrStrMot[WDR_BY_MOT_NUM];    // 0 ~ 255
    MI_U8            u8NrNosMot[WDR_BY_MOT_NUM];    // 0 ~ 255
    MI_U8            u8VNDSft[WDR_VND_LUT_X_NUM];   // 1 ~ 11
    MI_U16           u16VNDThd[WDR_VND_LUT_Y_NUM];  // 0 ~ 4095
    MI_U16           u16VNDGain[WDR_VND_LUT_Y_NUM]; // 0 ~ 4095
    MI_ISP_IQ_Bool_e bVNDByPass;                    // 0 ~ 1
} MI_ISP_IQ_WdrNrParam_t;

typedef struct MI_ISP_IQ_WdrNrManualAttr_s
{
    MI_ISP_IQ_WdrNrParam_t stParaAPI;
} MI_ISP_IQ_WdrNrManualAttr_t;

typedef struct MI_ISP_IQ_WdrNrAutoAttr_s
{
    MI_ISP_IQ_WdrNrParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_WdrNrAutoAttr_t;

typedef struct MI_ISP_IQ_WdrNrType_s
{
    MI_ISP_IQ_Bool_e            bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e          enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_WdrNrAutoAttr_t   stAuto;
    MI_ISP_IQ_WdrNrManualAttr_t stManual;
} MI_ISP_IQ_WdrNrType_t;

typedef enum __attribute__((aligned(4)))
{
    E_WDR_CURVE_FULL_GLOBAL_TONE,
    E_WDR_CURVE_FULL_CURVE1,
    E_WDR_CURVE_FULL_CURVE2,
    E_WDR_CURVE_FULL_MAX
} MI_ISP_IQ_WdrCurveFull_e;

typedef struct MI_ISP_IQ_WdrCurveFullParam_s
{
    MI_U8  u8GlobalToneSft[WDR_CURVE_FULL_LUT_X_NUM];  // 3~15
    MI_U16 u16GlobalToneLut[WDR_CURVE_FULL_LUT_Y_NUM]; // 0~4095
    MI_U16 u16Curve1[WDR_CURVE_FULL_CURVE_NUM];        // 0~4096
    MI_U16 u16Curve2[WDR_CURVE_FULL_CURVE_NUM];        // 0~4096
} MI_ISP_IQ_WdrCurveFullParam_t;

typedef struct MI_ISP_IQ_WdrCurveFullManualAttr_s
{
    MI_ISP_IQ_WdrCurveFullParam_t stParaAPI;
} MI_ISP_IQ_WdrCurveFullManualAttr_t;

typedef struct MI_ISP_IQ_WdrCurveFullAutoAttr_s
{
    MI_ISP_IQ_WdrCurveFullParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_WdrCurveFullAutoAttr_t;

typedef struct MI_ISP_IQ_WdrCurveFullType_s
{
    MI_ISP_IQ_Bool_e                   bEnable[E_WDR_CURVE_FULL_MAX];  // 0 ~ 1
    MI_ISP_IQ_OpType_e                 enOpType[E_WDR_CURVE_FULL_MAX]; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_WdrCurveFullAutoAttr_t   stAuto;
    MI_ISP_IQ_WdrCurveFullManualAttr_t stManual;
} MI_ISP_IQ_WdrCurveFullType_t;

typedef struct MI_ISP_IQ_WdrCurveAdvType_s
{
    MI_ISP_IQ_Bool_e bEnable; // 0 ~ 1
} MI_ISP_IQ_WdrCurveAdvType_t;

typedef struct MI_ISP_IQ_DynamicDpParam_s
{
    MI_ISP_IQ_Bool_e bHotPixEn; // 0 ~ 1
    MI_U16           u16HotPixCompSlpoe;
    MI_ISP_IQ_Bool_e bDarkPixEn; // 0 ~ 1
    MI_U16           u16DarkPixCompSlpoe;
    MI_U16           u16DPCTH;
    MI_ISP_IQ_Bool_e bBlendEn;
    MI_U16           u16DiffLut[DYNAMIC_DP_LUT_NUM];
    MI_U16           u16YLut[DYNAMIC_DP_LUT_NUM];
} MI_ISP_IQ_DynamicDpParam_t;

typedef struct MI_ISP_IQ_DynamicDpManualAttr_s
{
    MI_ISP_IQ_DynamicDpParam_t stParaAPI;
} MI_ISP_IQ_DynamicDpManualAttr_t;

typedef struct MI_ISP_IQ_DynamicDpAutoAttr_s
{
    MI_ISP_IQ_DynamicDpParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_DynamicDpAutoAttr_t;

typedef struct MI_ISP_IQ_DynamicDpType_s
{
    MI_ISP_IQ_Bool_e                bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e              enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_DynamicDpAutoAttr_t   stAuto;
    MI_ISP_IQ_DynamicDpManualAttr_t stManual;
} MI_ISP_IQ_DynamicDpType_t;

typedef struct MI_ISP_IQ_DynamicDpClusterAttr_s
{
    MI_ISP_IQ_Bool_e bEdgeMode;
    MI_U16           u16NeiDeltaTh;
    MI_U8            u8NeiSmooth;
    MI_ISP_IQ_Bool_e bSortEn;
    MI_ISP_IQ_Bool_e bSortRGGBEn[DYNAMIC_DP_CLUSTER_CH_NUM];
    MI_ISP_IQ_Bool_e bSort1x3ModeEn;
    MI_U16           u16SortLumTblL[DYNAMIC_DP_CLUSTER_TBL_NUM];
    MI_U16           u16SortLumTblD[DYNAMIC_DP_CLUSTER_TBL_NUM];
    MI_U16           u16SortLumTblS[DYNAMIC_DP_CLUSTER_TBL_NUM];
} MI_ISP_IQ_DynamicDpClusterAttr_t;

typedef struct MI_ISP_IQ_DynamicDpClusterManualAttr_s
{
    MI_ISP_IQ_DynamicDpClusterAttr_t stParaAPI;
} MI_ISP_IQ_DynamicDpClusterManualAttr_t;

typedef struct MI_ISP_IQ_DynamicDpClusterAutoAttr_s
{
    MI_ISP_IQ_DynamicDpClusterAttr_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_DynamicDpClusterAutoAttr_t;

typedef struct MI_ISP_IQ_DynamicDpClusterType_s
{
    MI_ISP_IQ_Bool_e                       bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e                     enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_DynamicDpClusterAutoAttr_t   stAuto;
    MI_ISP_IQ_DynamicDpClusterManualAttr_t stManual;
} MI_ISP_IQ_DynamicDpClusterType_t;

typedef struct MI_ISP_IQ_HsvParam_s
{
    MI_S16 s16HueByHueLut[HSV_HUE_NUM];       //  -127 ~  127
    MI_U16 u16HueBySatLut[HSV_SAT_NUM];       //  0 ~ 255 (128->1X)
    MI_U16 u16HueByYLut[HSV_Y_NUM];           //  0 ~ 255 (128->1X)
    MI_U16 u16SatByHueLut[HSV_HUE_NUM];       //  0 ~  255(128->1X)
    MI_S16 s16SatBySatLut[HSV_SAT_NUM];       //  -511 ~ 511
    MI_U16 u16SatByYLut[HSV_Y_NUM];           //  0 ~ 255 (128->1X)
    MI_S16 s16SatBySYLut[HSV_Y_NUM];          //  -511 ~ 511
    MI_S16 s16YByHueLut[HSV_HUE_NUM];         //  -511 ~  511
    MI_U16 u16YBySatLut[HSV_SAT_NUM];         //  0 ~ 255 (128->1X)
    MI_U16 u16YByYLut[HSV_Y_NUM];             //  0 ~ 255 (128->1X)
    MI_S16 s16HueByHueLut_ByIso[HSV_HUE_NUM]; //  -127 ~  127
    MI_U16 u16HueBySatLut_ByIso[HSV_SAT_NUM]; //  0 ~ 255 (128->1X)
    MI_U16 u16HueByYLut_ByIso[HSV_Y_NUM];     //  0 ~ 255 (128->1X)
    MI_U16 u16SatByHueLut_ByIso[HSV_HUE_NUM]; //  0 ~  255(128->1X)
    MI_S16 s16SatBySatLut_ByIso[HSV_SAT_NUM]; //  -511 ~ 511
    MI_U16 u16SatByYLut_ByIso[HSV_Y_NUM];     //  0 ~ 255 (128->1X)
    MI_S16 s16SatBySYLut_ByIso[HSV_Y_NUM];    //  -511 ~ 511
    MI_S16 s16YByHueLut_ByIso[HSV_HUE_NUM];   //  -511 ~  511
    MI_U16 u16YBySatLut_ByIso[HSV_SAT_NUM];   //  0 ~ 255 (128->1X)
    MI_U16 u16YByYLut_ByIso[HSV_Y_NUM];       //  0 ~ 255 (128->1X)
    MI_ISP_IQ_Bool_e bVibranceEn;             //  0 ~ 1
    MI_U8  u8GrayProtectStrength;             //  0~63
    MI_U16 u16GrayProtectTh;                  //  0~1023
    MI_U8  u8DebugMode;                       //  0 ~ 4
} MI_ISP_IQ_HsvParam_t;

typedef struct MI_ISP_IQ_HsvManualAttr_s
{
    MI_ISP_IQ_HsvParam_t stParaAPI;
} MI_ISP_IQ_HsvManualAttr_t;

typedef struct MI_ISP_IQ_HsvAutoAttr_s
{
    MI_ISP_IQ_HsvParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_HsvAutoAttr_t;

typedef struct MI_ISP_IQ_HsvType_s
{
    MI_ISP_IQ_Bool_e          bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e        enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_HsvAutoAttr_t   stAuto;
    MI_ISP_IQ_HsvManualAttr_t stManual;
} MI_ISP_IQ_HsvType_t;

typedef struct MI_ISP_IQ_RgbirParam_s
{
    MI_U8            u8IrPosType; // 0 ~ 7, def : 0
    MI_ISP_IQ_Bool_e bRemovelEn;  // 0 ~ 1, def : 1
    MI_U16           u16Ratio_R[RGBIR_BY_Y_NUM];
    MI_U16           u16Ratio_G[RGBIR_BY_Y_NUM];
    MI_U16           u16Ratio_B[RGBIR_BY_Y_NUM];
} MI_ISP_IQ_RgbirParam_t;

typedef struct MI_ISP_IQ_RgbirManualAttr_s
{
    MI_ISP_IQ_RgbirParam_t stParaAPI;
} MI_ISP_IQ_RgbirManualAttr_t;

typedef struct MI_ISP_IQ_RgbirAutoAttr_s
{
    MI_ISP_IQ_RgbirParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_RgbirAutoAttr_t;

typedef struct MI_ISP_IQ_RgbirType_s
{
    MI_ISP_IQ_Bool_e            bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e          enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_RgbirAutoAttr_t   stAuto;
    MI_ISP_IQ_RgbirManualAttr_t stManual;
} MI_ISP_IQ_RgbirType_t;

typedef struct MI_ISP_IQ_FpnType_s
{
    MI_ISP_IQ_Bool_e bEnable; // 0 ~ 1
} MI_ISP_IQ_FpnType_t;

typedef struct MI_ISP_IQ_PfcParam_s
{
    MI_U8 u8Strength;                                // 0 ~ 255
    MI_U8 u8UStrength;                               // 0 ~ 63
    MI_U8 u8VStrength;                               // 0 ~ 63
    MI_U8 u8StrengthByY[PFC_BY_Y_NUM];               // 0 ~ 255
    MI_U8 u8FlatProtect;                             // 0 ~ 127
    MI_U8 u8SatByY[PFC_LUT_NUM];                     // 0 ~ 25
    MI_U8 u8StrengthByContrast[PFC_BY_CONTRAST_NUM]; // 0 ~ 127
} MI_ISP_IQ_PfcParam_t;

typedef struct MI_ISP_IQ_PfcManualAttr_s
{
    MI_ISP_IQ_PfcParam_t stParaAPI;
} MI_ISP_IQ_PfcManualAttr_t;

typedef struct MI_ISP_IQ_PfcAutoAttr_s
{
    MI_ISP_IQ_PfcParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_PfcAutoAttr_t;

typedef struct MI_ISP_IQ_PfcType_s
{
    MI_ISP_IQ_Bool_e          bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e        enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_PfcAutoAttr_t   stAuto;
    MI_ISP_IQ_PfcManualAttr_t stManual;
} MI_ISP_IQ_PfcType_t;

typedef struct MI_ISP_IQ_PfcExParam_s
{
    MI_ISP_IQ_Bool_e bDbgEn;                             // 0 ~ 1
    MI_U8            u8SatMaskSel;                       // 0 ~ 1
    MI_ISP_IQ_Bool_e bSatAmpEn;                          // 0 ~ 1
    MI_U8            u8StrengthByHue[PFC_EX_BY_HUE_NUM]; // 0 ~ 255
} MI_ISP_IQ_PfcExParam_t;

typedef struct MI_ISP_IQ_PfcExManualAttr_s
{
    MI_ISP_IQ_PfcExParam_t stParaAPI;
} MI_ISP_IQ_PfcExManualAttr_t;

typedef struct MI_ISP_IQ_PfcExType_s
{
    MI_ISP_IQ_Bool_e            bEnable; // 0 ~ 1
    MI_ISP_IQ_PfcExManualAttr_t stManual;
} MI_ISP_IQ_PfcExType_t;

typedef struct MI_ISP_IQ_DemosaicParam_s
{
    MI_U8            u8DbgMode;            // 0~2
    MI_U8            u8IsoTh;              // 0~127
    MI_U8            u8GradientTh;         // 32~63
    MI_ISP_IQ_Bool_e bSmoEn;               // 0~1
    MI_U8            u8SmoRange;           // 0~7
    MI_U8            u8SmoStrength;        // 0~255
    MI_ISP_IQ_Bool_e bDtlEn;               // 0~1
    MI_ISP_IQ_Bool_e bDtlBypassColorCheck; // 0~1
    MI_U8            u8DtlColorRatio;      // 0~255
    MI_U8            u8DtlColorOft;        // 0~63
    MI_U8            u8DtlHScale;          // 0~15
    MI_U8            u8DtlMScale;          // 0~15
} MI_ISP_IQ_DemosaicParam_t;

typedef struct MI_ISP_IQ_DemosaicManualAttr_s
{
    MI_ISP_IQ_DemosaicParam_t stParaAPI;
} MI_ISP_IQ_DemosaicManualAttr_t;

typedef struct MI_ISP_IQ_DemosaicAutoAttr_s
{
    MI_ISP_IQ_DemosaicParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_DemosaicAutoAttr_t;

typedef struct MI_ISP_IQ_DemosaicType_s
{
    MI_ISP_IQ_Bool_e               bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e             enOpType; // OP_TYP_AUTO ~ (OP_TPY_MODMAX-1)
    MI_ISP_IQ_DemosaicAutoAttr_t   stAuto;
    MI_ISP_IQ_DemosaicManualAttr_t stManual;
} MI_ISP_IQ_DemosaicType_t;

typedef struct MI_ISP_IQ_ColorTransParam_s
{
    MI_U16 u16Y_OFST;                        // 0 ~ 2047
    MI_U16 u16U_OFST;                        // 0 ~ 2047
    MI_U16 u16V_OFST;                        // 0 ~ 2047
    MI_U16 u16Matrix[COLORTRANS_MATRIX_NUM]; // 0 ~ 1023
} MI_ISP_IQ_ColorTransParam_t;

typedef struct MI_ISP_IQ_ColorTransManualAttr_s
{
    MI_ISP_IQ_ColorTransParam_t stParaAPI;
} MI_ISP_IQ_ColorTransManualAttr_t;

typedef struct MI_ISP_IQ_ColorTransType_s
{
    MI_ISP_IQ_Bool_e                 bEnable; // 0 ~ 1
    MI_ISP_IQ_ColorTransManualAttr_t stManual;
} MI_ISP_IQ_ColorTransType_t;

typedef struct MI_ISP_IQ_CTEx_s
{
    MI_U8 u8Type;                            // 0 ~ 5
} MI_ISP_IQ_CTEx_t;

typedef struct MI_ISP_IQ_CTExManualAttr_s
{
    MI_ISP_IQ_CTEx_t stParaAPI;
} MI_ISP_IQ_CTExManualAttr_t;

typedef struct MI_ISP_IQ_CTExType_s
{
    MI_ISP_IQ_Bool_e                 bEnable; // 0 ~ 1
    MI_ISP_IQ_CTExManualAttr_t       stManual;
} MI_ISP_IQ_CTExType_t;

typedef struct MI_ISP_IQ_HdrParam_s
{
    MI_U16 u16YwtTh1;                            // 0 ~ 1023
    MI_U16 u16YwtTh2;                            // 0 ~ 1023
    MI_U16 u16NoiseLevel[HDR_BY_Y_NUM];          // 0 ~ 16383
    MI_U8  u8YSrcStr[HDR_BLEND_V_NUM];           // 0 ~ 255
    MI_U8  u8NrStr;                              // 0 ~ 63
    MI_U8  u8NrPreStr;                           // 0 ~ 63
    MI_U16 u16NrYTh1;                            // 0 ~ 1023
    MI_U16 u16NrYTh2;                            // 0 ~ 1023
    MI_U8  u8NrYGain[HDR_LUT_Y_NUM];             // 0 ~ 255
    MI_U8  u8NrYSft[HDR_LUT_X_NUM];              // 0 ~ 7
    MI_U8  u8NrKernelStr;                        // 0 ~ 7
    MI_U8  u8NrKernelStrWei[HDR_STR_BY_DIFF]; // 0 ~ 31
    MI_U8  u8MotAdjSft1[HDR_MOT_LUT_X_NUM];      // 0 ~ 7
    MI_U8  u8MoLuBlendSft[HDR_BLEND_LUT_X_NUM];  // 0 ~ 7
    MI_U16 u16MotAdj1[HDR_MOT_LUT_Y_NUM];        // 0 ~ 256
    MI_U16 u16MotAdj2[HDR_MOT_LUT_Y_NUM];        // 0 ~ 256
    MI_U16 u16MotAdj3[HDR_MOT_LUT_Y_NUM];        // 0 ~ 256
    MI_U16 u16MoLuBlendY[HDR_BLEND_LUT_Y_NUM];   // 0 ~ 256
} MI_ISP_IQ_HdrParam_t;

typedef struct MI_ISP_IQ_HdrManualAttr_s
{
    MI_ISP_IQ_HdrParam_t stParaAPI;
} MI_ISP_IQ_HdrManualAttr_t;

typedef struct MI_ISP_IQ_HdrAutoAttr_s
{
    MI_ISP_IQ_HdrParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_HdrAutoAttr_t;

typedef struct MI_ISP_IQ_HdrType_s
{
    MI_ISP_IQ_Bool_e          bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e        enOpType; // OP_TYP_AUTO ~ (OP_TPY_MODMAX-1)
    MI_ISP_IQ_HdrAutoAttr_t   stAuto;
    MI_ISP_IQ_HdrManualAttr_t stManual;
} MI_ISP_IQ_HdrType_t;

typedef struct MI_ISP_IQ_HdrExParam_s
{
    MI_ISP_IQ_Bool_e bDbgEn;                             // 0 ~ 1
    MI_ISP_IQ_Bool_e bDynRatioEn;                        // 0 ~ 1
    MI_ISP_IQ_Bool_e bNrEn;                              // 0 ~ 1
    MI_U16           u16SensorExpRatio;                  // 1024 ~ 65536
    MI_U8            u8DynRatioSrcSel;                   // 0 ~ 1
    MI_U8            u8YSrcSel;                          // 0 ~ 1
    MI_U8            u8NoiseLevelSrcSel;                 // 0 ~ 3
    MI_U8            u8MotMaxVal;                        // 0 ~ 7
    MI_U8            u8MotAdjSft2[HDR_EX_MOT_LUT_X_NUM]; // 0 ~ 7
} MI_ISP_IQ_HdrExParam_t;

typedef struct MI_ISP_IQ_HdrExManualAttr_s
{
    MI_ISP_IQ_HdrExParam_t stParaAPI;
} MI_ISP_IQ_HdrExManualAttr_t;

typedef struct MI_ISP_IQ_HdrExType_s
{
    MI_ISP_IQ_Bool_e            bEnable; // 0 ~ 1
    MI_ISP_IQ_HdrExManualAttr_t stManual;
} MI_ISP_IQ_HdrExType_t;

typedef enum __attribute__((aligned(4)))
{
    E_EFFECT_VIVID       = 0,
    E_EFFECT_PALE        = 1,
    E_EFFECT_SEPIA       = 2,
    E_EFFECT_BLACK_WHITE = 3,
    E_EFFECT_EMBOSS      = 4,
    E_EFFECT_NEGATIVE    = 5,
    E_EFFECT_SKETCH      = 6,
    E_EFFECT_OIL         = 7,
    E_EFFECT_MAX
} MI_ISP_IQ_Effect_e;

typedef struct MI_ISP_IQ_EffectType_s
{
    MI_ISP_IQ_Bool_e   bEnable;
    MI_ISP_IQ_Effect_e eStyle;
    MI_U8              u8Level;
} MI_ISP_IQ_EffectType_t;

typedef struct MI_ISP_IQ_SysMcnrMemoryType_s
{
    MI_ISP_IQ_Bool_e bEnable; // 0 ~ 1
} MI_ISP_IQ_SysMcnrMemoryType_t;

typedef struct
{
    MI_U16 u16NumOfPoints;
    MI_S32 s32Y[INTP_LUT_NUM];
    MI_S32 s32X[INTP_LUT_NUM];
} MI_ISP_IQ_IntpLut_t;

typedef struct MI_ISP_IQ_LscType_s
{
    MI_ISP_IQ_Bool_e bEnable; // 0 ~ 1
    MI_U16           u16CenterX;
    MI_U16           u16CenterY;
    MI_U16           u16RateX;
    MI_U16           u16RateY;
    MI_U8            u8Shift;
    MI_U16           u16RGainTable[LSC_TBL_SIZE * LSC_CCT_NUM_MAX];
    MI_U16           u16GGainTable[LSC_TBL_SIZE * LSC_CCT_NUM_MAX];
    MI_U16           u16BGainTable[LSC_TBL_SIZE * LSC_CCT_NUM_MAX];
} MI_ISP_IQ_LscType_t;

typedef struct MI_ISP_IQ_LscCtrlType_s
{
    MI_ISP_IQ_Bool_e    bEnable; // 0 ~ 1
    MI_U8               u8RRatioByCct[LSC_CCT_NUM_MAX];
    MI_U8               u8GRatioByCct[LSC_CCT_NUM_MAX];
    MI_U8               u8BRatioByCct[LSC_CCT_NUM_MAX];
    MI_ISP_IQ_IntpLut_t RatioByBv;
} MI_ISP_IQ_LscCtrlType_t;

typedef struct MI_ISP_IQ_AlscType_s
{
    MI_ISP_IQ_Bool_e bEnable; // 0 ~ 1
    MI_U8            u8GridX;
    MI_U8            u8GridY;
    MI_U16           u16CCTthr[ALSC_CCT_NUM_MAX];
    MI_U8            u8DeltaMode;
    MI_ISP_IQ_Bool_e bDeltaModeAdvEn;
    MI_U8            u8DeltaLutX[ALSC_DELTA_LUT_NUM];
    MI_U8            u8DeltaLutY[ALSC_DELTA_LUT_NUM];
    MI_U16           u16TableR[ALSC_CCT_NUM_MAX][ALSC_TBL_MAX];
    MI_U16           u16TableG[ALSC_CCT_NUM_MAX][ALSC_TBL_MAX];
    MI_U16           u16TableB[ALSC_CCT_NUM_MAX][ALSC_TBL_MAX];
} MI_ISP_IQ_AlscType_t;

typedef struct MI_ISP_IQ_AlscCtrlType_s
{
    MI_ISP_IQ_Bool_e    bEnable; // 0 ~ 1
    MI_U8               u8RRatioByCct[ALSC_CCT_NUM_MAX];
    MI_U8               u8GRatioByCct[ALSC_CCT_NUM_MAX];
    MI_U8               u8BRatioByCct[ALSC_CCT_NUM_MAX];
    MI_ISP_IQ_IntpLut_t RatioByBv;
} MI_ISP_IQ_AlscCtrlType_t;

typedef struct MI_ISP_IQ_R2YParam_s
{
    MI_U16 u16Matrix[R2Y_MATRIX_NUM];
    MI_U8  u8AddY16;
} MI_ISP_IQ_R2YParam_t;

typedef struct MI_ISP_IQ_R2YManualAttr_s
{
    MI_ISP_IQ_R2YParam_t stParaAPI;
} MI_ISP_IQ_R2YManualAttr_t;

typedef struct MI_ISP_IQ_R2YType_s
{
    MI_ISP_IQ_Bool_e          bEnable; // 0 ~ 1
    MI_ISP_IQ_R2YManualAttr_t stManual;
} MI_ISP_IQ_R2YType_t;

typedef struct MI_ISP_IQ_DummyAttr_s
{
    MI_S16 s16Dummy0[DUMMY_NUM];
    MI_S16 s16Dummy1[DUMMY_NUM];
    MI_S16 s16Dummy2[DUMMY_NUM];
    MI_S16 s16Dummy3;
    MI_S16 s16Dummy4;
} MI_ISP_IQ_DummyAttr_t;

typedef struct MI_ISP_IQ_DummyManualAttr_s
{
    MI_ISP_IQ_DummyAttr_t stParaAPI;
} MI_ISP_IQ_DummyManualAttr_t;

typedef struct MI_ISP_IQ_DummyAutoAttr_s
{
    MI_ISP_IQ_DummyAttr_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_DummyAutoAttr_t;

typedef struct MI_ISP_IQ_DummyType_s
{
    MI_ISP_IQ_Bool_e            bEnable;  // 0 ~ 1
    MI_ISP_IQ_OpType_e          enOpType; // OP_TYP_AUTO ~ (OP_TPY_MODMAX-1)
    MI_ISP_IQ_Bool_e            bLogEn;
    MI_ISP_IQ_DummyAutoAttr_t   stAuto;
    MI_ISP_IQ_DummyManualAttr_t stManual;
} MI_ISP_IQ_DummyType_t;

typedef struct MI_ISP_IQ_DummyExAttr_s
{
    MI_S16 s16DummyEx0[DUMMY_EX_NUM];
    MI_S16 s16DummyEx1[DUMMY_EX_NUM];
    MI_S16 s16DummyEx2[DUMMY_EX_NUM];
    MI_S16 s16DummyEx3;
    MI_S16 s16DummyEx4;
} MI_ISP_IQ_DummyExAttr_t;

typedef struct MI_ISP_IQ_DummyExManualAttr_s
{
    MI_ISP_IQ_DummyExAttr_t stParaAPI;
} MI_ISP_IQ_DummyExManualAttr_t;

typedef struct MI_ISP_IQ_DummyExType_s
{
    MI_ISP_IQ_Bool_e              bEnable; // 0 ~ 1
    MI_ISP_IQ_Bool_e              bLogEn;
    MI_ISP_IQ_DummyExManualAttr_t stManual;
} MI_ISP_IQ_DummyExType_t;

typedef struct MI_ISP_IQ_TempParam_s
{
    MI_S16 s16ObcOffset;
    MI_U8  u8DynamicDPRatio;
    MI_U8  u8CrosstalkRatio;
    MI_U8  u8NRDeSpikeRatio;
    MI_U8  u8NR3DRatio[TEMP_NR3D_NUM];
    MI_U8  u8NRLumaRatio;
    MI_U8  u8SharpnessRatio[TEMP_SHARPNESS_NUM];
    MI_U8  u8SaturationRatio;
    MI_U8  u8ColorToneRatio[TEMP_COLOR_TONE_NUM];
} MI_ISP_IQ_TempParam_t;

typedef struct MI_ISP_IQ_TempManualAttr_s
{
    MI_ISP_IQ_TempParam_t stParaAPI;
} MI_ISP_IQ_TempManualAttr_t;

typedef struct MI_ISP_IQ_TempAutoAttr_s
{
    MI_ISP_IQ_TempParam_t stParaAPI[MI_ISP_AUTO_NUM];
} MI_ISP_IQ_TempAutoAttr_t;

typedef struct MI_ISP_IQ_TempType_s
{
    MI_ISP_IQ_Bool_e           bEnable; // 0 ~ 1
    MI_U8                      u8TemperatureLut[TEMP_LUT_NUM];
    MI_ISP_IQ_OpType_e         enOpType; // M_AUTO ~ (M_MODMAX-1)
    MI_ISP_IQ_TempAutoAttr_t   stAuto;
    MI_ISP_IQ_TempManualAttr_t stManual;
} MI_ISP_IQ_TempType_t;

typedef struct MI_ISP_IQ_TempInfoType_s
{
    MI_U8 u8Temperature;
} MI_ISP_IQ_TempInfoType_t;

typedef enum __attribute__((aligned(4)))
{
    E_IND0_GRAY = 0,
    E_IND1_R1,
    E_IND2_G1,
    E_IND3_B1,
    E_IND4_C1,
    E_IND5_M1,
    E_IND6_Y1,
    E_IND7_R2,
    E_IND8_G2,
    E_IND9_B2,
    E_IND10_C2,
    E_IND11_M2,
    E_IND12_Y2,
    E_IND13_SKIN1,
    E_IND14_SKIN2,
    E_IND15_SKIN3,
    E_IND16_MAX,
} MI_ISP_IQ_CsaLutInd_e;

typedef enum __attribute__((aligned(4)))
{
    E_CSA_MOD_BLUE = 0,
    E_CSA_MOD_GREEN,
    E_CSA_MOD_BG,
    E_CSA_MOD_SKIN,
    E_CSA_MOD_VIVID,  // all ind
    E_CSA_MOD_MANUAL, // selected ind
    // E_CSA_MODE_BUTT
    E_CSA_MOD_MAX,
} MI_ISP_IQ_CsaMode_e;

typedef struct MI_ISP_IQ_CsaParam_s
{
} MI_ISP_IQ_CsaParam_t;

typedef struct MI_ISP_IQ_CsaManualAttr_s
{
} MI_ISP_IQ_CsaManualAttr_t;

typedef struct MI_ISP_IQ_CsaType_s
{
} MI_ISP_IQ_CsaType_t;

typedef struct MI_ISP_IQ_DaynightInfoType_s
{
    MI_ISP_IQ_Bool_e bD2N;
    MI_ISP_IQ_Bool_e bN2D;
    MI_U32           u32N2D_VsbLtScore;
} MI_ISP_IQ_DaynightInfoType_t;

typedef struct MI_ISP_IQ_DaynightDetectionType_s
{
    MI_ISP_IQ_Bool_e bEnable;
    MI_S32           s32D2N_BvThd;
    MI_U32           u32N2D_VsbLtScoreThd;
} MI_ISP_IQ_DaynightDetectionType_t;
typedef struct MI_ISP_IQ_NrLumaParam_s
{
} MI_ISP_IQ_NrLumaParam_t;

typedef struct MI_ISP_IQ_NrLumaManualAttr_s
{
} MI_ISP_IQ_NrLumaManualAttr_t;

typedef struct MI_ISP_IQ_NrLumaType_s
{
} MI_ISP_IQ_NrLumaType_t;

typedef struct MI_ISP_IQ_YclpfParam_s
{
} MI_ISP_IQ_YclpfParam_t;

typedef struct MI_ISP_IQ_YclpfManualAttr_s
{
} MI_ISP_IQ_YclpfManualAttr_t;

typedef struct MI_ISP_IQ_YclpfType_s
{
} MI_ISP_IQ_YclpfType_t;

typedef struct MI_ISP_IQ_WdrLceParam_s
{
} MI_ISP_IQ_WdrLceParam_t;

typedef struct MI_ISP_IQ_WdrLceManualAttr_s
{
} MI_ISP_IQ_WdrLceManualAttr_t;

typedef struct MI_ISP_IQ_WdrLceType_s
{
} MI_ISP_IQ_WdrLceType_t;
#endif
/************************************* API20 Define the structure declaration END *************************************/

/************************************* IQ Define the structure declaration START **************************************/
#if 1 // ISP IQ API

#define GAMMA_LUT_NUM 256
#define OBC4CH_NUM    4

typedef struct MI_ISP_IQ_VersionInfoParam_s
{
    MI_U32 u32Vendor;
    MI_U32 u32Major;
    MI_U32 u32Minor;
} MI_ISP_IQ_VersionInfoParam_t;

typedef struct MI_ISP_IQ_VersionInfoType_s
{
    MI_ISP_IQ_VersionInfoParam_t stParaAPI;
} MI_ISP_IQ_VersionInfoType_t;

typedef struct MI_ISP_IQ_ParamInitInfoParam_s
{
    MI_ISP_IQ_Bool_e bFlag;
} MI_ISP_IQ_ParamInitInfoParam_t;

typedef struct MI_ISP_IQ_ParamInitInfoType_s
{
    MI_ISP_IQ_ParamInitInfoParam_t stParaAPI;
} MI_ISP_IQ_ParamInitInfoType_t;

typedef struct MI_ISP_IQ_FastModeParam_s
{
    MI_ISP_IQ_Bool_e bFastMode;
} MI_ISP_IQ_FastModeParam_t;

typedef struct MI_ISP_IQ_FastModeType_s
{
    MI_ISP_IQ_FastModeParam_t stParaAPI;
} MI_ISP_IQ_FastModeType_t;

typedef enum __attribute__((aligned(4)))
{
    E_SS_IQ_PARAM_MODE_NORMAL = 0,
    E_SS_IQ_PARAM_MODE_NIGHT  = 1, // Night Mode
    E_SS_IQ_PARAM_MODE_MAX
} MI_ISP_IQ_ParamMode_e;

typedef struct MI_ISP_IQ_GammaLutType_s
{
    MI_U16 u16LutR[GAMMA_LUT_NUM];
    MI_U16 u16LutG[GAMMA_LUT_NUM];
    MI_U16 u16LutB[GAMMA_LUT_NUM];
} MI_ISP_IQ_GammaLutType_t;

typedef struct MI_ISP_IQ_Obc4ChType_s
{
    MI_U16 u16OBC4Ch[OBC4CH_NUM];
} MI_ISP_IQ_Obc4ChType_t;
#endif
/************************************* IQ Define the structure declaration END ****************************************/

/************************************* MAINTOOL Define the structure declaration END **********************************/
#if 1 // MAINTOOL API
typedef enum __attribute__((aligned(4)))
{
    E_SS_IQ_INDEX_0 = 0,
    E_SS_IQ_INDEX_1,
    E_SS_IQ_INDEX_2,
    E_SS_IQ_INDEX_3,
    E_SS_IQ_INDEX_4,
    E_SS_IQ_INDEX_5,
    E_SS_IQ_INDEX_6,
    E_SS_IQ_INDEX_7,
    E_SS_IQ_INDEX_8,
    E_SS_IQ_INDEX_9,
    E_SS_IQ_INDEX_10,
    E_SS_IQ_INDEX_11,
    E_SS_IQ_INDEX_12,
    E_SS_IQ_INDEX_13,
    E_SS_IQ_INDEX_14,
    E_SS_IQ_INDEX_15,
    E_SS_IQ_INDEX_MAX
} MI_ISP_IQ_Index_e;

typedef enum __attribute__((aligned(4)))
{
    E_SS_BYPASS_OFF = 0,
    E_SS_BYPASS_ON,
    E_SS_BYPASS_MAX
} MI_ISP_IQ_BypassMode_e;

typedef struct MI_ISP_IQ_ApiBypassType_s
{
    MI_ISP_IQ_BypassMode_e bEnable; // 0 ~ 1
    MI_ISP_IQ_ApiId_e      eAPIIndex;
} MI_ISP_IQ_ApiBypassType_t;
#endif
/************************************* MAINTOOL Define the structure declaration END **********************************/

#endif /* _MI_ISP_IQ_DATATYPE_H_ */
