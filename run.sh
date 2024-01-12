make
/usr/bin/qemu-system-x86_64 -s -S image.iso -m 256M --d in_asm,int -D qemu_log.txt -M smm=off --no-reboot
