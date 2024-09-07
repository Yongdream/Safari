#include <iostream>
#include <cstring>
#include <fcntl.h> 
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/wait.h>

#define SHM_NAME "/my_shm"
#define SEM_A_NAME "/sem_a"
#define SEM_B_NAME "/sem_b"
#define SHM_SIZE 1024

void processA() {
    // 打开共享内存对象
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    char* shm_ptr = (char*)mmap(0, SHM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // 打开信号量
    sem_t* sem_a = sem_open(SEM_A_NAME, O_CREAT, 0666, 0);
    sem_t* sem_b = sem_open(SEM_B_NAME, O_CREAT, 0666, 0);

    // 写入数据并通知进程B
    strcpy(shm_ptr, "hello");
    sem_post(sem_a);

    // 等待进程B的响应
    sem_wait(sem_b);
    std::cout << "Process A received: " << shm_ptr << std::endl;

    // 关闭共享内存和信号量
    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);
    sem_close(sem_a);
    sem_close(sem_b);
}

void processB() {
    // 打开共享内存对象
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    char* shm_ptr = (char*)mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // 打开信号量
    sem_t* sem_a = sem_open(SEM_A_NAME, O_CREAT, 0666, 0);
    sem_t* sem_b = sem_open(SEM_B_NAME, O_CREAT, 0666, 0);

    // 等待进程A的数据
    sem_wait(sem_a);
    std::cout << "Process B received: " << shm_ptr << std::endl;

    // 写入响应数据并通知进程A
    strcpy(shm_ptr, "world");
    sem_post(sem_b);

    // 关闭共享内存和信号量
    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);
    sem_close(sem_a);
    sem_close(sem_b);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // 子进程B
        processB();
    }
    else {
        // 父进程A
        processA();

        // 等待子进程结束
        wait(NULL);

        // 清理共享内存和信号量
        shm_unlink(SHM_NAME);
        sem_unlink(SEM_A_NAME);
        sem_unlink(SEM_B_NAME);
    }

    return 0;
}
