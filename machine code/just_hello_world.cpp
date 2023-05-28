//
// Created by ash on 28.05.23.
//

#include"../changing_mod.cpp"


int main() {

    auto *arr = new uint8_t[28]{
            0x89,
            0xf2,

            0x48,

            0x89,
            0xfe,

            0x48,

            0xc7,
            0xc7,
            0x00, 0x00, 0x00, 0x00,

            0x48,

            0xc7,
            0xc0,
            0x01, 0x00, 0x00, 0x00,

            0x0f, 0x05,

            0xc3
    }; //generating array of bytes

    auto write = reinterpret_cast<void (*)(char *, long long)>(arr); // getting function from the array

    chmod(write, "rwe");

    write("Hello, world!\n", 14);
}
