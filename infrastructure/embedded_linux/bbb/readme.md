
# Linux kernel
Version: 6.1.102

After setting `CROSS_COMPILE` and `ARCH` variables

```bash
wget https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-6.1.102.tar.xz
tar xf linux-6.1.102.tar.xz
```

```bash
make mrproper

make -j4 zImage

make modules

make dtbs
```

# Uboot
Version: v2021.01

After setting `CROSS_COMPILE` and `ARCH` variables

```bash
git clone git://git.denx.de/u-boot.git
cd u-boot
git checkout v2021.01
```

```bash
make am335x_evm_defconfig
make
```
# Booting the BBB

```
U-Boot# fatload mmc 0:1 0x80200000 zImage

U-Boot# fatload mmc 0:1 0x80f00000 am335x-boneblack.dtb

U-Boot# setenv bootargs console=ttyO0

U-Boot# bootz 0x80200000 - 0x80f00000
```
