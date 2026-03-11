/*
 * Part of the OpenIPC project — https://openipc.org
 * Targets: IP cameras and embedded Linux (POSIX, uClibc/musl/glibc)
 * Contact: tech@openipc.eu
 * License: MIT
 */

#include "star.h"

static sdk_header sdk;

static int mi_snr_init(void) {
	if (MI_SNR_SetPlaneMode(MI_SENSOR_PAD, false)) {
		return 1;
	}

	MI_SNR_Res_t res = {0};
	if (MI_SNR_GetRes(MI_SENSOR_PAD, sdk.index, &res)) {
		return 1;
	}

	sdk.fps = res.u32MaxFps;
	if (MI_SNR_SetRes(MI_SENSOR_PAD, sdk.index)) {
		return 1;
	}

	if (MI_SNR_Enable(MI_SENSOR_PAD)) {
		return 1;
	}

	return 0;
}

static int mi_snr_deinit(void) {
	return MI_SNR_Disable(MI_SENSOR_PAD);
}

#ifdef SIGMASTAR_MARUKO
static int mi_vif_init(void) {
	MI_VIF_GroupAttr_t attr = {0};
	attr.eHDRType = E_MI_VIF_HDR_TYPE_OFF;
	attr.eClkEdge = E_MI_VIF_CLK_EDGE_DOUBLE;
	attr.eIntfMode = E_MI_VIF_MODE_MIPI;
	attr.eWorkMode = E_MI_VIF_WORK_MODE_1MULTIPLEX;
	attr.u32GroupStitchMask = E_MI_VIF_GROUPMASK_ID1;

	if (MI_VIF_CreateDevGroup(0, &attr)) {
		return 1;
	}

	MI_SNR_PlaneInfo_t plane = {0};
	if (MI_SNR_GetPlaneInfo(MI_SENSOR_PAD, 0, &plane)) {
		return 1;
	}

	sdk.format = (MI_SYS_PixelFormat_e)RGB_BAYER_PIXEL(
		plane.ePixPrecision, plane.eBayerId);

	MI_VIF_DevAttr_t dev = {0};
	dev.stInputRect.u16X = plane.stCapRect.u16X;
	dev.stInputRect.u16Y = plane.stCapRect.u16Y;
	dev.stInputRect.u16Width = plane.stCapRect.u16Width;
	dev.stInputRect.u16Height = plane.stCapRect.u16Height;
	dev.eInputPixel = sdk.format;

	if (MI_VIF_SetDevAttr(0, &dev)) {
		return 1;
	}

	if (MI_VIF_EnableDev(0)) {
		return 1;
	}

	MI_VIF_OutputPortAttr_t port = {0};
	port.stCapRect.u16Width = plane.stCapRect.u16Width;
	port.stCapRect.u16Height = plane.stCapRect.u16Height;
	port.stDestSize.u16Width = plane.stCapRect.u16Width;
	port.stDestSize.u16Height = plane.stCapRect.u16Height;
	port.ePixFormat = sdk.format;

	sdk.width = plane.stCapRect.u16Width;
	sdk.height = plane.stCapRect.u16Height;

	if (MI_VIF_SetOutputPortAttr(0, 0, &port)) {
		return 1;
	}

	if (MI_VIF_EnableOutputPort(0, 0)) {
		return 1;
	}

	return 0;
}

