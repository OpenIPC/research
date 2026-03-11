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
*   mi_isp_datatype.h
*
*   Created on: June 27, 2018
*       Author: Jeffrey Chou
*/

#ifndef _MI_ISP_HW_DEP_DATATYPE_H_
#define _MI_ISP_HW_DEP_DATATYPE_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "mi_common.h"
#include "mi_sys_datatype.h"
#include "mi_isp_af_datatype.h"
#include "mi_isp_iq_datatype.h"

#define MI_ISP_NAME ISP_MUFFIN

#define SENSOR_ID_CHAR_SIZE   32
#define ROOT_PATH_STRING_SIZE 64

#define AE_HW_STAT_BLOCK            128 * 90
#define AWB_HW_STAT_BLOCK           128 * 90
#define HISTO_HW_STAT_BIN           128
#define RGBIR_HISTO_HW_STAT_BIN     256
#define YUV_HISTO_HW_STAT_BIN       256
#define AF_STATS_IIR_1_SIZE         5
#define AF_STATS_IIR_2_SIZE         5
#define AF_STATS_LUMA_SIZE          5
#define AF_STATS_FIR_V_SIZE         5
#define AF_STATS_FIR_H_SIZE         5
#define AF_STATS_YSAT_SIZE          3
#define AF_STATS_VERTICAL_BLOCK_MAX 16

/************************** Cus3A ***********************/
typedef struct
{
    MI_U8 uAvgR;
    MI_U8 uAvgG;
    MI_U8 uAvgB;
    MI_U8 uAvgY;
} MI_ISP_AE_AVGS;

typedef struct
{
    MI_U32 nBlkX;
    MI_U32 nBlkY;
    MI_ISP_AE_AVGS nAvg[AE_HW_STAT_BLOCK];
}MI_ISP_AE_HW_STATISTICS_t;

typedef struct
{
    MI_U8 uAvgR;
    MI_U8 uAvgG;
    MI_U8 uAvgB;
} MI_ISP_AWB_AVGS;

typedef struct
{
    MI_U32 nBlkX;
    MI_U32 nBlkY;
    MI_ISP_AWB_AVGS nAvg[AWB_HW_STAT_BLOCK];
} MI_ISP_AWB_HW_STATISTICS_t;

typedef struct
{
    MI_U16 nHisto[HISTO_HW_STAT_BIN];
} MI_ISP_HISTO_HW_STATISTICS_t;

typedef struct
{
    MI_U16 nHisto[RGBIR_HISTO_HW_STAT_BIN];
} MI_ISP_RGBIR_HISTO_HW_STATISTICS_t;

typedef struct
{
    MI_U16 nHisto[YUV_HISTO_HW_STAT_BIN];
} MI_ISP_YUV_HISTO_HW_STATISTICS_t;

typedef struct
{
    MI_BOOL bAE;
    MI_BOOL bAWB;
    MI_BOOL bAF;
}Cus3AEnable_t;

typedef struct
{
    MI_BOOL bInject3A;
}CusInject3AEnable_t;

typedef struct
{
    MI_U32 Size;                            /**< struct size*/
    char sensor_id[SENSOR_ID_CHAR_SIZE];    /**< sensor module id*/
    MI_U32 shutter;                         /**< shutter Shutter in ns*/
    MI_U32 shutter_step;                    /**< shutter Shutter step ns*/
    MI_U32 shutter_min;                     /**< shutter Shutter min us*/
    MI_U32 shutter_max;                     /**< shutter Shutter max us*/
    MI_U32 sensor_gain;                     /**< sensor_gain Sensor gain, 1X = 1024*/
    MI_U32 sensor_gain_min;                 /**< sensor_gain_min Minimum Sensor gain, 1X = 1024*/
    MI_U32 sensor_gain_max;                 /**< sensor_gain_max Maximum Sensor gain, 1X = 1024*/
    MI_U32 isp_gain;                        /**< isp_gain Isp digital gain , 1X = 1024 */
    MI_U32 isp_gain_max;                    /**< isp_gain Maximum Isp digital gain , 1X = 1024 */
    MI_U32 FNx10;                           /**< F number * 10*/
    MI_U32 fps;                             /**< initial frame per second*/
    MI_U32 shutterHDRShort_step;            /**< shutter Shutter step ns*/
    MI_U32 shutterHDRShort_min;             /**< shutter Shutter min us*/
    MI_U32 shutterHDRShort_max;             /**< shutter Shutter max us*/
    MI_U32 sensor_gainHDRShort_min;         /**< sensor_gain_min Minimum Sensor gain, 1X = 1024*/
    MI_U32 sensor_gainHDRShort_max;         /**< sensor_gain_max Maximum Sensor gain, 1X = 1024*/
    /*CUS3A v1.1*/
    MI_U32 AvgBlkX;                         /**< HW statistics average block number*/
    MI_U32 AvgBlkY;                         /**< HW statistics average block number*/
}CusAEInitParam_t,CusAeInitParam_t;

