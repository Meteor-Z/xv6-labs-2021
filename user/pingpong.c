#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(void)
{
    // build two pipe
    int father_fd[2];
    int son_fd[2];

    char buf[10]; 
    pipe(father_fd);
    pipe(son_fd);
    int fd = fork();
    
   
    // 每次使用的时候都要关闭另一个管道
    if (fd < 0)
    {
        fprintf(2, "fork() error\n");
        exit(1);
    }
    else if (fd == 0) // 儿子
    {       
        close(father_fd[1]);
        close(son_fd[0]);
 
        read(father_fd[0], buf, 4);
        printf("%d: received %s\n", getpid(), buf);
        write(son_fd[1], "pong", 4);
        close(son_fd[1]);
        exit(0);
    }
    else // 父亲
    {
        close(father_fd[0]);
        close(son_fd[1]);

        write(father_fd[1], "ping", 4);
        close(father_fd[1]);
        read(son_fd[0], buf, 4);
        printf("%d: received %s\n", getpid(), buf);
    }

    exit(0);
}