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
    // �򿪹����ڴ����
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    char* shm_ptr = (char*)mmap(0, SHM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // ���ź���
    sem_t* sem_a = sem_open(SEM_A_NAME, O_CREAT, 0666, 0);
    sem_t* sem_b = sem_open(SEM_B_NAME, O_CREAT, 0666, 0);

    // д�����ݲ�֪ͨ����B
    strcpy(shm_ptr, "hello");
    sem_post(sem_a);

    // �ȴ�����B����Ӧ
    sem_wait(sem_b);
    std::cout << "Process A received: " << shm_ptr << std::endl;

    // �رչ����ڴ���ź���
    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);
    sem_close(sem_a);
    sem_close(sem_b);
}

void processB() {
    // �򿪹����ڴ����
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    char* shm_ptr = (char*)mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // ���ź���
    sem_t* sem_a = sem_open(SEM_A_NAME, O_CREAT, 0666, 0);
    sem_t* sem_b = sem_open(SEM_B_NAME, O_CREAT, 0666, 0);

    // �ȴ�����A������
    sem_wait(sem_a);
    std::cout << "Process B received: " << shm_ptr << std::endl;

    // д����Ӧ���ݲ�֪ͨ����A
    strcpy(shm_ptr, "world");
    sem_post(sem_b);

    // �رչ����ڴ���ź���
    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);
    sem_close(sem_a);
    sem_close(sem_b);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // �ӽ���B
        processB();
    }
    else {
        // ������A
        processA();

        // �ȴ��ӽ��̽���
        wait(NULL);

        // �������ڴ���ź���
        shm_unlink(SHM_NAME);
        sem_unlink(SEM_A_NAME);
        sem_unlink(SEM_B_NAME);
    }

    return 0;
}