typedef struct
{
    MI_U8 nDevId;
    MI_U8 nCh;
} CusSync3AChanMap;

/*! @brief ISP report to AE, hardware statistic */
typedef struct
{
    MI_U32 Size;                            /**< struct size*/
    void   *hist1;                          /**< HW statistic histogram 1*/
    void   *hist2;                          /**< HW statistic histogram 2*/
    MI_U32 AvgBlkX;                         /**< HW statistics average block number*/
    MI_U32 AvgBlkY;                         /**< HW statistics average block number*/
    void * avgs;                            /**< HW statistics average block data*/
    MI_U32 Shutter;                         /**< Current shutter in ns*/
    MI_U32 SensorGain;                      /**< Current Sensor gain, 1X = 1024 */
    MI_U32 IspGain;                         /**< Current ISP gain, 1X = 1024*/
    MI_U32 ShutterHDRShort;                 /**< Current shutter in ns*/
    MI_U32 SensorGainHDRShort;              /**< Current Sensor gain, 1X = 1024 */
    MI_U32 IspGainHDRShort;                 /**< Current ISP gain, 1X = 1024*/
    /*CUS3A V1.1*/
    MI_U32 PreAvgY;                         /**< Previous frame brightness*/
    MI_U8  HDRCtlMode;                      /**< 0 = HDR off; */
                                            /**< 1 = Separate shutter & Separate sensor gain settings */
                                            /**< 2 = Separate shutter & Share sensor gain settings */
                                            /**< 3 = Share shutter & Separate sensor gain settings */
    MI_U32 FNx10;                           /**< Aperture in FNx10*/
    MI_U32 CurFPS;                          /**Current sensor FPS */
    MI_U32 PreWeightY;                      /**< Previous frame brightness with ROI weight*/
    /* __ENABLE_ISP_SYNC3A_MODE__ */
    MI_U8 nChGroupID;
    MI_U32 nChSync3AType;
    MI_U8 nGroupSyncChNum;
    CusSync3AChanMap stSync3AChMap[8];
} __attribute__((packed, aligned(1))) CusAEInfo_t, CusAeInput_t;

/*! @brief ISP ae algorithm result*/
typedef struct
{
    MI_U32 Size;                            /**< struct size*/
    MI_U32 Change;                          /**< if true, apply this result to hw register*/
    MI_U32 Shutter;                         /**< Shutter in ns */
    MI_U32 SensorGain;                      /**< Sensor gain, 1X = 1024 */
    MI_U32 IspGain;                         /**< ISP gain, 1X = 1024 */
    MI_U32 ShutterHdrShort;                 /**< Shutter in ns */
    MI_U32 SensorGainHdrShort;              /**< Sensor gain, 1X = 1024 */
    MI_U32 IspGainHdrShort;                 /**< ISP gain, 1X = 1024 */
    MI_U32 u4BVx16384;                      /**< Bv * 16384 in APEX system, EV = Av + Tv = Sv + Bv */
    MI_U32 AvgY;                            /**< frame brightness */
    MI_U32 HdrRatio;                        /**< hdr ratio, 1X = 1024 */
    /*CUS3A V1.1*/
    MI_U32 FNx10;                           /**< F number * 10*/
    MI_U32 DebandFPS;                       /** Target fps when running auto debanding**/
    MI_U32 WeightY;                         /**< frame brightness with ROI weight*/
}__attribute__((packed, aligned(1))) CusAEResult_t, CusAeOutput_t;

