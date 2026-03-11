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
#ifndef _MI_SENSOR_DATATYPE_H_
#define _MI_SENSOR_DATATYPE_H_

#include "mi_sys_datatype.h"
#pragma pack(push)
#pragma pack(4)

#define MI_ERR_SNR_INVALID_DEVID    MI_DEF_ERR(E_MI_MODULE_ID_SNR, E_MI_ERR_LEVEL_ERROR, E_MI_ERR_INVALID_DEVID)
#define MI_ERR_SNR_INVALID_CHNID    MI_DEF_ERR(E_MI_MODULE_ID_SNR, E_MI_ERR_LEVEL_ERROR, E_MI_ERR_INVALID_CHNID)
#define MI_ERR_SNR_INVALID_PARA     MI_DEF_ERR(E_MI_MODULE_ID_SNR, E_MI_ERR_LEVEL_ERROR, E_MI_ERR_ILLEGAL_PARAM)
#define MI_ERR_SNR_INVALID_NULL_PTR MI_DEF_ERR(E_MI_MODULE_ID_SNR, E_MI_ERR_LEVEL_ERROR, E_MI_ERR_NULL_PTR)
#define MI_ERR_SNR_FAILED_NOTCONFIG MI_DEF_ERR(E_MI_MODULE_ID_SNR, E_MI_ERR_LEVEL_ERROR, E_MI_ERR_NOT_CONFIG)
#define MI_ERR_SNR_NOT_SUPPORT      MI_DEF_ERR(E_MI_MODULE_ID_SNR, E_MI_ERR_LEVEL_ERROR, E_MI_ERR_NOT_SUPPORT)
#define MI_ERR_SNR_NOT_PERM         MI_DEF_ERR(E_MI_MODULE_ID_SNR, E_MI_ERR_LEVEL_ERROR, E_MI_ERR_NOT_PERM)
#define MI_ERR_SNR_NOMEM            MI_DEF_ERR(E_MI_MODULE_ID_SNR, E_MI_ERR_LEVEL_ERROR, E_MI_ERR_NOMEM)
#define MI_ERR_SNR_BUF_EMPTY        MI_DEF_ERR(E_MI_MODULE_ID_SNR, E_MI_ERR_LEVEL_ERROR, E_MI_ERR_BUF_EMPTY)
#define MI_ERR_SNR_BUF_FULL         MI_DEF_ERR(E_MI_MODULE_ID_SNR, E_MI_ERR_LEVEL_ERROR, E_MI_ERR_BUF_FULL)
#define MI_ERR_SNR_SYS_NOTREADY     MI_DEF_ERR(E_MI_MODULE_ID_SNR, E_MI_ERR_LEVEL_ERROR, E_MI_ERR_SYS_NOTREADY)
#define MI_ERR_SNR_BUSY             MI_DEF_ERR(E_MI_MODULE_ID_SNR, E_MI_ERR_LEVEL_ERROR, E_MI_ERR_BUSY)
#define MI_ERR_SNR_FAIL             MI_DEF_ERR(E_MI_MODULE_ID_SNR, E_MI_ERR_LEVEL_ERROR, E_MI_ERR_FAILED)

typedef MI_U32 MI_SNR_PADID;

typedef struct MI_SNR_Res_s
{
    MI_SYS_WindowRect_t stCropRect;
    MI_SYS_WindowSize_t stOutputSize; /**< Sensor actual output size */

    MI_U32 u32MaxFps;      /**< Max fps in this resolution */
    MI_U32 u32MinFps;      /**< Min fps in this resolution*/
    MI_S8  strResDesc[32]; // Need to put “HDR” here if the resolution is for HDR //NOLINT
} __attribute__((packed, aligned(4))) MI_SNR_Res_t;