#else
static int mi_vif_init(void) {
	MI_SNR_PADInfo_t info = {0};
	if (MI_SNR_GetPadInfo(MI_SENSOR_PAD, &info)) {
		return 1;
	}

	MI_VIF_DevAttr_t dev = {0};
	dev.eIntfMode = info.eIntfMode;
	dev.eHDRType = E_MI_VIF_HDR_TYPE_OFF;
	dev.eClkEdge = E_MI_VIF_CLK_EDGE_DOUBLE;
	dev.eBitOrder = E_MI_VIF_BITORDER_NORMAL;
	dev.eWorkMode = E_MI_VIF_WORK_MODE_RGB_REALTIME;

	if (dev.eIntfMode == E_MI_VIF_MODE_MIPI) {
		dev.eDataSeq = info.unIntfAttr.stMipiAttr.eDataYUVOrder;
	} else {
		dev.eDataSeq = E_MI_VIF_INPUT_DATA_YUYV;
	}

	if (MI_VIF_SetDevAttr(0, &dev)) {
		return 1;
	}

	if (MI_VIF_EnableDev(0)) {
		return 1;
	}

	MI_SNR_PlaneInfo_t plane = {0};
	if (MI_SNR_GetPlaneInfo(MI_SENSOR_PAD, 0, &plane)) {
		return 1;
	}

	sdk.format = (MI_SYS_PixelFormat_e)RGB_BAYER_PIXEL(
		plane.ePixPrecision, plane.eBayerId);

	MI_VIF_ChnPortAttr_t port = {0};
	port.stCapRect.u16Width = plane.stCapRect.u16Width;
	port.stCapRect.u16Height = plane.stCapRect.u16Height;
	port.stDestSize.u16Width = plane.stCapRect.u16Width;
	port.stDestSize.u16Height = plane.stCapRect.u16Height;
	port.ePixFormat = sdk.format;

	sdk.width = plane.stCapRect.u16Width;
	sdk.height = plane.stCapRect.u16Height;

	if (MI_VIF_SetChnPortAttr(0, 0, &port)) {
		return 1;
	}

	if (MI_VIF_EnableChnPort(0, 0)) {
		return 1;
	}

	return 0;
}
#endif

static int mi_vif_deinit(void) {
	if (MI_VIF_DisableChnPort(0, 0)) {
		return 1;
	}

	if (MI_VIF_DisableDev(0)) {
		return 1;
	}

#ifdef SIGMASTAR_MARUKO
	if (MI_VIF_DestroyDevGroup(0)) {
		return 1;
	}
#endif

	return 0;
}

#ifdef SIGMASTAR_MARUKO
static int mi_isp_init(void) {
	MI_ISP_DevAttr_t dev = {0};
	dev.u32DevStitchMask = E_MI_ISP_DEVICEMASK_ID0;

	if (MI_ISP_CreateDevice(0, &dev)) {
		return 1;
	}

	MI_ISP_ChannelAttr_t attr = {0};
	attr.u32SensorBindId = E_MI_ISP_SENSOR0;

	if (MI_ISP_CreateChannel(0, 0, &attr)) {
		return 1;
	}

	MI_ISP_ChnParam_t param = {0};
	param.eHDRType = E_MI_ISP_HDR_TYPE_OFF;
	param.eRot = E_MI_SYS_ROTATE_NONE;

	if (MI_ISP_SetChnParam(0, 0, &param)) {
		return 1;
	}

	if (MI_ISP_StartChannel(0, 0)) {
		return 1;
	}

	MI_SYS_ChnPort_t input = {0};
	input.eModId = E_MI_MODULE_ID_VIF;

	MI_SYS_ChnPort_t output = {0};
	output.eModId = E_MI_MODULE_ID_ISP;

	if (MI_SYS_BindChnPort2(0, &input, &output, sdk.fps,
			sdk.fps, E_MI_SYS_BIND_TYPE_REALTIME, 0)) {
		return 1;
	}

	MI_ISP_OutPortParam_t port = {0};
	port.ePixelFormat = MI_PIXEL_FORMAT;

	if (MI_ISP_SetOutputPortParam(0, 0, 0, &port)) {
		return 1;
	}

	if (MI_ISP_EnableOutputPort(0, 0, 0)) {
		return 1;
	}

	return 0;
}

static int mi_isp_deinit(void) {
	MI_SYS_ChnPort_t input = {0};
	input.eModId = E_MI_MODULE_ID_VIF;

	MI_SYS_ChnPort_t output = {0};
	output.eModId = E_MI_MODULE_ID_ISP;

	if (MI_SYS_UnBindChnPort(0, &input, &output)) {
		return 1;
	}

	if (MI_ISP_DisableOutputPort(0, 0, 0)) {
		return 1;
	}

	if (MI_ISP_StopChannel(0, 0)) {
		return 1;
	}

	if (MI_ISP_DestroyChannel(0, 0)) {
		return 1;
	}

	if (MI_ISP_DestoryDevice(0)) {
		return 1;
	}

	return 0;
}