/*! @brief AWB HW statistics data*/
typedef struct
{
    MI_U32 Size;                            /**< struct size*/
    MI_U32 AvgBlkX;
    MI_U32 AvgBlkY;
    MI_U32 CurRGain;
    MI_U32 CurGGain;
    MI_U32 CurBGain;
    void *avgs; //ISP_AWB_SAMPLE
    /*CUS3A V1.1*/
    MI_U8  HDRMode;                         /**< Noramal or HDR mode*/
    void*  *pAwbStatisShort;                /**< Short Shutter AWB statistic data */
    MI_U32 u4BVx16384;                      /**< From AE output, Bv * 16384 in APEX system, EV = Av + Tv = Sv + Bv */
    MI_S32 WeightY;                         /**< frame brightness with ROI weight*/
    /* __ENABLE_ISP_SYNC3A_MODE__ */
    MI_U8 nChGroupID;
    MI_U32 nChSync3AType;
    MI_U8 nGroupSyncChNum;
    CusSync3AChanMap stSync3AChMap[8];
}__attribute__((packed, aligned(1))) CusAWBInfo_t, CusAWBInput_t;

/*! @brief AWB algorithm result*/
typedef struct
{
    MI_U32 Size;                            /**< struct size*/
    MI_U32 Change;                          /**< if true, apply this result to hw register*/
    MI_U32 R_gain;                          /**< AWB gain for R channel*/
    MI_U32 G_gain;                          /**< AWB gain for G channel*/
    MI_U32 B_gain;                          /**< AWB gain for B channel*/
    MI_U32 ColorTmp;                        /**< Return color temperature*/
}CusAWBResult_t, CusAwbOutput_t;

typedef enum __attribute__ ((aligned (1)))
{
    SS_AE_16x24 = 0,
    SS_AE_32x24,
    SS_AE_64x48,
    SS_AE_64x45,
    SS_AE_128x80,
    SS_AE_128x90,
    SS_AE_32x32
} MS_CUST_AE_WIN_BLOCK_NUM_TYPE_e;

typedef struct
{
    MI_U16 u2Stawin_x_offset;
    MI_U16 u2Stawin_x_size;
    MI_U16 u2Stawin_y_offset;
    MI_U16 u2Stawin_y_size;
    MI_U16 u2WinIdx;
} CusAEHistWin_t;

typedef struct
{
    MI_U32 SizeX;
    MI_U32 SizeY;
    MI_U32 IncRatio;
}CusAWBSample_t;

typedef struct
{
    MI_U16 CropX;   // 0~1023
    MI_U16 CropY;   // 0~1023
    MI_U16 CropW;   // 0~1023
    MI_U16 CropH;   // 0~1023
}CusAEAWBCropSize_t;

typedef struct
{
    MI_U8 iir_1[AF_STATS_IIR_1_SIZE * AF_HW_WIN_NUM];   //[5]: iir 37bit, use 5*u8 datatype,     [16]: 16wins
    MI_U8 iir_2[AF_STATS_IIR_2_SIZE * AF_HW_WIN_NUM];   //[5]: iir 37bit, use 5*u8 datatype,     [16]: 16wins
    MI_U8 luma[AF_STATS_LUMA_SIZE * AF_HW_WIN_NUM];     //[5]: luma 34bit, use 5*u8 datatype,    [16]: 16wins
    MI_U8 fir_v[AF_STATS_FIR_V_SIZE * AF_HW_WIN_NUM];   //[5]: fir 37bit, use 5*u8 datatype,     [16]: 16wins
    MI_U8 fir_h[AF_STATS_FIR_H_SIZE * AF_HW_WIN_NUM];   //[5]: fir 37bit, use 5*u8 datatype,     [16]: 16wins
    MI_U8 ysat[AF_STATS_YSAT_SIZE * AF_HW_WIN_NUM];     //[3]: ysat 24bit, use 3*u8 datatype,    [16]: 16wins
} AF_STATS_PARAM_t;

