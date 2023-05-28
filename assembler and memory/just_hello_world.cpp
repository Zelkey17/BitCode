//
// Created by ash on 28.05.23.
//
extern "C" long long write(const char *str, unsigned long long cnt);
asm(R"(
write:
        mov %rsi, %rdx
        mov %rdi, %rsi
        movq $0, %rdi
        mov $1, %rax
        syscall
        ret

)");

int main() {
    write("Hello, world!\n", 14);
}