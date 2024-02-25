namespace std {
    namespace __private_std {
        void memcpy(void* dest, void* src, int len) {
            for (int i = 0; i < len; i++) {
                *((char*)dest + i) = *((char*)src + i);
            }
        }
    }
}