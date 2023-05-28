//
// Created by ash on 27.05.23.
//


#include <cstdint>
#include <iostream>
#include "../changing_mod.cpp"

/*


 MRM format:

                                                    |       m1  m2     rg  rg  rg     rm  rm  rm
	89 f8             	mov    %rdi, %rax   |  f8:  1   1      1   1   1      0   0   0
	89 f7             	mov    %rsi, %rdi   |  f7:  1   1      1   1   0      1   1   1
	89 fa             	mov    %rdi, %rdx   |  fa:  1   1      1   1   1      0   1   0
	89 d1             	mov    %rdx, %rcx   |  d1:  1   1      0   1   0      0   0   1
	89 ce             	mov    %rcx, %rsi   |  ce:  1   1      0   0   1      1   1   0
	01 f0             	add    %rsi, %rax   |  f0:  1   1      1   1   0      0   0   0
	c3                      ret                 |
                                                    |

             000 - rax
             001 - rcx
             010 - rdx
             011 - rbx
             100 - {sib}
             101 - rbp
             110 - rsi
             111 - rdi

             m1m2 - declare an existing of displacement

 */


int main() {
    auto *arr = new uint8_t[5]{0x89, // mov
                               0xf8, // rdi -> rax
                               0x01, // add
                               0xf0, // rsi -> rax
                               0xc3  // ret
    }; //generating array of bytes

    auto sum = reinterpret_cast<uint64_t (*)(uint64_t, uint64_t)>(arr); // getting function from the array

    int a, b;
    std::cin >> a >> b;

    //std::cout<<sum(a,b);  // error, sigfalt `course
                            // we haven't got a permission to execute

    chmod(sum, "rwe"); //so here we are
    std::cout << sum(a, b); // hurray
}
