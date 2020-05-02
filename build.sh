#!/usr/bin/env bash

IMGSIZE=4096

set -x

#BUILD_DIR="$(realpath $1)"

make -C kernel

if ! [ -f ./dirac.hdd ]; then
    dd if=/dev/zero bs=1M count=0 seek=$IMGSIZE of=dirac.hdd

    parted -s dirac.hdd mklabel msdos
    parted -s dirac.hdd mkpart primary 1 100%

    # create echfs partition
    echfs-utils -m -p0 dirac.hdd quick-format 32768
fi

if ! [ -d qloader2 ]; then
    git clone https://github.com/qloader2/qloader2.git
fi
qloader2/qloader2-install qloader2/qloader2.bin dirac.hdd

install -m 644 kernel/dirac.elf root/

# copy root to image
#./copy-root-to-image.sh "$BUILD_DIR"/system-root dirac.hdd 0
./copy-root-to-image.sh root dirac.hdd 0
