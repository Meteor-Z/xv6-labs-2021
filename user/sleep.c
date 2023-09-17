#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// 调库 然后让他休眠
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(2, "ji le "); // 2是错误输出
        exit(1);
    } else
    {
        sleep(atoi(argv[1]));
    }
    exit(0);
}