static int mi_vpe_init(void) {
	MI_SYS_GlobalPrivPoolConfig_t pool = {0};
	pool.bCreate = true;
	pool.eConfigType = E_MI_SYS_PER_DEV_PRIVATE_RING_POOL;
	pool.uConfig.stpreDevPrivRingPoolConfig.eModule = E_MI_MODULE_ID_SCL;
	pool.uConfig.stpreDevPrivRingPoolConfig.u16MaxWidth = sdk.width;
	pool.uConfig.stpreDevPrivRingPoolConfig.u16MaxHeight = sdk.height;
	pool.uConfig.stpreDevPrivRingPoolConfig.u16RingLine = sdk.height / 4;

	if (MI_SYS_ConfigPrivateMMAPool(0, &pool)) {
		return 1;
	}

	MI_SCL_DevAttr_t dev = {0};
	dev.u32NeedUseHWOutPortMask = E_MI_SCL_HWSCL0 | E_MI_SCL_HWSCL1;

	if (MI_SCL_CreateDevice(0, &dev)) {
		return 1;
	}

	MI_SCL_ChannelAttr_t attr = {0};
	if (MI_SCL_CreateChannel(0, 0, &attr)) {
		return 1;
	}

	MI_SCL_ChnParam_t param = {0};
	param.eRot = E_MI_SYS_ROTATE_NONE;

	if (MI_SCL_SetChnParam(0, 0, &param)) {
		return 1;
	}

	if (MI_SCL_StartChannel(0, 0)) {
		return 1;
	}

	MI_SYS_ChnPort_t input = {0};
	input.eModId = E_MI_MODULE_ID_ISP;

	MI_SYS_ChnPort_t output = {0};
	output.eModId = E_MI_MODULE_ID_SCL;

	if (MI_SYS_BindChnPort2(MDEV &input, &output, sdk.fps,
			sdk.fps, E_MI_SYS_BIND_TYPE_REALTIME, 0)) {
		return 1;
	}

	MI_SCL_OutPortParam_t port = {0};
	port.stSCLOutputSize.u16Width = sdk.width;
	port.stSCLOutputSize.u16Height = sdk.height;
	port.ePixelFormat = MI_PIXEL_FORMAT;
	port.eCompressMode = E_MI_SYS_COMPRESS_MODE_IFC;

	if (MI_SCL_SetOutputPortParam(0, 0, 0, &port)) {
		return 1;
	}

	if (MI_SCL_EnableOutputPort(0, 0, 0)) {
		return 1;
	}

	return 0;
}

static int mi_vpe_deinit(void) {
	MI_SYS_ChnPort_t input = {0};
	input.eModId = E_MI_MODULE_ID_ISP;

	MI_SYS_ChnPort_t output = {0};
	output.eModId = E_MI_MODULE_ID_SCL;

	if (MI_SYS_UnBindChnPort(MDEV &input, &output)) {
		return 1;
	}

	if (MI_SCL_DisableOutputPort(0, 0, 0)) {
		return 1;
	}

	if (MI_SCL_StopChannel(0, 0)) {
		return 1;
	}

	if (MI_SCL_DestroyChannel(0, 0)) {
		return 1;
	}

	if (MI_SCL_DestroyDevice(0)) {
		return 1;
	}

	return 0;
}

#else
static int mi_vpe_init(void) {
	MI_VPE_ChannelAttr_t attr = {0};
	attr.eSensorBindId = E_MI_VPE_SENSOR0;
	attr.eRunningMode = E_MI_VPE_RUN_REALTIME_MODE;
	attr.eHDRType = E_MI_VPE_HDR_TYPE_OFF;
	attr.ePixFmt = sdk.format;
	attr.u16MaxW = sdk.width;
	attr.u16MaxH = sdk.height;

	if (MI_VPE_CreateChannel(0, &attr)) {
		return 1;
	}

	if (MI_VPE_StartChannel(0)) {
		return 1;
	}

	MI_SYS_ChnPort_t input = {0};
	input.eModId = E_MI_MODULE_ID_VIF;

	MI_SYS_ChnPort_t output = {0};
	output.eModId = E_MI_MODULE_ID_VPE;

	if (MI_SYS_BindChnPort2(MDEV &input, &output, sdk.fps,
			sdk.fps, E_MI_SYS_BIND_TYPE_REALTIME, 0)) {
		return 1;
	}

	MI_VPE_PortMode_t port = {0};
	port.ePixelFormat = MI_PIXEL_FORMAT;
	port.u16Width = sdk.width;
	port.u16Height = sdk.height;

	if (MI_VPE_SetPortMode(0, 0, &port)) {
		return 1;
	}

	if (MI_VPE_EnablePort(0, 0)) {
		return 1;
	}

	return 0;
}