typedef enum
{
    E_MI_SNR_HDR_HW_MODE_NONE           = 0,
    E_MI_SNR_HDR_HW_MODE_SONY_DOL       = 1,
    E_MI_SNR_HDR_HW_MODE_DCG            = 2,
    E_MI_SNR_HDR_HW_MODE_EMBEDDED_RAW8  = 3,
    E_MI_SNR_HDR_HW_MODE_EMBEDDED_RAW10 = 4,
    E_MI_SNR_HDR_HW_MODE_EMBEDDED_RAW12 = 5,
    E_MI_SNR_HDR_HW_MODE_EMBEDDED_RAW14 = 6,
    E_MI_SNR_HDR_HW_MODE_EMBEDDED_RAW16 = 7,
} MI_SNR_HDRHWMode_e;

typedef enum
{
    E_MI_SNR_HDR_SOURCE_VC0,
    E_MI_SNR_HDR_SOURCE_VC1,
    E_MI_SNR_HDR_SOURCE_VC2,
    E_MI_SNR_HDR_SOURCE_VC3,
    E_MI_SNR_HDR_SOURCE_MAX
} MI_SNR_HDRSrc_e;

typedef enum
{
    E_MI_SNR_CUSTDATA_TO_DRIVER,
    E_MI_SNR_CUSTDATA_TO_USER,
    E_MI_SNR_CUSTDATA_MAX = E_MI_SNR_CUSTDATA_TO_USER,
} MI_SNR_CUST_DIR_e;

typedef enum
{
    E_MI_SNR_PIN_POLAR_POS,
    E_MI_SNR_PIN_POLAR_NEG
} MI_SNR_Polar_e;

typedef struct MI_SNR_SyncAttr_s
{
    MI_SNR_Polar_e eVsyncPolarity;
    MI_SNR_Polar_e eHsyncPolarity;
    MI_SNR_Polar_e ePclkPolarity;
    MI_U32         VsyncDelay;
    MI_U32         HsyncDelay;
    MI_U32         PclkDelay;
} MI_SNR_SyncAttr_t;

typedef struct MI_SNR_AttrParallel_s
{
    MI_SNR_SyncAttr_t stSyncAttr;
} MI_SNR_AttrParallel_t;
// Should be the same structure definition with the one used in SNR

typedef struct MI_SNR_MipiAttr_s
{
    MI_U32 u32LaneNum;
    MI_U32 u32DataFormat; // 0: YUV 422 format. 1: RGB pattern.
    MI_U32 u32HsyncMode;
    MI_U32 u32Sampling_delay;
    /** < MIPI start sampling delay */ /*bit 0~7: clk_skip_ns. bit 8~15: data_skip_ns*/
    MI_SNR_HDRHWMode_e eHdrHWmode;
    MI_U32             u32Hdr_Virchn_num;      //??
    MI_U32             u32Long_packet_type[2]; //??
} MI_SNR_MipiAttr_t;

typedef enum
{
    E_MI_SNR_BITORDER_NORMAL = 0,
    E_MI_SNR_BITORDER_REVERSED
} MI_SNR_BitOrder_e;

typedef enum
{
    E_MI_SNR_CLK_EDGE_SINGLE_UP,
    E_MI_SNR_CLK_EDGE_SINGLE_DOWN,
    E_MI_SNR_CLK_EDGE_DOUBLE,
    E_MI_SNR_CLK_EDGE_MAX
} MI_SNR_ClkEdge_e;

typedef struct MI_SNR_AttrBt656_s
{
    MI_U32            u32Multiplex_num;
    MI_SNR_SyncAttr_t stSyncAttr;
    MI_SNR_ClkEdge_e  eClkEdge;
    MI_SNR_BitOrder_e eBitSwap;
} MI_SNR_AttrBt656_t;

typedef union
{
    MI_SNR_AttrParallel_t stParallelAttr;
    MI_SNR_MipiAttr_t     stMipiAttr;
    MI_SNR_AttrBt656_t    stBt656Attr;
} MI_SNR_IntfAttr_u;

