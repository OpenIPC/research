/*
 * Part of the OpenIPC project — https://openipc.org
 * Targets: IP cameras and embedded Linux (POSIX, uClibc/musl/glibc)
 * Contact: tech@openipc.eu
 * License: MIT
 */

#ifdef SIGMASTAR_MARUKO
#include <mi_isp_ae.h>
#include <mi_isp_cus3a_api.h>
#include <mi_scl.h>

#define MDEV 0,
#define SDEV 0

#define MI_VIF_DisableChnPort MI_VIF_DisableOutputPort
#define MI_ISP_API_CmdLoadBinFile MI_ISP_ApiCmdLoadBinFile
#define MI_ISP_AE_EXPO_LIMIT_TYPE_t MI_ISP_AE_ExpoLimitType_t

#define VENC_MODULE_BIND E_MI_SYS_BIND_TYPE_HW_RING
#define VENC_MODULE_PORT E_MI_MODULE_ID_SCL
#else
#include <mi_vpe.h>

#define MDEV
#define SDEV

#define VENC_MODULE_BIND E_MI_SYS_BIND_TYPE_FRAME_BASE
#define VENC_MODULE_PORT E_MI_MODULE_ID_VPE
#endif

void __assert(void) {}
void __ctype_b(void) {}
void __stdin(void) {}

int __fgetc_unlocked(FILE *stream) {
	return fgetc(stream);
}

#ifdef SIGMASTAR_PUDDING
float __expf_finite(float a) {
	return expf(a);
}

double __log_finite(double a) {
	return log(a);
}
#endif

#ifdef SIGMASTAR_MARUKO
void backtrace(void) {}
void backtrace_symbols(void) {}
#endif

#ifdef SIGMASTAR_ISPAHAN
void *mmap(void *start, size_t len, int prot, int flags, int fd, uint32_t off) {
	return (void *)syscall(SYS_mmap2, start, len, prot, flags, fd, off >> 12);
}
#endif