static int mi_vpe_deinit(void) {
	if (MI_VPE_DisablePort(0, 0)) {
		return 1;
	}

	MI_SYS_ChnPort_t input = {0};
	input.eModId = E_MI_MODULE_ID_VIF;

	MI_SYS_ChnPort_t output = {0};
	output.eModId = E_MI_MODULE_ID_VPE;

	if (MI_SYS_UnBindChnPort(MDEV &input, &output)) {
		return 1;
	}

	if (MI_VPE_StopChannel(0)) {
		return 1;
	}

	if (MI_VPE_DestroyChannel(0)) {
		return 1;
	}

	return 0;
}
#endif

static int mi_venc_config(void) {
	char file[PATH_MAX];
	char *path = "/etc/sensors/%s.bin";

	const char *sensor = getenv("SENSOR");
	snprintf(file, sizeof(file), path, sensor);

	if (!access(file, 0)) {
		printf("--- Load api file: %s\n", file);
		if (MI_ISP_API_CmdLoadBinFile(MDEV 0, file, 1234)) {
			return 1;
		}
	}

	MI_ISP_AE_EXPO_LIMIT_TYPE_t exposure;
	if (MI_ISP_AE_GetExposureLimit(MDEV 0, &exposure)) {
		return 1;
	}

	exposure.u32MaxShutterUS = 1000 / sdk.fps * 1000;
	if (MI_ISP_AE_SetExposureLimit(MDEV 0, &exposure)) {
		return 1;
	}

	return 0;
}

static int mi_venc_init_hevc(void) {
	MI_VENC_ChnAttr_t attr = {0};
	attr.stVeAttr.eType = E_MI_VENC_MODTYPE_H265E;
	attr.stVeAttr.stAttrH265e.bByFrame = !sdk.slice;
	attr.stVeAttr.stAttrH265e.u32PicWidth = sdk.width;
	attr.stVeAttr.stAttrH265e.u32PicHeight = sdk.height;
	attr.stVeAttr.stAttrH265e.u32MaxPicWidth = sdk.width;
	attr.stVeAttr.stAttrH265e.u32MaxPicHeight = sdk.height;

	attr.stRcAttr.eRcMode = E_MI_VENC_RC_MODE_H265AVBR;
	attr.stRcAttr.stAttrH265Avbr.u32Gop = sdk.fps;
	attr.stRcAttr.stAttrH265Avbr.u32MaxBitRate = sdk.bitrate * 1024;
	attr.stRcAttr.stAttrH265Avbr.u32SrcFrmRateNum = sdk.fps;
	attr.stRcAttr.stAttrH265Avbr.u32SrcFrmRateDen = 1;
	attr.stRcAttr.stAttrH265Avbr.u32MaxQp = 42;
	attr.stRcAttr.stAttrH265Avbr.u32MinQp = 12;

	if (MI_VENC_CreateChn(MDEV 0, &attr)) {
		return 1;
	}

	MI_VENC_RcParam_t param;
	if (MI_VENC_GetRcParam(MDEV 0, &param)) {
		return 1;
	}

	param.stParamH265Avbr.s32IPQPDelta = -4;
	if (MI_VENC_SetRcParam(MDEV 0, &param)) {
		return 1;
	}

	return 0;
}

static int mi_venc_init(void) {
	if (mi_venc_init_hevc()) {
		return 1;
	}

#ifdef SIGMASTAR_MARUKO
	MI_SYS_GlobalPrivPoolConfig_t pool = {0};
	pool.bCreate = true;
	pool.eConfigType = E_MI_SYS_PER_DEV_PRIVATE_RING_POOL;
	pool.uConfig.stpreDevPrivRingPoolConfig.eModule = E_MI_MODULE_ID_VENC;
	pool.uConfig.stpreDevPrivRingPoolConfig.u16MaxWidth = sdk.width;
	pool.uConfig.stpreDevPrivRingPoolConfig.u16MaxHeight = sdk.height;
	pool.uConfig.stpreDevPrivRingPoolConfig.u16RingLine = sdk.height;

	if (MI_SYS_ConfigPrivateMMAPool(0, &pool)) {
		return 1;
	}

	MI_VENC_InputSourceConfig_t config = {0};
	config.eInputSrcBufferMode = E_MI_VENC_INPUT_MODE_RING_UNIFIED_DMA;

	if (MI_VENC_SetInputSourceConfig(0, 0, &config)) {
		return 1;
	}
#endif

	if (sdk.slice) {
		MI_VENC_ParamH265SliceSplit_t split;
		split.bSplitEnable = true;
		split.u32SliceRowCount = sdk.slice;

		if (MI_VENC_SetH265SliceSplit(MDEV 0, &split)) {
			return 1;
		}
	}

	if (MI_VENC_StartRecvPic(MDEV 0)) {
		return 1;
	}

	MI_SYS_ChnPort_t input = {0};
	input.eModId = VENC_MODULE_PORT;

	MI_SYS_ChnPort_t output = {0};
	output.eModId = E_MI_MODULE_ID_VENC;

	if (MI_SYS_BindChnPort2(MDEV &input, &output,
			sdk.fps, sdk.fps, VENC_MODULE_BIND, 0)) {
		return 1;
	}

	return 0;
}