typedef struct
{
    AF_STATS_PARAM_t stParaAPI[AF_STATS_VERTICAL_BLOCK_MAX];
} CusAFStats_t;

typedef enum __attribute__ ((aligned (1)))
{
    AF_ROI_MODE_NORMAL,
    AF_ROI_MODE_MATRIX
} ISP_AF_ROI_MODE_e;

typedef struct AF_WINDOW_PARAM_s
{
    MI_U32 u32StartX;   /*range : 0~1023*/
    MI_U32 u32StartY;   /*range : 0~1023*/
    MI_U32 u32EndX;     /*range : 0~1023*/
    MI_U32 u32EndY;     /*range : 0~1023*/
} AF_WINDOW_PARAM_t;

typedef struct
{
    ISP_AF_ROI_MODE_e mode;
    MI_U32 u32_vertical_block_number;
    AF_WINDOW_PARAM_t stParaAPI[AF_HW_WIN_NUM];
} CusAFWin_t;

typedef struct
{
    MI_U32 u32Src1Cnt[AF_HW_WIN_NUM];
    MI_U32 u32Src2Cnt[AF_HW_WIN_NUM];
} CusAFWinPxCntOneRow_t;

typedef struct
{
    CusAFWinPxCntOneRow_t win_px_cnt[AF_STATS_VERTICAL_BLOCK_MAX];
} CusAFWinPxCnt_t;

typedef struct
{
    MI_U16 u16IIR1_a0;
    MI_U16 u16IIR1_a1;
    MI_U16 u16IIR1_a2;
    MI_U16 u16IIR1_b1;
    MI_U16 u16IIR1_b2;
    MI_U16 u16IIR1_1st_low_clip;
    MI_U16 u16IIR1_1st_high_clip;
    MI_U16 u16IIR1_2nd_low_clip;
    MI_U16 u16IIR1_2nd_high_clip;
    MI_U16 u16IIR2_a0;
    MI_U16 u16IIR2_a1;
    MI_U16 u16IIR2_a2;
    MI_U16 u16IIR2_b1;
    MI_U16 u16IIR2_b2;
    MI_U16 u16IIR2_1st_low_clip;
    MI_U16 u16IIR2_1st_high_clip;
    MI_U16 u16IIR2_2nd_low_clip;
    MI_U16 u16IIR2_2nd_high_clip;

    MI_U16 u16IIR1_e1_en;
    MI_U16 u16IIR1_e1_a0;
    MI_U16 u16IIR1_e1_a1;
    MI_U16 u16IIR1_e1_a2;
    MI_U16 u16IIR1_e1_b1;
    MI_U16 u16IIR1_e1_b2;
    MI_U16 u16IIR1_e2_en;
    MI_U16 u16IIR1_e2_a0;
    MI_U16 u16IIR1_e2_a1;
    MI_U16 u16IIR1_e2_a2;
    MI_U16 u16IIR1_e2_b1;
    MI_U16 u16IIR1_e2_b2;

    MI_U16 u16IIR2_e1_en;
    MI_U16 u16IIR2_e1_a0;
    MI_U16 u16IIR2_e1_a1;
    MI_U16 u16IIR2_e1_a2;
    MI_U16 u16IIR2_e1_b1;
    MI_U16 u16IIR2_e1_b2;
    MI_U16 u16IIR2_e2_en;
    MI_U16 u16IIR2_e2_a0;
    MI_U16 u16IIR2_e2_a1;
    MI_U16 u16IIR2_e2_a2;
    MI_U16 u16IIR2_e2_b1;
    MI_U16 u16IIR2_e2_b2;
} CusAFFilter_t;

