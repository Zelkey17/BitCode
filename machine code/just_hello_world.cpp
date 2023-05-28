//
// Created by ash on 28.05.23.
//

#include"../changing_mod.cpp"


int main() {
    auto *arr = new uint8_t[28]{
            0x89, // mov
            0xf2, // rsi -> rdx

            0x48, // something magic

            0x89, // mov
            0xfe, // rdi -> rsi

            0x48, // something magic

            0xc7, // mov (data to reg)
            0xc7, // reg = rdi
            0x00, 0x00, 0x00, 0x00, // data = $1

            0x48, // something magic

            0xc7, // mov (data to reg)
            0xc0, // reg = rax
            0x01, 0x00, 0x00, 0x00, // data = $0

            0x0f, 0x05, // syscall

            0xc3 // ret

    }; //generating array of bytes

    auto write = reinterpret_cast<void (*)(char *, long long)>(arr); // getting function from the array

    chmod(write, "rwe"); // change page permission

    write("Hello, world!\n", 14); // ITS WORKING
}
