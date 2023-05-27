#include<iostream>
#include<cstring>
#include<sys/mman.h>

template<class T>
void chmod(T ptr, const std::string& mode, int page_cnt = 1, bool debug_mode = false)
{
    auto pointer = reinterpret_cast<uint64_t>(ptr);
    pointer &= -4096ull;
    int mp_mode = 0;

    if (mode.find('e') != -1) mp_mode |= PROT_EXEC;
    if (mode.find('r') != -1) mp_mode |= PROT_READ;
    if (mode.find('w') != -1) mp_mode |= PROT_WRITE;

    int res = mprotect((void *) pointer, 4096 * page_cnt, mp_mode);

    if (res == -1)
    {
        std::cout << "error: " << strerror(errno) << std::endl;
        exit(1);

    } else if (debug_mode)
    {
        void *re_pointer = reinterpret_cast<void *>(pointer);
        std::cout << re_pointer << " \n";
    }

}