typedef struct
{
    MI_BOOL bSobelYSatEn;
    MI_U16  u16SobelYThd;

    MI_BOOL bIIRSquareAccEn;
    MI_BOOL bSobelSquareAccEn;

    MI_U16  u16IIR1Thd;
    MI_U16  u16IIR2Thd;
    MI_U16  u16SobelHThd;
    MI_U16  u16SobelVThd;
    MI_U8   u8AFTbl1X[AF_FILTER_SQ_TBL_X_NUM];
    MI_U16  u16AFTbl1Y[AF_FILTER_SQ_TBL_Y_NUM];
    MI_U8   u8AFTbl2X[AF_FILTER_SQ_TBL_X_NUM];
    MI_U16  u16AFTbl2Y[AF_FILTER_SQ_TBL_Y_NUM];
} CusAFFilterSq_t;

typedef struct
{
    MI_U8 u8BnrEn;
    MI_U8 u8FilterStr;
} CusAFBNR_t;

typedef struct
{
    MI_U8 r;
    MI_U8 g;
    MI_U8 b;
} CusAFYParam_t;

typedef enum __attribute__ ((aligned (1)))
{
    AF_SOURCE_BF_3DNR_AF_HDR     = 0,
    AF_SOURCE_FROM_SE_OBC_BF_HDR = 2,
    AF_SOURCE_FROM_SE_WBG_BF_HDR = 3,
    AF_SOURCE_FROM_ALSC_AF_HDR   = 4,
    AF_SOURCE_FROM_WBG_AF_HDR    = 5,
    AF_SOURCE_FROM_LE_OBC_BF_HDR = 6,
    AF_SOURCE_FROM_LE_WBG_BF_HDR = 7,
} CusAFSource_e;

typedef struct
{
    MI_U8 u8IIR1En;
    MI_U8 u8IIR1Cor;  //0, 1, 2, 3: 0x, 1x, 2x, 4x
    MI_U8 u8IIR1Hor;  //0, 1, 2, 3: 0x, 1x, 2x, 4x
    MI_U8 u8IIR1Vert; //0, 1, 2, 3: 0x, 1x, 2x, 4x
    MI_U8 u8IIR1Cent; //0, 1, 2, 3: 1x, 2x, 4x, 8x
    MI_U8 u8IIR1Div;  //0, 1, 2, 3: 1/8x, 1/16x, 1/32x, 1/64x
    MI_U8 u8IIR2En;
    MI_U8 u8IIR2Cor;  //0, 1, 2, 3: 0x, 1x, 2x, 4x
    MI_U8 u8IIR2Hor;  //0, 1, 2, 3: 0x, 1x, 2x, 4x
    MI_U8 u8IIR2Vert; //0, 1, 2, 3: 0x, 1x, 2x, 4x
    MI_U8 u8IIR2Cent; //0, 1, 2, 3: 1x, 2x, 4x, 8x
    MI_U8 u8IIR2Div;  //0, 1, 2, 3: 1/8x, 1/16x, 1/32x, 1/64x

} CusAFPreFilter_t;

typedef struct
{
    MI_U8 u8FIR_b0;
    MI_U8 u8FIR_b1;
    MI_U8 u8FIR_b2;
} CusAFFirFilter_t;

typedef struct
{
    MI_U8  u8YMapEn;
    MI_U8  u8YMapLumaSource;        // 0: bef ymap; 1: aft ymap
    MI_U8  u8YMapX[AF_YMAP_X_NUM];  // 1~9
    MI_U16 u16YMapY[AF_YMAP_Y_NUM]; // 0~1023
    MI_U8  u8LumaSrc;               // 0: bef ymap; 1: aft ymap
} CusAFYMap_t;

typedef struct
{
    MI_U8 u8IIR1En;
    MI_U8 u8IIR2En;
    MI_U8 u8FIRHEn;
    MI_U8 u8FIRVEn;
    MI_U16 u16IIRCurveX[AF_LDG_LUT_NUM];    // 0~1023
    MI_U8  u8IIRCurveY[AF_LDG_LUT_NUM];     // 0~255
    MI_U16 u16FIRCurveX[AF_LDG_LUT_NUM];    // 0~1023
    MI_U8  u8FIRCurveY[AF_LDG_LUT_NUM];     // 0~255
} CusAFLdg_t;

typedef struct
{
    MI_U8 u8IIR1En;
    MI_U8 u8IIR2En;
    MI_U8 u8SubSample;
    MI_U8 u8Overlap;
} CusAFPeakMode_t;

