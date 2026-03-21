/*
 *
 * Copyright (c) OpenIPC  https://openipc.org  MIT License
 *
 * star.h — types and definitions for the star RTP streamer
 *
 */

#include <errno.h>
#include <endian.h>
#include <fcntl.h>
#include <poll.h>
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <linux/limits.h>
#include <sys/syscall.h>

#include <mi_isp.h>
#include <mi_sensor.h>
#include <mi_sys.h>
#include <mi_venc.h>
#include <mi_vif.h>
#include "compat.h"

#define MI_SENSOR_PAD 0
#define MI_PIXEL_FORMAT E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420
#define MTU_SIZE 1400

typedef struct {
	uint8_t version;
	uint8_t payload_type;
	uint16_t sequence;
	uint32_t timestamp;
	uint32_t ssrc_id;
} rtp_header;

typedef struct {
	struct sockaddr_in address;
	bool running;
	int mtu_size;
	int sequence;

	MI_SYS_PixelFormat_e format;
	int index;
	int width;
	int height;
	int fps;
	int bitrate;
	int slice;
} sdk_header;