static int mi_venc_deinit(void) {
	MI_SYS_ChnPort_t input = {0};
	input.eModId = VENC_MODULE_PORT;

	MI_SYS_ChnPort_t output = {0};
	output.eModId = E_MI_MODULE_ID_VENC;

	if (MI_SYS_UnBindChnPort(MDEV &input, &output)) {
		return 1;
	}

	if (MI_VENC_StopRecvPic(MDEV 0)) {
		return 1;
	}

	return MI_VENC_DestroyChn(MDEV 0);
}

static void create_stream(int port, uint8_t *data, uint32_t size) {
	rtp_header rtp;
	rtp.version = 0x80;
	rtp.sequence = htobe16(sdk.sequence++);
	rtp.payload_type = 0x60;
	rtp.timestamp = 0;
	rtp.ssrc_id = 0xDEADBEEF;

	struct iovec iov[2] = {0};
	iov[0].iov_base = &rtp;
	iov[0].iov_len = sizeof(rtp);
	iov[1].iov_base = data;
	iov[1].iov_len = size;

	struct msghdr msg = {0};
	msg.msg_iovlen = 2;
	msg.msg_iov = iov;
	msg.msg_name = &sdk.address;
	msg.msg_namelen = sizeof(struct sockaddr_in);

	if (sendmsg(port, &msg, 0) < 0) {
		printf("--- Cannot send packet: %s [%dKB]\n",
			strerror(errno), size / 1024);
	}
}

static void create_fragment(int port, char *data, int size) {
	char nal_prefix = 4;
	data += nal_prefix;
	size -= nal_prefix;

	if (size > sdk.mtu_size) {
		char nal_type_avc = data[0] & 0x1F;
		char nal_type_hevc = (data[0] >> 1) & 0x3F;
		char nal_bits_avc = data[0] & 0xE0;
		char nal_bits_hevc = data[0] & 0x81;

		char tx_buffer[4096];
		char nal_bits = 2;
		bool start_bit = true;

		while (size) {
			int chunk = size > sdk.mtu_size ? sdk.mtu_size : size;
			if (nal_type_avc == 1 || nal_type_avc == 5) {
				tx_buffer[0] = nal_bits_avc | 28;
				tx_buffer[1] = nal_type_avc;

				if (start_bit) {
					data++;
					size--;

					tx_buffer[1] = 0x80 | nal_type_avc;
					start_bit = false;
				}

				if (chunk == size) {
					tx_buffer[1] |= 0x40;
				}
			}

			if (nal_type_hevc == 1 || nal_type_hevc == 19) {
				tx_buffer[0] = nal_bits_hevc | 49 << 1;
				tx_buffer[1] = 1;
				tx_buffer[2] = nal_type_hevc;
				nal_bits = 3;

				if (start_bit) {
					data += 2;
					size -= 2;

					tx_buffer[2] = 0x80 | nal_type_hevc;
					start_bit = false;
				}

				if (chunk == size) {
					tx_buffer[2] |= 0x40;
				}
			}

			memcpy(tx_buffer + nal_bits, data, chunk + nal_bits);
			create_stream(port, tx_buffer, chunk + nal_bits);

			data += chunk;
			size -= chunk;
		}
	} else {
		create_stream(port, data, size);
	}
}

