#!/bin/bash
if [ "$1" = "vdec" ] || [ "$1" = "osd" ]; then
	FW=$PWD/firmware/general/package/hisilicon-osdrv-hi3536dv100/files/lib
	CC=toolchain.hisilicon-hi3536dv100
elif [ "$1" = "venc-goke" ]; then
	FW=$PWD/firmware/general/package/goke-osdrv-gk7205v200/files/lib
	CC=toolchain.goke-gk7205v200
elif [ "$1" = "venc-hisi" ]; then
	FW=$PWD/firmware/general/package/hisilicon-osdrv-hi3516ev200/files/lib
	CC=toolchain.hisilicon-hi3516ev200
elif [ "$1" = "star-b" ]; then
	FW=$PWD/firmware/general/package/sigmastar-osdrv-infinity6b0/files/lib
	CC=toolchain.sigmastar-infinity6b0
elif [ "$1" = "star-c" ]; then
	FW=$PWD/firmware/general/package/sigmastar-osdrv-infinity6c/files/lib
	CC=toolchain.sigmastar-infinity6c
elif [ "$1" = "star-e" ]; then
	FW=$PWD/firmware/general/package/sigmastar-osdrv-infinity6e/files/lib
	CC=toolchain.sigmastar-infinity6e
fi

DL=https://github.com/openipc/firmware/releases/download/toolchain
GCC=$PWD/toolchain/$CC/bin/arm-linux-gcc

if [ ! -e toolchain/$CC ]; then
	wget -c -q --show-progress $DL/$CC.tgz -P $PWD
	mkdir -p toolchain/$CC
	tar -xf $CC.tgz -C toolchain/$CC --strip-components=1 || exit 1
	rm -f $CC.tgz
fi

if [ ! -e firmware ]; then
	git clone https://github.com/openipc/firmware --depth=1
fi

if [ "$1" = "osd" ]; then
	cd osd
	cmake -Bbuild -DCMAKE_C_COMPILER=$GCC -DCMAKE_BUILD_TYPE=Release
	cmake --build build --parallel 8
elif [ "$1" = "vdec" ]; then
	make -C vdec -B CC=$GCC DRV=$FW
elif [ "$1" = "venc-goke" ] || [ "$1" = "venc-hisi" ]; then
	make -C venc -B CC=$GCC DRV=$FW $1
elif [ "$1" = "star-b" ] || [ "$1" = "star-c" ] || [ "$1" = "star-e" ]; then
	make -C star -B CC=$GCC DRV=$FW $1
else
	echo "Usage: $0 [vdec|venc-goke|venc-hisi|osd|star-b|star-c|star-e]"
	exit 1
fi
