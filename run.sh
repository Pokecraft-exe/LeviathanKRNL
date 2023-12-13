/usr/bin/qemu-system-x86_64 image.iso \
    -machine accel=tcg \
    -m 2015 \
    -net nic \
    -net user \
    -rtc base=localtime \
    -no-reboot