typedef enum
{
    E_MI_SNR_MODE_BT656,
    E_MI_SNR_MODE_DIGITAL_CAMERA,
    E_MI_SNR_MODE_BT1120_STANDARD,
    E_MI_SNR_MODE_BT1120_INTERLEAVED,
    E_MI_SNR_MODE_MIPI,
    E_MI_SNR_MODE_LVDS,
    E_MI_SNR_MODE_MAX
} MI_SNR_IntfMode_e;

typedef enum
{
    E_MI_SNR_HDR_TYPE_OFF,
    E_MI_SNR_HDR_TYPE_VC, // virtual channel mode HDR,vc0->long, vc1->short
    E_MI_SNR_HDR_TYPE_DOL,
    E_MI_SNR_HDR_TYPE_EMBEDDED, // compressed HDR mode
    E_MI_SNR_HDR_TYPE_LI,       // Line interlace HDR
    E_MI_SNR_HDR_TYPE_MAX
} MI_SNR_HDRType_e;

typedef struct MI_SNR_PADInfo_s
{
    MI_U32            u32PlaneCount; // It is different expo number for HDR. It is mux number for BT656. //??
    MI_SNR_IntfMode_e eIntfMode;
    MI_SNR_HDRType_e  eHDRMode;
    MI_SNR_IntfAttr_u unIntfAttr;
    MI_BOOL           bEarlyInit;
} MI_SNR_PADInfo_t;

typedef struct MI_SNR_PlaneInfo_s
{
    MI_U32                 u32PlaneID;       // For HDR long/short exposure or BT656 channel 0~3
    MI_S8                  s8SensorName[32]; // NOLINT
    MI_SYS_WindowRect_t    stCapRect;
    MI_SYS_BayerId_e       eBayerId;
    MI_SYS_DataPrecision_e ePixPrecision;
    MI_SNR_HDRSrc_e        eHdrSrc;
    MI_U32                 u32ShutterUs;
    MI_U32                 u32SensorGainX1024;
    MI_U32                 u32CompGain;
    MI_SYS_PixelFormat_e   ePixel;
} MI_SNR_PlaneInfo_t;

typedef enum
{
    E_MI_SNR_ANADEC_STATUS_NO_READY = 0,
    E_MI_SNR_ANADEC_STATUS_DISCNT,
    E_MI_SNR_ANADEC_STATUS_CONNECT,
    E_MI_SNR_ANADEC_STATUS_NUM
} MI_SNR_Anadec_Status_e;

typedef enum
{
    E_MI_SNR_ANADEC_TRANSFERMODE_CVBS = 0,
    E_MI_SNR_ANADEC_TRANSFERMODE_CVI,
    E_MI_SNR_ANADEC_TRANSFERMODE_TVI,
    E_MI_SNR_ANADEC_TRANSFERMODE_AHD,
    E_MI_SNR_ANADEC_TRANSFERMODE_NUM,
} MI_SNR_Anadec_TransferMode_e;

typedef enum
{
    E_MI_SNR_ANADEC_FORMAT_NTSC = 0,
    E_MI_SNR_ANADEC_FORMAT_PAL,
    E_MI_SNR_ANADEC_FORMAT_NUM,
} MI_SNR_Anadec_Format_e;

typedef struct MI_SNR_Anadec_SrcAttr_s
{
    MI_SNR_Anadec_Status_e       eStatus;
    MI_SNR_Anadec_TransferMode_e eTransferMode;
    MI_SNR_Anadec_Format_e       eFormat;
    MI_SYS_WindowSize_t          stRes;
    MI_U32                       u32Fps;
} MI_SNR_Anadec_SrcAttr_t;

typedef struct MI_SNR_InitParam_s
{
    MI_U32 u32DevId;
    MI_U8 *u8Data;
} MI_SNR_InitParam_t;

#pragma pack(pop)

#endif
