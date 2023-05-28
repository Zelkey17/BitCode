//
// Created by ash on 28.05.23.
//

#include <iostream>

[[noreturn]] void my_exit(int status) {
    asm volatile (R"(
        movq $60, %rax
        syscall
)");
    __builtin_unreachable();


}

int main(){
    std::cout<<"I`m here!!\n";
    my_exit(0);
    std::cerr<<"am I here??\n";

}