static int read_frame(int port) {
	struct pollfd desc;
	desc.fd = MI_VENC_GetFd(MDEV 0);
	desc.events = POLLIN;
	if (poll(&desc, 1, 1000) < 0) {
		printf("--- No frame received\n");
		return 1;
	}

	MI_VENC_ChnStat_t stat = {0};
	if (MI_VENC_Query(MDEV 0, &stat)) {
		printf("--- Cannot query stream\n");
		return 1;
	}

	if (stat.u32CurPacks == 0) {
		printf("--- Current frame is empty\n");
		return 0;
	}

	MI_VENC_Stream_t stream = {0};
	stream.u32PackCount = stat.u32CurPacks;
	stream.pstPack = alloca(sizeof(MI_VENC_Pack_t) * stat.u32CurPacks);

	if (MI_VENC_GetStream(MDEV 0, &stream, 0)) {
		printf("--- Cannot get stream\n");
		return 1;
	}

	MI_VENC_Pack_t *packet = {0};
	for (int i = 0; i < stream.u32PackCount; i++) {
		MI_VENC_Pack_t packet = stream.pstPack[i];
		if (packet.u32DataNum) {
			for (int i = 0; i < packet.u32DataNum; i++) {
				char *ptr = packet.pu8Addr + packet.asackInfo[i].u32PackOffset;
				int len = packet.asackInfo[i].u32PackLength;
				create_fragment(port, ptr, len);
			}
		} else {
			char *ptr = packet.pu8Addr;
			int len = packet.u32Len;
			create_fragment(port, ptr, len);
		}
	}

	if (MI_VENC_ReleaseStream(MDEV 0, &stream)) {
		printf("--- Cannot release stream\n");
		return 1;
	}

	return 0;
}

static void handler(int value) {
	sdk.running = false;
}

int main(int argc, char **argv) {
	sdk.bitrate = 4 * 1024;
	sdk.mtu_size = MTU_SIZE;

	if (argc > 1) {
		sdk.bitrate = atoi(argv[1]) * 1024;
	}

	char dst_addr[64];
	if (argc > 2) {
		strcpy(dst_addr, argv[2]);
	} else {
		strcpy(dst_addr, "192.168.1.10");
	}

	int dst_port = 5600;
	if (argc > 3) {
		dst_port = atoi(argv[3]);
	}

	if (MI_SYS_Init(SDEV)) {
		printf("--- Cannot initialize sys\n");
		return 0;
	}

	if (mi_snr_init()) {
		printf("--- Cannot initialize snr\n");
		return 1;
	}

	if (mi_vif_init()) {
		printf("--- Cannot initialize vif\n");
		return 1;
	}

#ifdef SIGMASTAR_MARUKO
	if (mi_isp_init()) {
		printf("--- Cannot initialize isp\n");
		return 1;
	}
#endif

	if (mi_vpe_init()) {
		printf("--- Cannot initialize vpe\n");
		return 1;
	}

	if (mi_venc_init()) {
		printf("--- Cannot initialize venc\n");
		return 1;
	}

	sleep(1);

	if (mi_venc_config()) {
		printf("--- Cannot set configuration\n");
		return 1;
	}

	signal(SIGINT, handler);

	sdk.address.sin_family = AF_INET;
	sdk.address.sin_port = htons(dst_port);
	sdk.address.sin_addr.s_addr = inet_addr(dst_addr);
	int port = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	printf("--- Index: %d, Bitrate: %d, Slice: %d | Stream: %dx%d@%dfps | Address: %s:%d\n",
		sdk.index, sdk.bitrate, sdk.slice, sdk.width, sdk.height, sdk.fps, dst_addr, dst_port);

	sdk.running = true;
	while (sdk.running) {
		if (read_frame(port)) {
			break;
		}
	}

	printf("--- Cancel program\n");

	if (mi_venc_deinit()) {
		printf("--- Cannot deinitialize venc\n");
		return 1;
	}

	if (mi_vpe_deinit()) {
		printf("--- Cannot deinitialize vpe\n");
		return 1;
	}

#ifdef SIGMASTAR_MARUKO
	if (mi_isp_deinit()) {
		printf("--- Cannot deinitialize isp\n");
		return 1;
	}
#endif

	if (mi_vif_deinit()) {
		printf("--- Cannot deinitialize vif\n");
		return 1;
	}

	if (mi_snr_deinit()) {
		printf("--- Cannot deinitialize snr\n");
		return 1;
	}

	if (MI_SYS_Exit(SDEV)) {
		printf("--- Cannot deinitialize sys\n");
		return 1;
	}

	return 0;
}