typedef struct
{
    MI_U8 u8GModeEn;
} CusAFGMode_t;

/* Raw store control */
typedef enum
{
    eRawStoreNode_P0HEAD = 0, /* Control by VIF, Do not use */
    eRawStoreNode_P1HEAD = 1, /* Control by VIF, Do not use */
    eRawStoreNode_P0TAIL = 2,
    eRawStoreNode_P1TAIL = 3,
    eRawStoreNode_ISPOUT = 4,
    eRawStoreNode_VDOS   = 5,
    eRawStoreNode_ISPOUT_BEFORE_YEE = 6,
    eRawStoreNode_RGBIR_IR_ONLY = 7
}CameraRawStoreNode_e;

typedef struct
{
    MI_U32 u32image_width;
    MI_U32 u32image_height;
    MI_U32 u32Node;
    MI_U32 u32PixelDepth;
} CusImageResolution_t;

typedef struct
{
    MI_U32 u32enable;
    MI_U32 u32image_width;
    MI_U32 u32image_height;
    MI_U64 u64physical_address;
    MI_U32 u32Node;
} CusISPOutImage_t;

typedef struct
{
    MI_U32 u32enable;
    MI_U32 u32image_width;
    MI_U32 u32image_height;
    MI_U64 u64physical_address;
    MI_U32 u32Node;
    MI_U32 u32PixelDepth;
} CusHdrRawImage_t;

typedef struct
{
    MI_U64 u64Pts;  /** frame PTS */
    MI_U32 u32Shutter;         /**< Shutter in us */
    MI_U32 u32SensorGain;      /**< Sensor gain, 1X = 1024 */
    MI_U32 u32ColorTmp;   /**< Return color temperature*/
} IspFrameMetaInfo_t;

/*! @brief ISP report to AF, hardware status */
typedef struct
{
    MI_U32 Size;       /**< struct size*/
    MI_U32 MinPos;     /**< Maximum position of AF motor */
    MI_U32 MaxPos;     /**< Minimum position of AF motor */
    MI_U32 CurPos;     /**< Current position of AF motor */
} __attribute__((packed, aligned(1))) CusAFInfo_t, CusAfInput_t;

/*! @brief AF algorithm result*/
typedef struct
{
    MI_U32 Size;    /**< struct size*/
    MI_U32 Change;  /**< if true, apply this result to hw register*/
    MI_U32 NextPos;  /**< Next absolute position of AF motor */
}__attribute__((packed, aligned(1))) CusAfResult_t, CusAfOutput_t;

typedef struct
{
    MI_U32 u32SlaveAddr;  //sensor slave address
    MI_U32 u32RegLen;      //sensor register length , 1 or 2 bytes
    MI_U32 u32DataLen;     //sensor register data length, 1 or 2 bytes
    MI_U32 u32I2cSpeed;   //i2c speed , 100/200/300/400 KHz
    MI_U32 u32Reg;        //sensor register address
    MI_U32 u32Data;       //sensor register data
}CusSensorI2cParam_t;

/***************************** end of Cus3A ****************************/

// COMMON API
typedef struct MI_ISP_API_CHANNEL_ID_TYPE_s
{
    MI_U32 u32ChannelID;
} MI_ISP_API_CHANNEL_ID_TYPE_t;

typedef struct MI_ISP_API_USERSPACE3A_ATTR_s
{
    MI_SYS_PixelFormat_e ePixelFmt;
    MI_U32 eSensorBindId;
} MI_ISP_API_USERSPACE3A_ATTR_t;

typedef struct
{
    MI_S8 strIspRoot[ROOT_PATH_STRING_SIZE];
} MI_ISP_ROOT_PATH_T;

typedef struct MI_ISP_API_DEVICE_ID_TYPE_s
{
    MI_U32 u32DeviceID;
} MI_ISP_API_DEVICE_ID_TYPE_t;

#ifdef __cplusplus
}   //end of extern C
#endif

#endif  //_MI_ISPIQ_DATATYPE_H_
