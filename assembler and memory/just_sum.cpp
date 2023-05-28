//
// Created by ash on 28.05.23.
//

#include <iostream>

extern "C" long long sum1(long long, long long);
extern "C" long long sum2(long long, long long);

asm(R"(
sum1:
    mov %rdi, %rax
    add %rsi, %rax
    ret

sum2:
    lea (%rsi, %rdi), %rax
    ret

)");

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << sum1(a, b) << " " << sum2(a, b) << std::endl;
}